package by.bsu.zmiecer;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created by Zmiecer on 06.12.2015.
 */

public class Runner {
    public static void main(String[] args) {
        TreeCollection<ForestTree> forestTrees = new TreeCollection<>();
        try
        {
            Scanner sc = new Scanner(new File("forest.txt"));
            while (true) {
                if (sc.hasNextLine()) {
                    ForestTree tree = new ForestTree(sc.next(), sc.nextInt(), sc.next(), sc.nextInt());
                    forestTrees.add(tree);
                }
                else
                    break;
            }
        }
        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
        }

        ForestTree tree1 = new ForestTree("Test", 10, "leaf", 20);
        ForestTree tree2 = new ForestTree("Zest", 10, "leaf", 20);
        ForestTree tree3 = new ForestTree("Best", 10, "leaf", 20);
        ForestTree tree4 = new ForestTree("Best", 20, "leaf", 20);

        //TreeCollection<ForestTree> temp = new TreeCollection<>();
        //temp.add(tree2);
        //temp.add(tree3);
        //temp.add(tree4);

        forestTrees = forestTrees.sort();
        forestTrees.printInf();
        System.out.println();
        System.out.println(forestTrees.binarySearch(tree1));
        System.out.println(forestTrees.binarySearch(tree3));

        System.out.println(forestTrees.max());
        System.out.println(forestTrees.min());
        System.out.println(forestTrees.frequency(tree2));
    }
}
