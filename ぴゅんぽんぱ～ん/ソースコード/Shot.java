package yoshito.pyunpo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;


public class Shot {

    private Bitmap shot,shot_,bar,ball;

    Point sh = new Point();
    private Paint paint = new Paint();

    private int shotflag;

    public void initialize(Resources res){
        shot = BitmapFactory.decodeResource(res, R.drawable.shot);  //ショット
        shot_ = BitmapFactory.decodeResource(res, R.drawable.shot_);  //ショット

        bar = BitmapFactory.decodeResource(res, R.drawable.bar);  //バー（プレイヤー）
        ball = BitmapFactory.decodeResource(res, R.drawable.ball);  //ボール

        sh.x = -shot.getWidth() * 2;
        sh.y = -shot.getHeight() * 2;

        shotflag = 0;
    }

    public void draw(Canvas canvas,Point player, int pushflag,float x_touch,int screen_width,int shotplus,int end,int startflag){


        if(shotplus<=0) canvas.drawBitmap(shot, sh.x, sh.y, paint);
        else  canvas.drawBitmap(shot_, sh.x, sh.y, paint);


        //弾が自動的に上へ動く
        sh.y -= shot.getHeight()*4/5;

        if(end >= 2) sh.x = -shot.getWidth() * 2;

        //画面の真ん中をタッチすると弾が発射
        //押しっぱなしは無効
        //弾が見えなくなるまで次の弾は撃てない
        if(sh.y<0){  //弾が見えなければ
            if(startflag==1 && pushflag == 1 && x_touch>screen_width/4 && x_touch<screen_width*3/4 ){  //画面の真ん中をタッチしたら
       //     if( pushflag == 1 && x_touch > player.x - bar.getWidth()/3 &&  x_touch < player.x + bar.getWidth()*4/3 && rightflag == 0 && leftflag == 0){  //バーの近くをタッチしたら
                if(shotflag==0){
                    //バーのど真ん中に弾を移動
                    sh.x = player.x + bar.getWidth()/2 - ball.getWidth()/2;
                    sh.y = player.y - ball.getHeight()/2;
                    shotflag = 1;  //押しっぱなしは無効
                }
            }
            else shotflag = 0;
        }
    }


    public Point hit(Point bal,Point v,int shotplus){

        //ボールと弾の当たり判定
        if (((sh.x > bal.x && sh.x < bal.x + ball.getWidth()) || ( bal.x > sh.x && bal.x < sh.x + shot.getWidth())) &&
                ((sh.y > bal.y && sh.y < bal.y + ball.getHeight()) ||  ( bal.y > sh.y && bal.y < sh.y + shot.getHeight()))) {
            if(shotplus<=0){
                if(v.y>0) v.y = -v.y;  //ボールが落ちている時押し上げる
                else v.x = -v.x;  //ボールが上がっている時横への動きを逆にする
                sh.y = -shot.getHeight() * 2;  //弾を見えなくする
            }
        }

        return v;
    }

}
