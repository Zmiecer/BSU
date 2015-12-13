package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public abstract class Tree {
    String name;
    int age;
    boolean type;

    public Tree(String name, int age, boolean type) {
        this.name = name;
        this.age = age;
        this.type = type;
    }

    @Override
    public String toString()
    {
        StringBuffer str = new StringBuffer(name + " " + age + " ");
        if (!type)
            str.append("leaf");
        else
            str.append("conifer");
        return str.toString();
    }
}
