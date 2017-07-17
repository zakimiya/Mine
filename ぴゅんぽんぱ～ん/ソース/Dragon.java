package yoshito.pyunpo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;

import java.util.Random;

public class Dragon {

    private Bitmap dragon,fire,bar;
    private Random rnd = new Random();
    private Point d = new Point();
    private Point f = new Point();
    private Paint paint = new Paint();

    private int v;
    private int turn;
    private boolean hit;

    public void initialize(Resources res,int screen_width){

        dragon = BitmapFactory.decodeResource(res, R.drawable.dragon);
        fire = BitmapFactory.decodeResource(res, R.drawable.fire);

        bar = BitmapFactory.decodeResource(res, R.drawable.bar);

        d.x = -dragon.getWidth() * 3 - rnd.nextInt(dragon.getWidth() * 4);
        d.y = dragon.getHeight()/2;

        v = dragon.getWidth() / 15;
        turn = screen_width + dragon.getWidth() * 2 + rnd.nextInt(dragon.getWidth() * 4);

        hit = false;

        f.x = d.x + dragon.getWidth()/2 + fire.getWidth()/2;
        f.y = d.y + dragon.getHeight()/2 + fire.getHeight()/2;
    }


    public void draw(Canvas canvas, int startflag,int screen_width,int screen_height){

        canvas.drawBitmap(fire, f.x, f.y, paint);
        canvas.drawBitmap(dragon, d.x, d.y, paint);

        if(startflag==1) {
            d.x += v;

            f.y += fire.getHeight() / 5;
        }

        if(v>0 && d.x > turn){
            v = -v;
            turn = -dragon.getWidth() * 3 - rnd.nextInt(dragon.getWidth() * 4);
        }
        if(v<0 && d.x < turn){
            v = -v;
            turn = screen_width + dragon.getWidth() * 2 + rnd.nextInt(dragon.getWidth() * 4);
        }

        if(f.y > screen_height) {
            f.x = d.x + dragon.getWidth() / 2 + fire.getWidth() / 2;
            f.y = d.y + dragon.getHeight() / 2 + fire.getHeight() / 2;
            hit = false;
        }
    }


    public int hit(Point player,int end){

        if (((player.x > f.x && player.x < f.x + fire.getWidth()) || (f.x > player.x && f.x < player.x + bar.getWidth())) &&
                ((player.y > f.y && player.y < f.y + fire.getHeight()) || (f.y > player.y && f.y < player.y + bar.getHeight()))
                && hit==false) {
            end++;
            hit = true;
        }

        return end;
    }
}
