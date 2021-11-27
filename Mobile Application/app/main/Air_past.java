package lk.uom.airpollution;

public class Air_past {

    private String temp_p;
    private String hum_p;
    private String pm2_p;
    private String pm10_p;
    private String car_p;
    private String ox_p;


    public Air_past(String temp, String hum, String pm2, String pm10,String car,String ox) {
        this.temp_p = temp_p;
        this.hum_p = hum_p;
        this.pm2_p = pm2_p;
        this.pm10_p = pm10_p;
        this.car_p = car_p;
        this.ox_p=ox_p;
    }

    @Override
    public int hashCode() {
        return temp_p != null ? temp_p.hashCode() : 0;
    }

    public String getTemp() {
        return temp_p;
    }

    public void setTemp(String temp) {
        this.temp_p = temp_p;
    }

    public String getHum() {
        return hum_p;
    }

    public void setHum(String hum) {
        this.hum_p = hum_p;
    }

    public String getPm2() {
        return pm2_p;
    }

    public void setPm2(String pm2) {
        this.pm2_p = pm2_p;
    }

    public String getPm10() {
        return pm10_p;
    }

    public void setPm10(String pm10) {
        this.pm10_p = pm10_p;
    }

    public String getCar() {
        return car_p;
    }

    public void setCar(String car) {
        this.car_p = car_p;
    }

    public String getOx() {
        return ox_p;
    }

    public void setOx(String ox) {
        this.ox_p = ox_p;
    }

}
