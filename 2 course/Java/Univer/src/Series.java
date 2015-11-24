import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by Zmiecer on 18.11.2015.
 */

public abstract class Series
{
    double elem;
    double delta;
    int length;

    public Series(double elem, double delta, int length)
    {
        this.length = length;
        this.elem = elem;
        this.delta = delta;
    }

    abstract double getElem(int j);

    public double sum()
    {
        double s = 0.0;
        for (int i = 0; i < length; i++)
            s += getElem(i+1);
        return s;
    }

    @Override
    public String toString()
    {
        StringBuffer str = new StringBuffer();
        for (int i = 1; i <= length; i++)
        {
            str.append(getElem(i) + " ");
        }
        return str.toString();
    }

    public void saveEl(int k)
    {
        for (int i = 0; i < k; i++)
        {
            System.out.println(getElem(i));
        }
    }

    void write (String fileName) throws IOException
    {
        FileWriter file = new FileWriter(fileName);
        file.write(toString());
        file.close();
    }
}