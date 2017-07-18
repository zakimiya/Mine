package yoshito.pyunpo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;

import java.util.Random;


public class Block {

    private static final int XBLOCK = 5;  //ブロックの横の数
    private static final int YBLOCK = 100;  //ブロックの縦の数

    private Bitmap block,block1,block2,block3,bar,ball,shot;

    private float[][] x_block = new float[XBLOCK][YBLOCK];  //ブロックのx座標（5×100）
    private float[][] y_block = new float[XBLOCK][YBLOCK];  //ブロックのy座標（5×100）

    private Paint paint = new Paint();

    private int[][] vanishflag = new int[XBLOCK][YBLOCK];  //ブロックが消えているかどうか（0=ある,1=ない）
    private int[][] color = new int[XBLOCK][YBLOCK];  //ブロックの色（5×100）
    private int[][] color_rand = new int[XBLOCK][YBLOCK];  //ブロックの色（5×100）
    private float v_block;  //ブロックした下に移動する速

    int point;

    Random rnd = new Random();

    int i,j;

    public void initialize(Resources res,int screen_height){


        block = BitmapFactory.decodeResource(res, R.drawable.block);  //ブロック
        block1 = BitmapFactory.decodeResource(res, R.drawable.block1);  //ブロック1
        block2 = BitmapFactory.decodeResource(res, R.drawable.block2);  //ブロック2
        block3 = BitmapFactory.decodeResource(res, R.drawable.block3);  //ブロック3

        bar = BitmapFactory.decodeResource(res, R.drawable.bar);  //バー（プレイヤー）
        ball = BitmapFactory.decodeResource(res, R.drawable.ball);  //ボール
        shot = BitmapFactory.decodeResource(res, R.drawable.shot);  //ショット

        for(i=0;i<XBLOCK;i++){
            for(j=0;j<YBLOCK;j++){
                x_block[i][j] = (float) (block.getWidth()*i*1.4 +block.getWidth()*0.2);
                y_block[i][j] = (float) (-block.getHeight()*j*2 +screen_height/8);
                color_rand[i][j] = rnd.nextInt(20);  //乱数を生成

                switch(color_rand[i][j]){
                    case 0:
                        color[i][j] = 1;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        color[i][j] = 2;
                        break;
                    case 4:
                        color[i][j] = 3;
                        break;
                    default:
                        color[i][j] = 0;
                        break;

                }
                vanishflag[i][j] = 0;
            }
        }

        v_block = (float) block.getHeight()/40;
        point = 0;
    }

    public void draw(Canvas canvas, int startflag){

        for(i=0;i<XBLOCK;i++){
            for(j=0;j<YBLOCK;j++){
                if(vanishflag[i][j]==0){
                    switch(color[i][j]){
                        case 1:
                            canvas.drawBitmap(block1, x_block[i][j], y_block[i][j], paint);
                            break;
                        case 2:
                            canvas.drawBitmap(block2, x_block[i][j], y_block[i][j], paint);
                            break;
                        case 3:
                            canvas.drawBitmap(block3, x_block[i][j], y_block[i][j], paint);
                            break;
                        default:
                            canvas.drawBitmap(block, x_block[i][j], y_block[i][j], paint);
                            break;

                    }
                }

                if (startflag == 1) {
                    y_block[i][j] += v_block;  //ブロックは自動的に下に移動
                    v_block += block.getHeight() / 1000;
                }
            }
        }
    }


    public Point hit_shot(Point sh,int screen_height,int shotplus){

        for(i=0;i<XBLOCK;i++) {
            for (j = 0; j < YBLOCK; j++) {

                if (y_block[i][j] > -block1.getHeight() && y_block[i][j] < screen_height) {
                    if (((sh.x > x_block[i][j] && sh.x < x_block[i][j] + block.getWidth()) || (x_block[i][j] > sh.x && x_block[i][j] < sh.x + shot.getWidth())) &&
                        ((sh.y > y_block[i][j] && sh.y < y_block[i][j] + block.getHeight()) || (y_block[i][j] > sh.y && y_block[i][j] < sh.y + shot.getHeight()))) {
                        if (vanishflag[i][j] == 0) {
                            if (shotplus <= 0) {
                                sh.y = -shot.getHeight()*2;  //弾が見えなくなる
                                if (color[i][j] == 0 || color[i][j] == 2) {
                                    point += 1000 - rnd.nextInt(3);
                                    vanishflag[i][j] = 1;  //ブロック、ブロック2の場合、ブロックが消える
                                }
                            }
                            else {
                                point += 1000 - rnd.nextInt(3);
                                vanishflag[i][j] = 1;  //ブロックが消える
                            }
                        }
                    }
                }
            }
        }

        return sh;
    }


    public Point hit_ball(Point bal,Point v,int screen_height,int ballplus){

        for(i=0;i<XBLOCK;i++) {
            for (j = 0; j < YBLOCK; j++) {

                if (y_block[i][j] > -block1.getHeight() && y_block[i][j] < screen_height) {
                    //ブロックとボールの当たり判定
                    if (((bal.x > x_block[i][j] && bal.x < x_block[i][j] + block.getWidth()) || (x_block[i][j] > bal.x && x_block[i][j] < bal.x + ball.getWidth())) &&
                        ((bal.y > y_block[i][j] && bal.y < y_block[i][j] + block.getHeight()) || (y_block[i][j] > bal.y && y_block[i][j] < bal.y + ball.getHeight()))) {
                        if (vanishflag[i][j] == 0) {
                            if (ballplus <= 0) {
                                if(((bal.x >= x_block[i][j] - ball.getWidth() && bal.x <= x_block[i][j] - ball.getWidth() + v.x) ||
                                    (bal.x <= x_block[i][j] + bar.getWidth()  && bal.x >= x_block[i][j] + bar.getWidth()  - v.x))&&
                                    ((bal.y >= y_block[i][j] - ball.getHeight() && bal.y <= y_block[i][j] - ball.getHeight() + v.y) ||
                                     (bal.y <= y_block[i][j] + bar.getHeight()  && bal.y >= y_block[i][j] + bar.getHeight()  - v.y))){
                                    v.x = -v.y;
                                    v.y = -v.y;
                                }
                                else if((bal.x >= x_block[i][j] - ball.getWidth() && bal.x <= x_block[i][j] - ball.getWidth() + v.x) ||
                                         (bal.x <= x_block[i][j] + bar.getWidth()  && bal.x >= x_block[i][j] + bar.getWidth()  - v.x))
                                    v.x = -v.x;
                                else
                                    v.y = -v.y;
                                /*
                                else if((bal.y >= y_block[i][j] - ball.getHeight() && bal.y < y_block[i][j] - ball.getHeight() + v.y) ||
                                         (bal.y <= y_block[i][j] + bar.getHeight()  && bal.y > y_block[i][j] + bar.getHeight() - v.y))
                                    v.y = -v.y;
                                    */

                                if (color[i][j] == 0 || color[i][j] == 1) {
                                    point += 1000 - rnd.nextInt(3);
                                    vanishflag[i][j] = 1;  //ブロック、ブロック1の場合、ブロックが消える
                                }
                            }
                            else {
                                point += 1000 - rnd.nextInt(3);
                                vanishflag[i][j] = 1;  //ブロックが消える
                            }
                        }
                    }
                }
            }
        }
        return v;
    }

    public Point avoid_in(Point bal,int screen_height) {

        for(i=0;i<XBLOCK;i++) {
                for (j = 0; j < YBLOCK; j++) {
                    if (vanishflag[i][j] == 0 && y_block[i][j] > -block1.getHeight() && y_block[i][j] < screen_height) {
                        if (bal.x > x_block[i][j] - ball.getWidth() && bal.x < x_block[i][j] + block.getWidth() && bal.y > y_block[i][j] - ball.getHeight() && bal.y < y_block[i][j])
                            bal.y = y_block[i][j] - ball.getHeight();
                        if (bal.x > x_block[i][j] - ball.getWidth() && bal.x < x_block[i][j] + block.getWidth() && bal.y > y_block[i][j] && bal.y < y_block[i][j] + block.getHeight())
                            bal.y = y_block[i][j] + block.getHeight();
                        if (bal.y > y_block[i][j] - ball.getHeight() && bal.y < y_block[i][j] + block.getHeight() && bal.x > x_block[i][j] - ball.getWidth() && bal.x < x_block[i][j])
                            bal.x = x_block[i][j] - ball.getWidth();
                        if (bal.y > y_block[i][j] - ball.getHeight() && bal.y < y_block[i][j] + block.getHeight() && bal.x > x_block[i][j] && bal.x < x_block[i][j] + block.getWidth())
                            bal.x = x_block[i][j] + block.getWidth();
                    }
            }
        }
        return bal;
    }

    public int hit_player(Point player,int endflag){

        for(i=0;i<XBLOCK;i++) {
            for (j = 0; j < YBLOCK; j++) {

                if (((player.x > x_block[i][j] && player.x < x_block[i][j] + block.getWidth()) || (x_block[i][j] > player.x && x_block[i][j] < player.x + bar.getWidth())) &&
                        ((player.y > y_block[i][j] && player.y < y_block[i][j] + block.getHeight()) || (y_block[i][j] > player.y && y_block[i][j] < player.y + bar.getHeight()))) {
                    if(vanishflag[i][j]==0) endflag = 2;  //ゲームオーバー
                }
            }
        }

        return endflag;
    }


}
