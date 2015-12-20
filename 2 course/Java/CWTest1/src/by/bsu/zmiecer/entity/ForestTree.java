package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public class ForestTree extends Tree {
    int wood;

    public ForestTree(String name, int age, boolean type, int wood) {
        super(name, age, type);
        this.wood = wood;
    }

    @Override
    public String toString() {
        return super.toString() + " " + wood;
    }
}
