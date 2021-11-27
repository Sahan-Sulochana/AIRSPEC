package lk.uom.airpollution;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
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

public class Home_future extends AppCompatActivity {

    private TextView temp_f_txt,hum_f_txt,pm2_f_txt,pm10_f_txt,car_f_txt,ox_f_txt;
    private RequestQueue myqueue_f;
    private final String  url_f= "http://192.168.1.3/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home_future);


        myqueue_f= Volley.newRequestQueue(Home_future.this);

        temp_f_txt=findViewById(R.id.temp_f_txt);
        hum_f_txt=findViewById(R.id.hum_f_txt);
        pm2_f_txt=findViewById(R.id.pm2_f_txt);
        pm10_f_txt=findViewById(R.id.pm10_f_txt);
        car_f_txt=findViewById(R.id.car_f_txt);
        ox_f_txt=findViewById(R.id.ox_f_txt);
        LoadData();
    }
    private void LoadData()
    {
        JsonObjectRequest jsonObjectRequest = new JsonObjectRequest
                (Request.Method.GET, url_f, null, new Response.Listener<JSONObject>() {
                    @Override
                    public void onResponse(JSONObject response)  {
                        try {


                            temp_f_txt.setText(response.getString("PM1"));
                            hum_f_txt.setText(response.getString("PM25"));
                            pm2_f_txt.setText(response.getString("PM10"));
                            pm10_f_txt.setText(response.getString("Temperature"));
                            car_f_txt.setText(response.getString("Humidity"));
                            ox_f_txt.setText(response.getString("Pressure"));


                        } catch(JSONException e){
                            e.printStackTrace();
                        }

                    }
                }, new Response.ErrorListener() {
                    @Override
                    public void onErrorResponse(VolleyError error) {
                        Toast.makeText(Home_future.this,"Something went wrong",Toast.LENGTH_LONG).show();
                    }
                });

        myqueue_f.add(jsonObjectRequest);
    }
}