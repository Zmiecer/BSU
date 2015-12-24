package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 22.12.2015.
 */
public class Magazine extends Paper {
    String type;

    public Magazine(String name, String habitat, int foodPerDay, String type) {
        super(name, habitat, foodPerDay);
        this.type = type;
    }

    public String getType() {
        return type;
    }
}
