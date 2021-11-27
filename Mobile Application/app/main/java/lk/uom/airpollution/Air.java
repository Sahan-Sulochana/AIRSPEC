package lk.uom.airpollution;

public class Air {

    private int temp;
    private int hum;
    private int pm2;
    private int pm10;
    private int car;
    private int ox;


    public Air(int temp, int hum, int pm2, int pm10,int car,int ox) {
        this.temp = temp;
        this.hum = hum;
        this.pm2 = pm2;
        this.pm10 = pm10;
        this.car = car;
        this.ox=ox;
    }

    public int getTemp() {
        return temp;
    }

    public void setTemp(int temp) {
        this.temp = temp;
    }

    public int getHum() {
        return hum;
    }

    public void setHum(int hum) {
        this.hum = hum;
    }

    public int getPm2() {
        return pm2;
    }

    public void setPm2(int pm2) {
        this.pm2 = pm2;
    }

    public int getPm10() {
        return pm10;
    }

    public void setPm10(int pm10) {
        this.pm10 = pm10;
    }

    public int getCar() {
        return car;
    }

    public void setCar(int car) { this.car = car;
    }

    public int getOx() {
        return ox;
    }

    public void setOx(int ox) {
        this.ox = ox;
    }

}
