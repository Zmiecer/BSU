/**
 * Created by Zmiecer on 09.11.2015.
 */

import java.io.*;
import java.util.*;

public class Task9 {

    public static double[][] power(double[][] A, int deg)
    {
        int n = A[0].length;
        double P[][] = new double[n][n];
        double B[][] = A;

        double N[][] = new double[n][n];

        if (deg > 0) {
            while (deg > 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                            P[i][j] += B[i][k] * A[k][j];
                        }
                    }
                }
                B = P;
                P = N;
                deg--;
            }
        }
        else
            if (deg == 0)
            {
                for (int i = 0; i < n; i++)
                    N[i][i] = 1;
                return N;
            }


        return B;
    }

    public static void arrout(double[][] A, int deg)
    {
        int n = A[0].length;

        System.out.println("Матрица A в степени " + deg + ": ");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        try
        {
            // Считывание
            Scanner scanner = new Scanner(new File("C:\\Users\\Дмитрий\\Документы\\GitHub\\BSU-FAMCS\\2 course\\Java\\Univer\\src\\input.txt"));
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
                    A[i][j] = scanner.nextInt();
                }
            }

            // Вовзедение в степень
            A = power(A, deg);

            // Вывод
            arrout(A, deg);

        }
        catch (FileNotFoundException fnfe)
        {
            System.out.println("File not found!");
        }
        catch (IllegalArgumentException iae)
        {
            if (iae.getMessage().equals("N"))
                System.out.println("Введите натуральный размер матрицы!");
            else
                System.out.println(iae.getMessage());
        }
    }
}
