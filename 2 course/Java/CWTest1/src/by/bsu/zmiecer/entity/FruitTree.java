package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public class FruitTree extends Tree {
    int harvest;
    int storageTime;

    public FruitTree(String name, int age, boolean type, int harvest, int storageTime) {
        super(name, age, type);
        this.harvest = harvest;
        this.storageTime = storageTime;
    }

    @Override
    public String toString() {
        return super.toString() + " " + harvest + " " + storageTime;
    }
}
