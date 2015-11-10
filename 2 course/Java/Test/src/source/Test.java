package source;

import java.util.Scanner;

/**
 * Created by ִלטענטי on 23.09.2015.
 */

public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Shalom! Insert your number:");
        int k = scanner.nextInt();
        System.out.println("Insert divider:");
        int c = scanner.nextInt();
        int d = k / c;
        int r = k % c;
        System.out.println("Division:");
        System.out.println( k + " / " + c + " = " + d + "*" + c + " + " + r);
    }
}
