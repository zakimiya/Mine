package yoshito.pyunpo;


import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class Interface {

    private Paint paint = new Paint();
    private Paint bgPaint = new Paint();
    private Bitmap attack,back,gameover;

    int end;
    private float scale;


    public void initialize(Resources res){
        attack = BitmapFactory.decodeResource(res, R.drawable.attack);
        gameover = BitmapFactory.decodeResource(res, R.drawable.gameover);
        back = BitmapFactory.decodeResource(res, R.drawable.back);

        end = 0;
        scale = (float) attack.getWidth() / 120f;

        paint.setTextSize(70);
        paint.setColor(Color.RED);
    }


    public void back(Canvas canvas, int screen_width, int screen_height){

        bgPaint.setColor(Color.WHITE);
        canvas.drawRect( 0, 0,screen_width,screen_height, bgPaint);

        canvas.scale((float)screen_width/back.getWidth(), (float)screen_height/back.getHeight());
        canvas.drawBitmap(back, 0, 0, paint);
        canvas.scale((float)back.getWidth()/screen_width, (float)back.getHeight()/screen_height);
    }

    public void score(Canvas canvas, int screen_width, int screen_height,int point){

        canvas.scale(scale ,scale);

        canvas.drawText(""+point , (screen_width/2+attack.getWidth()*3/2) /scale ,(screen_height-attack.getHeight()) / scale, paint);

        canvas.scale(1.0f/scale ,1.0f/scale);
    }

    public void gameover(Canvas canvas,int screen_width,int screen_height,int point) {

        //endflagが立ったら画面を真っ白にする
        if (end >= 2) {
            canvas.drawRect(0, 0, screen_width, screen_height, bgPaint);

            canvas.scale((float)screen_width/back.getWidth(), (float)screen_height/back.getHeight());
            canvas.drawBitmap(gameover, 0, 0, paint);
            canvas.scale((float)back.getWidth()/screen_width, (float)back.getHeight()/screen_height);

            canvas.scale(scale ,scale);
            canvas.drawText("スコア：" + point, (attack.getWidth() * 3 / 2) /scale, (screen_height - attack.getHeight()) /scale, paint);
            canvas.scale(1.0f/scale ,1.0f/scale);
        }
    }
}
