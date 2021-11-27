package lk.uom.airpollution;

import androidx.appcompat.app.AppCompatActivity;

import android.location.LocationManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.JsonRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;
import lk.uom.airpollution.Coordinates;

public class Home extends AppCompatActivity {

    private TextView temp_txt,hum_txt,pm2_txt,pm10_txt,car_txt,ox_txt;
    private RequestQueue myqueue;

    private final String  url = "http://192.168.1.3/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);


        myqueue= Volley.newRequestQueue(Home.this);

        temp_txt=findViewById(R.id.temp_txt);
        hum_txt=findViewById(R.id.hum_txt);
        pm2_txt=findViewById(R.id.pm2_txt);
        pm10_txt=findViewById(R.id.pm10_txt);
        car_txt=findViewById(R.id.car_txt);
        ox_txt=findViewById(R.id.ox_txt);
        LoadData();
    }
    private void LoadData()
    {
        JsonObjectRequest jsonObjectRequest = new JsonObjectRequest
                (Request.Method.GET, url, null, new Response.Listener<JSONObject>() {
                    @Override
                    public void onResponse(JSONObject response)  {
                        try {


                            temp_txt.setText(response.getString("PM1"));
                            hum_txt.setText(response.getString("PM25"));
                            pm2_txt.setText(response.getString("PM10"));
                            pm10_txt.setText(response.getString("Temperature"));
                            car_txt.setText(response.getString("Humidity"));
                            ox_txt.setText(response.getString("Pressure"));

                        } catch(JSONException e){
                            e.printStackTrace();
                    }

                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Home.this,"Something went wrong",Toast.LENGTH_LONG).show();

            }
        });

        myqueue.add(jsonObjectRequest);
    }


}

