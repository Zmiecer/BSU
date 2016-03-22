package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 20.12.2015.
 */
public class Runner {
    public static void main(String[] args) {
        Tree<Integer> integerTree = new Tree<Integer>(8);


        //integerTree.add(8);
        integerTree.add(4);
        integerTree.add(12);
        integerTree.add(2);
        integerTree.add(6);
        integerTree.add(10);
        integerTree.add(14);
        integerTree.add(1);
        integerTree.add(3);
        integerTree.add(5);
        integerTree.add(7);
        integerTree.add(9);
        integerTree.add(11);
        integerTree.add(13);
        integerTree.add(15);


        //for (int i = 10; i > 0; i--) {
        //    integerTree.add(i);
        //}


        integerTree.clrTraversal();
        System.out.println();
        integerTree.lrcTraversal();
        System.out.println();
        integerTree.lcrTraversal();


    }
}
