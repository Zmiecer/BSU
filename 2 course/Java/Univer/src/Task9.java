/**
 * Created by Zmiecer on 09.11.2015.
 */

import java.io.*;
import java.util.*;

public class Task9 {

    public static double[][] power(double[][] a, int deg)
    {
        int n = a[0].length;
        double p[][] = new double[n][n];
        double b[][] = a;

        double e[][] = new double[n][n];

        if (deg > 0) {
            while (deg > 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                            p[i][j] += b[i][k] * a[k][j];
                        }
                    }
                }
                b = p;
                p = e;
                deg--;
            }
        }
        else
            if (deg == 0)
            {
                for (int i = 0; i < n; i++)
                    e[i][i] = 1;
                return e;
            }


        return b;
    }

    public static void arrOut(double[][] a, int deg)
    {
        int n = a[0].length;

        System.out.println("Матрица A в степени " + deg + ": ");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        try
        {
            // Считывание
            Scanner scanner = new Scanner(new FileReader("input.txt"));

            if (!scanner.hasNext())
                throw new IllegalArgumentException("Введите данные!");

            int n;
            if (scanner.hasNextInt())
                n = scanner.nextInt();
            else
                throw new IllegalArgumentException("N");
            if (n < 0)
                throw new IllegalArgumentException("N");

            int deg;
            if (scanner.hasNextInt())
                deg = scanner.nextInt();
            else
                throw new IllegalArgumentException("Введите целую степень!");

            double A[][] = new double[n][n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!scanner.hasNext())
                        throw new IllegalArgumentException("Матрица не квадратная!");
                    A[i][j] = scanner.nextDouble();
                }
            }

            // Возведение в степень
            A = power(A, deg);

            // Вывод
            arrOut(A, deg);

        }
        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
        }
        catch (IllegalArgumentException e)
        {
            if (e.getMessage().equals("N"))
                System.out.println("Введите натуральный размер матрицы!");
            else
                System.out.println(e.getMessage());
        }
    }
}
