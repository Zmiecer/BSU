package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 22.12.2015.
 */
public class Bear extends Beast {
    String coatColor;
    int honeyAmount;

    public Bear(String name, String habitat, int foodPerDay, String coatColor, int honeyAmount) {
        super(name, habitat, foodPerDay);
        this.coatColor = coatColor;
        this.honeyAmount = honeyAmount;
    }
}
