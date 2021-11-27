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

public class Home_past extends AppCompatActivity {

    private TextView temp_p_txt,hum_p_txt,pm2_p_txt,pm10_p_txt,car_p_txt,ox_p_txt;
    private RequestQueue myqueue_p;
    private final String  url_p = "http://192.168.1.3/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home_past);

        myqueue_p= Volley.newRequestQueue(Home_past.this);

        temp_p_txt=findViewById(R.id.temp_p_txt);
        hum_p_txt=findViewById(R.id.hum_p_txt);
        pm2_p_txt=findViewById(R.id.pm2_p_txt);
        pm10_p_txt=findViewById(R.id.pm10_p_txt);
        car_p_txt=findViewById(R.id.car_p_txt);
        ox_p_txt=findViewById(R.id.ox_p_txt);
        LoadData();
    }
    private void LoadData()
    {
        JsonObjectRequest jsonObjectRequest = new JsonObjectRequest
                (Request.Method.GET, url_p, null, new Response.Listener<JSONObject>() {
                    @Override
                    public void onResponse(JSONObject response)  {
                        try {

                            temp_p_txt.setText(response.getString("PM1"));
                            hum_p_txt.setText(response.getString("PM25"));
                            pm2_p_txt.setText(response.getString("PM10"));
                            pm10_p_txt.setText(response.getString("Temperature"));
                            car_p_txt.setText(response.getString("Humidity"));
                            ox_p_txt.setText(response.getString("Pressure"));


                        } catch(JSONException e){
                            e.printStackTrace();
                        }

                    }
                }, new Response.ErrorListener() {
                    @Override
                    public void onErrorResponse(VolleyError error) {
                        Toast.makeText(Home_past.this,"Something went wrong",Toast.LENGTH_LONG).show();
                    }
                });

        myqueue_p.add(jsonObjectRequest);
    }
}