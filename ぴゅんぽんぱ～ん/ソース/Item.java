package yoshito.pyunpo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;

import java.util.Random;
/**
 * Created by yoshito on 2016/07/10.
 */
public class Item {

    private Bitmap item1,item2,item3,bar;
    private Random rnd = new Random();
    private Point item = new Point();
    private Paint paint = new Paint();

    int shotplus,ballplus;
    private int rnd_item;

    public void initialize(Resources res,int screen_width,int screen_height){

        item1 = BitmapFactory.decodeResource(res, R.drawable.item_ball);  //アイテム1
        item2 = BitmapFactory.decodeResource(res, R.drawable.item_shot);  //アイテム2
        item3 = BitmapFactory.decodeResource(res, R.drawable.item_death);  //アイテム3

        bar = BitmapFactory.decodeResource(res, R.drawable.bar);

        shotplus = 0;
        ballplus = 0;
        item.x = rnd.nextInt(screen_width - item1.getWidth());
        item.y = -item1.getHeight()*2 - rnd.nextInt(screen_height) * 2;
        rnd_item = rnd.nextInt(3);
    }

    public void draw(Canvas canvas, int startflag,int screen_width,int screen_height){


        switch(rnd_item){
            case 0:
                canvas.drawBitmap(item1, item.x, item.y, paint);
                break;
            case 1:
                canvas.drawBitmap(item2, item.x, item.y, paint);
                break;
            default:
                canvas.drawBitmap(item3, item.x, item.y, paint);
                break;
        }


        if(startflag==1) item.y += item1.getHeight()/10;
        ballplus--;
        if(ballplus <-10) ballplus = -10;
        shotplus--;
        if(shotplus < -10) shotplus = -10;

        if(item.y>screen_height){
            item.x = rnd.nextInt(screen_width - item1.getWidth());
            item.y = -item1.getHeight()*2 - rnd.nextInt(screen_width) * 2;
            rnd_item = rnd.nextInt(4);
        }

    }

    public int hit(Point player,int end,int screen_width){

        //アイテムとバーの当たり判定
        if (((player.x > item.x && player.x < item.x + item1.getWidth()) || (item.x > player.x && item.x < player.x + bar.getWidth())) &&
                ((player.y > item.y && player.y < item.y + item1.getHeight()) || (item.y > player.y && item.y < player.y + bar.getHeight()))) {
            switch(rnd_item){
                case 0:
                    ballplus = 150;
                    break;
                case 1:
                    shotplus = 150;;
                    break;
                default:
                    end = 2;
                    break;
            }
            item.x = rnd.nextInt(screen_width - item1.getWidth());
            item.y =  -item1.getHeight()*2 - rnd.nextInt(screen_width) * 2;
            rnd_item = rnd.nextInt(4);
        }

        return end;
    }
}
