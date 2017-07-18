package yoshito.pyunpo;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import android.content.res.Resources;
import android.view.MotionEvent;


public class AnimationSurfaceView extends SurfaceView
		implements Runnable, SurfaceHolder.Callback {

	static final long FPS = 40;
	static final long FRAME_TIME = 1000 / FPS;
	SurfaceHolder surfaceHolder;
	Thread thread;
	public Resources res = this.getContext().getResources();
	Canvas canvas;

	int screen_width, screen_height;  //画面の横幅、縦幅

	float x_touch,y_touch;
	int pushflag,startflag;
	int stage,touchflag;
	int next_count;

	final float VIEW_WIDTH = 1080;
	final float VIEW_HEIGHT = 1700;
	float scale,scaleX,scaleY;

	Bitmap block_p = BitmapFactory.decodeResource(res, R.drawable.block);  //ブロック
    Bitmap title1 = BitmapFactory.decodeResource(res, R.drawable.title1);
    Bitmap title2 = BitmapFactory.decodeResource(res, R.drawable.title2);
    Bitmap title3 = BitmapFactory.decodeResource(res, R.drawable.title3);

	//インスタンス
	Player player = new Player();
	Ball ball = new Ball();
	Shot shot = new Shot();
	Block block = new Block();
	Item item = new Item();
	Dragon dragon = new Dragon();
	Bomb bomb = new Bomb();
	Interface face = new Interface();

	public AnimationSurfaceView(Context context) {
		super(context);
		surfaceHolder = getHolder();
		surfaceHolder.addCallback(this);

	}

	@Override
	public void surfaceChanged(SurfaceHolder holder,int format,int width, int height) {
		screen_width = width;
		screen_height = height;

/*		scaleX = screen_width / VIEW_WIDTH;
		scaleY = screen_height /  VIEW_HEIGHT;
		scale = scaleX > scaleY ? scaleY : scaleX;
		if((float) screen_width/screen_height < VIEW_WIDTH / VIEW_HEIGHT) scaleX =  (VIEW_WIDTH / VIEW_HEIGHT) / ((float) screen_width/screen_height);
		else scaleX = 1.0f;

		if((float) screen_width/screen_height > VIEW_WIDTH / VIEW_HEIGHT) scaleY =  (VIEW_WIDTH / VIEW_HEIGHT) / ((float) screen_width/screen_height);
		else scaleY = 1.0f;
		*/

		scaleX = (float)screen_width/block_p.getWidth() * 150f /1080f;
		scaleY = (float)screen_height/block_p.getHeight() * 60f /1701f;

		screen_width = (int) (width / scaleX);
		screen_height = (int) (height / scaleY);
	}

	@Override
	public void surfaceCreated(SurfaceHolder holder) {
		thread = new Thread(this);
		thread.start();
	}

	@Override
	public void run() {

		while(true) {
			//初期化

			face.initialize(res);
			player.initialize(res, screen_width, screen_height);
			ball.initialize(res, screen_width, screen_height);
			shot.initialize(res);
			block.initialize(res, screen_height);
			item.initialize(res, screen_width, screen_height);
			dragon.initialize(res, screen_width);
			bomb.initialize(res, screen_width);

			long loopCount = 0;
			long waitTime = 0;
			long startTime = System.currentTimeMillis();
			stage = 0;
			touchflag = 1;
			next_count = 0;

			//タイトル、説明
			while (thread != null) {

				try {
					Paint paint = new Paint();

					loopCount++;
					canvas = surfaceHolder.lockCanvas();

					canvas.scale(scaleX, scaleY);
                    canvas.scale((float)screen_width/title1.getWidth(), (float)screen_height/title1.getHeight());

					if (stage == 0) canvas.drawBitmap(title1, 0, 0, paint);
					if (stage == 1) canvas.drawBitmap(title2, 0, 0, paint);
					if (stage == 2) canvas.drawBitmap(title3, 0, 0, paint);

                    canvas.scale((float)title1.getWidth()/screen_width, (float)title1.getHeight()/screen_height);

					surfaceHolder.unlockCanvasAndPost(canvas);
					waitTime = (loopCount * FRAME_TIME) - (System.currentTimeMillis() - startTime);

					if (waitTime > 0) {
						Thread.sleep(waitTime);
					}

					next_count++;
					if(next_count >= 20){
						next_count = 20;
						if(pushflag==1){
							stage++;
							next_count = 0;
						}
					}

					if (stage >= 3) break;
				} catch (Exception e) {}
			}

			touchflag = 1;
			startflag = 0;

			//ゲーム本体
			while (thread != null) {

				try {
					loopCount++;
					canvas = surfaceHolder.lockCanvas();

					if (pushflag == 1) {
						if (touchflag == 0) startflag = 1;
					} else touchflag = 0;

					canvas.scale(scaleX, scaleY);

					face.back(canvas, screen_width, screen_height);

					ball.v = shot.hit(ball.bal, ball.v, item.shotplus);
					shot.sh = block.hit_shot(shot.sh, screen_height, item.shotplus);
					ball.v = block.hit_ball(ball.bal, ball.v, screen_height, item.ballplus);
					ball.bal = block.avoid_in(ball.bal,screen_height);

					face.end = block.hit_player(player.player, face.end);
					face.end = item.hit(player.player, face.end, screen_width);
					face.end = dragon.hit(player.player, face.end);
					face.end = bomb.hit_player(player.player, face.end, screen_height, screen_width);
					shot.sh = bomb.hit_shot(shot.sh, screen_width);

					face.end = ball.move(startflag, face.end, screen_width, screen_height);

					ball.draw(canvas, player.player, item.ballplus);
					shot.draw(canvas, player.player, pushflag, x_touch, screen_width, item.shotplus, face.end, startflag);
					block.draw(canvas, startflag);
					player.draw(canvas, pushflag, face.end, x_touch, screen_width, screen_height, startflag);

					dragon.draw(canvas, startflag, screen_width, screen_height);

					bomb.draw(canvas, startflag);
					item.draw(canvas, startflag, screen_width, screen_height);

					face.score(canvas, screen_width, screen_height, block.point);
					face.gameover(canvas, screen_width, screen_height, block.point);

					surfaceHolder.unlockCanvasAndPost(canvas);
					waitTime = (loopCount * FRAME_TIME) - (System.currentTimeMillis() - startTime);

					if (waitTime > 0) {
						Thread.sleep(waitTime);
					}

					if (face.end >= 2) next_count++;
					if(next_count >= 60){
						next_count = 60;
						if(pushflag==1) break;
					}

				} catch (Exception e) {}

			}

		}
	}

	@Override
	public void surfaceDestroyed(SurfaceHolder holder) {
		thread = null;
	}

	public boolean onTouchEvent(MotionEvent me) {
/*
		//タッチした瞬間スタート
		if(me.getAction() == MotionEvent.ACTION_DOWN && pushflag == 0) {
			startflag = 1;
		}
*/
		//タッチされている間
		if(me.getAction() == MotionEvent.ACTION_DOWN) {
			pushflag = 1;
		}
		//タッチされていない間
		if(me.getAction() == MotionEvent.ACTION_UP) {
			pushflag = 0;
		}

		//タッチしている点のx座標とy座標を取得
		x_touch = me.getX() / scaleX;
		y_touch = me.getY() /scaleY;

		return true;
	}

}