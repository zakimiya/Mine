package yoshito.pyunpo;

//import android.support.v7.app.AppCompatActivity;
import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {

    AnimationSurfaceView surfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        surfaceView = new AnimationSurfaceView(this);
        setContentView(surfaceView);
    }

}
