package lk.uom.airpollution;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class ThirdActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);
    }

    public void currentButton_Tapped(View view) {
        Intent intent = new Intent (ThirdActivity.this, Home.class);
        startActivity(intent);
    }

    public void lastButton_Tapped(View view) {
        Intent intent = new Intent (ThirdActivity.this, Home_past.class);
        startActivity(intent);
    }

    public void futureButton_Tapped(View view) {
        Intent intent = new Intent (ThirdActivity.this, Home_future.class);
        startActivity(intent);
    }
}