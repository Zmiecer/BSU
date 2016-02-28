package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 20.12.2015.
 */
public class Runner {
    public static void main(String[] args) {
        Tree<Integer> integerTree = new Tree<Integer>(10);


        integerTree.add(36);
        integerTree.add(45);
        integerTree.add(15);
        integerTree.add(51);
        integerTree.add(73);
        integerTree.add(22);
        integerTree.add(73);
        integerTree.add(27);
        integerTree.add(31);
        integerTree.add(81);
        integerTree.add(14);


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
