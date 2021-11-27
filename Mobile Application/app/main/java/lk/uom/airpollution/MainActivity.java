package lk.uom.airpollution;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.content.Intent;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import static java.lang.Thread.sleep;
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        startActivity(new Intent(MainActivity.this,SecondActivity.class));
        try {
            sleep(1500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // close splash activity
        finish();
    }
}