package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 22.12.2015.
 */
public class Elk extends Beast {
    String hornsType;

    public Elk(String name, String habitat, int foodPerDay, String hornsType) {
        super(name, habitat, foodPerDay);
        this.hornsType = hornsType;
    }
}
