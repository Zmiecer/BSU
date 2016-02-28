package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 20.12.2015.
 */
public class Runner {
    public static void main(String[] args) {
        int n = 1;
        Tree<Integer> integerTree = new Tree<Integer>(n);
        integerTree.add(3);
        integerTree.add(-1);
        integerTree.add(2);
        integerTree.add(-3);
        integerTree.add(-2);
        integerTree.add(6);
        integerTree.add(5);

        integerTree.lcrTraversal();
        System.out.println();
        integerTree.lrcTraversal();
        System.out.println();
        integerTree.clrTraversal();


        double d = 1.3;
        Tree<Double> doubleTree = new Tree<Double>(d);
        doubleTree.add(2.3);
        doubleTree.add(-1.4);
        doubleTree.add(7.5);
        doubleTree.add(-2.8);
        doubleTree.add(6.5);
        doubleTree.add(1.7);

        System.out.println();
        doubleTree.lcrTraversal();
        System.out.println();
        doubleTree.lrcTraversal();
        System.out.println();
        doubleTree.clrTraversal();





        Tree<Student> studentTree = new Tree<Student>();
        studentTree.add(new Student("Bylinovich", 19, 7.0));
        studentTree.add(new Student("Michnovec", 18, 8.0));
        studentTree.add(new Student("Avizhen", 18, 9.0));
        studentTree.add(new Student("Bykinevich", 18, 7.5));
        studentTree.add(new Student("Zacharenko", 20, 6.3));
        studentTree.add(new Student("Varchenko", 21, 8.3));

        System.out.println();
        studentTree.lcrTraversal();
        System.out.println();
        studentTree.lrcTraversal();
        System.out.println();
        studentTree.clrTraversal();

        System.out.println();
        Student bylinovich = new Student("Bylinovich", 19, 7.0);
        Student demidko = new Student("Dorohovich", 18, 8.6);
        if(studentTree.search(bylinovich))
            System.out.println("Student found!");
        else
            System.out.println("Student not found.");
        if(studentTree.search(demidko))
            System.out.println("Student found!");
        else
            System.out.println("Student not found.");


    }
}
