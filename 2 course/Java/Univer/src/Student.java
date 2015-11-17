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

    Student (String nam, int ag, double mar)
    {
        name = nam;
        age = ag;
        mark = mar;
    }


    @Override
    public int compareTo(Student otherStudent)
    {
        if(name.compareTo(otherStudent.name) > 0)
            return 1;
        else
            if(name.compareTo(otherStudent.name) == 0)
                return 0;
        else
            return -1;
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