package lk.uom.airpollution;

public class Air_future {

    private String temp_f;
    private String hum_f;
    private String pm2_f;
    private String pm10_f;
    private String car_f;
    private String ox_f;


    public Air_future(String temp_f, String hum_f, String pm2_f, String pm10_f,String car_f,String ox_f) {
        this.temp_f = temp_f;
        this.hum_f = hum_f;
        this.pm2_f = pm2_f;
        this.pm10_f = pm10_f;
        this.car_f = car_f;
        this.ox_f=ox_f;
    }

    @Override
    public int hashCode() {
        return temp_f != null ? temp_f.hashCode() : 0;
    }

    public String getTemp() {
        return temp_f;
    }

    public void setTemp(String temp) {
        this.temp_f = temp;
    }

    public String getHum() {
        return hum_f;
    }

    public void setHum(String hum) {
        this.hum_f = hum_f;
    }

    public String getPm2() {
        return pm2_f;
    }

    public void setPm2(String pm2) {
        this.pm2_f = pm2_f;
    }

    public String getPm10() {
        return pm10_f;
    }

    public void setPm10(String pm10) {
        this.pm10_f = pm10_f;
    }

    public String getCar() {
        return car_f;
    }

    public void setCar(String car) {
        this.car_f = car_f;
    }

    public String getOx() {
        return ox_f;
    }

    public void setOx(String ox) {
        this.ox_f = ox_f;
    }

}
