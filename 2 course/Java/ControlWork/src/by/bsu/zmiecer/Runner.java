package by.bsu.zmiecer;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Created by Zmiecer on 06.12.2015.
 */

public class Runner {
    public static void main(String[] args) {
        PupilCollection<Student> students = new PupilCollection<>();
        try
        {
            Scanner sc1 = new Scanner(new File("students.txt"));
            while (sc1.hasNextLine())
            {
                String surname = sc1.next();
                String institution = sc1.next();
                double gpa = sc1.nextDouble();
                int course = sc1.nextInt();
                Student student = new Student(surname, institution, gpa, course);
                students.add(student);
            }

        }
        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
        }
        catch (InputMismatchException e)
        {
                System.out.println("Please, enter correct data!");
        }

        Student student1 = new Student("Bylinovich", "BSU", 7.0, 2);
        Student student2 = new Student("Bylinovich", "BSUIR", 7.0, 2);

        System.out.println("1. Information about the students in the collection: ");
        students.printInf();
        System.out.println();

        System.out.println("2. Frequency of student " + student1 + " is " + students.frequency(student1));
        System.out.println("2. Frequency of student " + student2 + " is " + students.frequency(student2));
        System.out.println();



        students = students.sort();
        int bin1 = students.binarySearch(student1);
        if(bin1 >= 0)
        {
        System.out.println("3. Student "+ student1 + " is on " + bin1 + " position");
        }
        else
            System.out.println("There are no such students in the collection!");

        bin1 = students.binarySearch(student2);
        if(bin1 >= 0)
        {
            System.out.println(students.binarySearch(student2));
        }
        else
            System.out.println("There are no such students in the collection!");



        System.out.println();
        System.out.println("4. Minimal student: " + students.min());


        System.out.println();


        PupilCollection<Schoolboy> schoolboys = new PupilCollection<>();
        try
        {
            Scanner sc2 = new Scanner(new File("schoolboys.txt"));
            while (sc2.hasNextLine())
            {
                String surname = sc2.next();
                String institution = sc2.next();
                double gpa = sc2.nextDouble();
                int classGroup = sc2.nextInt();
                String behaviour = sc2.next();
                Schoolboy schoolboy = new Schoolboy(surname, institution, gpa, classGroup, behaviour);
                schoolboys.add(schoolboy);
            }

        }
        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
        }
        catch (InputMismatchException e)
        {
            System.out.println("Please, enter correct data!");
        }


        Schoolboy schoolboy1 = new Schoolboy("Bylinovich", "Gymn10", 7.0, 5, "good");
        Schoolboy schoolboy2 = new Schoolboy("Kuratovich", "BSUIR", 6.0, 2, "satisfying");

        System.out.println("1. Information about the schoolboys in the collection: ");
        students.printInf();
        System.out.println();

        System.out.println("2. Frequency of schoolboy " + schoolboy1 + " is " + schoolboys.frequency(schoolboy1));
        System.out.println("Frequency of schoolboy " + schoolboy2 + " is " + schoolboys.frequency(schoolboy2));
        System.out.println();



        schoolboys = schoolboys.sort();
        int bin2 = schoolboys.binarySearch(schoolboy1);
        if(bin2 >= 0)
        {
            System.out.println("3. Schoolboy "+ schoolboy1 + " is on " + bin2 + " position");
        }
        else
            System.out.println("There are no such schoolboys in the collection!");

        bin2 = schoolboys.binarySearch(schoolboy2);
        if(bin2 >= 0)
        {
            System.out.println(schoolboys.binarySearch(schoolboy2));
        }
        else
            System.out.println("There are no such schoolboys in the collection!");



        System.out.println();
        System.out.println("4. Minimal schoolboy: " + schoolboys.min());
    }
}
