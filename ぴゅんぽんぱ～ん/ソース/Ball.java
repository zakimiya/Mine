package yoshito.pyunpo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;


public class Ball {

    private Bitmap ball,ball_,bar;

    Point bal = new Point();
    Point v = new Point();

    private Paint paint = new Paint();

    //初期化
    public void initialize(Resources res,int screen_width,int screen_height){

        ball = BitmapFactory.decodeResource(res, R.drawable.ball);  //ボール
        ball_ = BitmapFactory.decodeResource(res, R.drawable.ball_);  //ボール

        bar = BitmapFactory.decodeResource(res, R.drawable.bar);

        bal.x= screen_width/2-ball.getWidth()/2;
        bal.y =screen_height*2/3;
        v.x = ball.getWidth()/50*9;
        v.y = ball.getHeight()/50*10;
    }

    //移動、描画
    public void draw(Canvas canvas,Point player, int ballplus){

        if(ballplus<=0) canvas.drawBitmap(ball, bal.x, bal.y, paint);   //ボールの描画
        else canvas.drawBitmap(ball_, bal.x, bal.y, paint); //ボール＋なら赤色

        //バーとボールの当たり判定
        if (((player.x > bal.x && player.x < bal.x + ball.getWidth()) || (bal.x > player.x && bal.x < player.x + bar.getWidth())) &&
                ((player.y > bal.y && player.y < bal.y + ball.getHeight()) || (bal.y > player.y && bal.y < player.y + bar.getHeight()))) {
            if(bal.y > player.y - ball.getHeight() + v.y && bal.y < player.y + bar.getHeight() - v.y) v.x = -v.x;
            else v.y = -v.y;
        }

        //めり込み防止
        if (bal.x > player.x - ball.getWidth() && bal.x < player.x + bar.getWidth() && bal.y > player.y - ball.getHeight() && bal.y < player.y) bal.y = player.y - ball.getHeight();
        if (bal.x > player.x - ball.getWidth() && bal.x < player.x + bar.getWidth() && bal.y > player.y  && bal.y < player.y + bar.getHeight()) bal.y = player.y + bar.getHeight();
        if (bal.y > player.y - ball.getHeight() && bal.y < player.y + bar.getHeight() && bal.x > player.x - ball.getWidth() && bal.x < player.x) bal.x = player.x - ball.getWidth();
        if (bal.y > player.y - ball.getHeight() && bal.y < player.y + bar.getHeight() && bal.x > player.x  && bal.x < player.x + bar.getWidth()) bal.x = player.x + bar.getWidth();

        //速さの設定（ボール＋なら速い）
        if(ballplus>0){
            if(v.x>0) v.x = (float) ball.getWidth()/20*7;
            else v.x = - (float) ball.getWidth()/20*7;
            if(v.y>0) v.y = (float) ball.getHeight()/20*8;
            else v.y = - (float) ball.getHeight()/20*8;
        }
        else{
            if(v.x>0) v.x = (float) ball.getWidth()/50*7;
            else v.x = - (float) ball.getWidth()/50*7;
            if(v.y>0) v.y = (float) ball.getHeight()/50*8;
            else v.y = - (float) ball.getHeight()/50*8;
        }
    }

    //移動
    public int move(int startflag,int end,int screen_width,int screen_height){

        //スタートしたら自動的にボールが移動
        if(startflag==1){
            bal.x += v.x;
            bal.y += v.y;
        }

        //ボールが壁に反射
        if(bal.x>screen_width-ball.getWidth()){
            bal.x = screen_width-ball.getWidth();
            v.x = -v.x;
        }
        if(bal.x<0){
            bal.x = 0;
            v.x = -v.x;
        }
        if(bal.y<0){
            bal.y = 0;
            v.y = -v.y;
        }

        if(bal.y>screen_height-ball.getHeight()){
            end = 2;
        }

        if(end >= 2) bal.x = -ball.getWidth() * 2;

        return end;
    }
}
