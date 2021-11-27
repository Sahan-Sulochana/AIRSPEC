package lk.uom.airpollution;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
    }

    public void Home_btn_tapped(View view) {

        Intent intent = new Intent (SecondActivity.this, ThirdActivity.class);
        startActivity(intent);

    }

    public void Location_btn_Tapped(View view) {

        Intent intent = new Intent (SecondActivity.this, MapsActivity.class);
        startActivity(intent);
    }

    public void coordinates_btn_Tapped(View view) {
        Intent intent = new Intent (SecondActivity.this, Coordinates.class);
        startActivity(intent);
    }
}