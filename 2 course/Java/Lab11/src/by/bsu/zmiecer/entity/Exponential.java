package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 18.11.2015.
 */

public class Exponential extends Series
{
    public Exponential(double elem, double delta, int length) {
        super(elem, delta, length);
    }

    @Override
    public double getElem(int j)
    {
        j--;
        double del = 1.0;
        while(j != 0)
        {
            del*=delta;
            j--;
        }
        return (elem*del);

    }

    @Override
    public double sum()
    {
        return (elem*(1-Math.pow(delta, length)))/(1-delta);
    }
}
