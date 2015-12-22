package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 22.12.2015.
 */
public class Beast implements Comparable<Beast> {

    String name;
    String habitat;
    int foodPerDay;

    public Beast(String name, String habitat, int foodPerDay) {
        this.name = name;
        this.habitat = habitat;
        this.foodPerDay = foodPerDay;
    }

    @Override
    public int compareTo(Beast otherBeast) {
        return name.compareTo(otherBeast.name);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Beast beast = (Beast) o;

        if (foodPerDay != beast.foodPerDay) return false;
        if (!name.equals(beast.name)) return false;
        return habitat.equals(beast.habitat);

    }
}
