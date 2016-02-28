package by.bsu.zmiecer.runner;

import by.bsu.zmiecer.entity.*;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by Zmiecer on 28.02.16.
 */
public class ProgrammingTest {
    public static void main(String[] args) {
        Academic dubkov = new Academic("Dubkov");
        Academic sakovich = new Academic("Sakovich");

        Set<Student> students = new HashSet();
        students.add(new Undergraduate("Bylinovich", "zmiecer", "zmiecer@tut.by", sakovich));
        students.add(new Undergraduate("Dorohovich", "dorochle", "dorochle@gmail.com", sakovich));
        students.add(new Postgraduate("Nesterovich", "nesterka", "nesterka@tut.by", sakovich));
        students.add(new Postgraduate("Michalchenko", "michko", "andey.mich@mail.ru", dubkov));
        students.add(new Postgraduate("Fedosov", "fedych", "fedych@tut.by", sakovich));

        Course course = new Course("Computer Science", students);

        System.out.println("Enter the name of supervisor: ");
        Scanner in = new Scanner(System.in);

        Set<Postgraduate> postgraduateSet = course.getPostgraduates(in.nextLine());
        if (!postgraduateSet.isEmpty()) {
            for (Postgraduate postgraduate : postgraduateSet) {
                System.out.println(postgraduate.toString());
            }

            Set<Object> testers = new HashSet(postgraduateSet);
            Notifier notifySet = new Notifier(testers);
            //Notifier notifySet = new Notifier(course.getPostgraduates(in.next()));
            System.out.println("Enter the message for students: ");
            notifySet.doNotifyAll(in.nextLine());
        }
        else
            System.out.println("There're no such students!");
    }
}
