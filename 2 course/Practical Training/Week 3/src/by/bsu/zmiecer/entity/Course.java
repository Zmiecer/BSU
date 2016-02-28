package by.bsu.zmiecer.entity;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by Zmiecer on 28.02.16.
 */
public class Course {
    String name;
    Set<Student> students;

    public Course(String name, Set<Student> students) {
        this.name = name;
        this.students = students;
    }

    public Set<Postgraduate> getPostgraduates (String nameOfSupervisor)
    {
        Set<Postgraduate> postgraduates = new HashSet();
        for (Student student: students)
        {
            if (student.getClass().getName().equals("by.bsu.zmiecer.entity.Postgraduate"))
            {
                Postgraduate postgraduate = (Postgraduate) student;
                if (postgraduate.getSupervisor().getName().equals(nameOfSupervisor))
                    postgraduates.add(postgraduate);
            }
        }
        return postgraduates;
    }
}
