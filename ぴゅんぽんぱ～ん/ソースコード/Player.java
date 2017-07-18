package yoshito.pyunpo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;


public class Player {

    private Bitmap bar,bar_,left,right,attack;
    public int rightflag,leftflag;

    Point player = new Point();
    private Paint paint = new Paint();

    public void initialize(Resources res,int screen_width,int screen_height){

        bar = BitmapFactory.decodeResource(res, R.drawable.bar);
        bar_ = BitmapFactory.decodeResource(res, R.drawable.bar_);
        right = BitmapFactory.decodeResource(res, R.drawable.right);
        left = BitmapFactory.decodeResource(res, R.drawable.left);
        attack = BitmapFactory.decodeResource(res, R.drawable.attack);

        player.x = screen_width/2 - bar.getWidth()/2;
        player.y = screen_height - attack.getHeight()*5/2;
        rightflag = 0;
        leftflag = 0;
    }

    public void draw(Canvas canvas,int pushflag,int end, float x_touch,int screen_width,int screen_height,int startfalg){

        if(end == 0) canvas.drawBitmap(bar, player.x, player.y, paint);
        else       canvas.drawBitmap(bar_, player.x, player.y, paint);
        canvas.drawBitmap(left, left.getWidth()/5, (float) (screen_height-left.getHeight()*1.5), paint);
        canvas.drawBitmap(right,screen_width-right.getWidth()-right.getWidth()/5, (float) (screen_height-right.getHeight()*1.5), paint);
        canvas.drawBitmap(attack, screen_width/2-attack.getWidth()/2, (float) (screen_height-attack.getHeight()*1.5), paint);


        //バー（プレイヤー）が
        //右半分を触っている間右へ、左半分を触っている間左へ移動
 //       if(pushflag==1&&x_touch>screen_width*3/4) player.x+=bar.getWidth()/7;
 //       if(pushflag==1&&x_touch<screen_width/4) player.x-=bar.getWidth()/7;
 //       if(pushflag == 1 && x_touch > player.x + bar.getWidth()*4/3) rightflag = 1;
        if(pushflag==1&&x_touch>screen_width*3/4) rightflag = 1;
        if(rightflag == 1) player.x += bar.getWidth()/7;
//        if(pushflag == 1 && x_touch < player.x - bar.getWidth()/3) leftflag = 1;
        if(pushflag==1&&x_touch<screen_width/4) leftflag = 1;
        if(leftflag == 1) player.x -= bar.getWidth()/7;

        if(pushflag==0){
            leftflag = 0;
            rightflag = 0;
        }

        //バーのx座標の上限、下限
        if(player.x<0) player.x = 0;
        if(player.x>screen_width-bar.getWidth()) player.x = screen_width-bar.getWidth();
    }

}
