/**
 * Created by Zmiecer on 21.10.2015.
 */

public class Task7
{
    public static double count(double e, double x)
    {
        double f =-x*x*x/12;
        double sum = f;
        for (int k = 2; Math.abs(f) >= e; k++)
        {
            f*=-x * k / ((k + 1) * (k + 2));
            sum += f;
        }

        return sum;
    }

    public static void main(String[] args)
    {
        try
        {
            if (args.length != 2)
            {
                throw new IllegalArgumentException("Аргументов не 2!");
            }
            double e = Double.valueOf(args[0]); // Double.parseDouble(args[0]);
            double x = Double.valueOf(args[1]);

            System.out.println("Сумма = " + count(e, x));
        }
        catch(NumberFormatException s)
        {
            System.out.println("Проблемы с конвертацией!");
        }
        catch(IllegalArgumentException e)
        {
            System.out.println(e.getMessage());
        }
    }
}
