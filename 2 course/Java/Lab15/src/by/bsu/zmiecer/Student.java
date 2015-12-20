package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 17.11.2015.
 */

public class Student implements Comparable<Student>
{

    int number;
    String surname;
    int course;
    int group;

    public Student(int number, String surname, int course, int group) {
        this.number = number;
        this.surname = surname;
        this.course = course;
        this.group = group;
    }

    public int getNumber() {
        return number;
    }

    public String getSurname() {
        return surname;
    }

    public int getCourse() {
        return course;
    }

    public int getGroup() {
        return group;
    }

    @Override
    public int compareTo(Student otherStudent)
    {
        return number - otherStudent.number;
    }

    @Override
    public String toString()
    {
        return "Number:" + number + ", surname: " + surname + ", course: " + course + ", group: " + group;
    }
}