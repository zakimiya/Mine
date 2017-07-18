package yoshito.pyunpo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;

import java.util.Random;

public class Bomb {

    private Bitmap bomb,bar,shot;
    private Random rnd = new Random();
    private Point bom = new Point();
    private Paint paint = new Paint();

    private boolean hit;


    public void initialize(Resources res,int screen_width){

        bomb = BitmapFactory.decodeResource(res, R.drawable.bomb);

        bar = BitmapFactory.decodeResource(res, R.drawable.bar);
        shot = BitmapFactory.decodeResource(res, R.drawable.shot);

        bom.x = rnd.nextInt(screen_width - bomb.getWidth());
        bom.y = -bomb.getHeight() * 2 - rnd.nextInt(bomb.getHeight() * 10);

        hit = false;
    }


    public void draw(Canvas canvas,int startflag){

        canvas.drawBitmap(bomb, bom.x, bom.y, paint);

        if(startflag==1) bom.y += bomb.getHeight()/20;
    }


    public int hit_player(Point player,int end,int screen_height,int screen_width){

        if (((player.x > bom.x && player.x < bom.x + bomb.getWidth()) || (bom.x > player.x && bom.x < player.x + bar.getWidth())) &&
                ((player.y > bom.y && player.y < bom.y + bomb.getHeight()) || (bom.y > player.y && bom.y < player.y + bar.getHeight()))) {
            if(hit==false) end++;
            hit = true;
        }

        if(bom.y>screen_height-bomb.getHeight()){
            if(hit==false) end++;

            bom.x = rnd.nextInt(screen_width - bomb.getWidth());
            bom.y = -bomb.getHeight() * 2 - rnd.nextInt(bomb.getHeight() * 10);

            hit = false;
        }

        return end;
    }


    public Point hit_shot(Point sh,int screen_width){

        if (((sh.x > bom.x && sh.x < bom.x + bomb.getWidth()) || ( bom.x > sh.x && bom.x < sh.x + shot.getWidth())) &&
            ((sh.y > bom.y && sh.y < bom.y + bomb.getHeight()) || ( bom.y > sh.y && bom.y < sh.y + shot.getHeight()))) {

            bom.x = rnd.nextInt(screen_width - bomb.getWidth());
            bom.y = -bomb.getHeight() * 2 - rnd.nextInt(bomb.getHeight() * 10);
            sh.y = -shot.getHeight() * 2;
        }

        return sh;
    }

}
