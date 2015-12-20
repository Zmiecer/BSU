package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 06.12.2015.
 */
public abstract class Tree implements Comparable<Tree> {
    String name;
    int age;
    String type;

    public Tree(String name, int age, String type) {
        this.name = name;
        this.age = age;
        this.type = type;
    }

    @Override
    public String toString()
    {
        StringBuffer str = new StringBuffer("Name: " + name + ", age: " + age + ", type: " + type);
        return str.toString();
    }

    @Override
    public int compareTo(Tree otherTree) {
        if(!name.equals(otherTree.name))
            return name.compareTo(otherTree.name);
        else
             return otherTree.age - age;
    }
}
