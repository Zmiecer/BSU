package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 17.11.2015.
 */

public class Student implements Comparable<Student>
{

    String name;
    int age;
    double mark;

    Student()
    {
        name = null;
        age = 0;
        mark = 0;
    }

    Student(String nam, int ag, double mar)
    {
        name = nam;
        age = ag;
        mark = mar;
    }


    @Override
    public int compareTo(Student otherStudent)
    {

        return name.compareTo(otherStudent.name);
    }

    @Override
    public String toString()
    {
        return "Surname: " + name + ", age: " + age + ", mark: " + mark;
    }

    public void print()
    {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Mark: " + mark);
    }
}