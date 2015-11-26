package by.bsu.zmiecer.entity;

/**
 * Created by Zmiecer on 18.11.2015.
 */

public class Linear extends Series
{
    public Linear(double elem, double delta, int length)
    {
        super(elem, delta, length);
    }

    @Override
    public double getElem(int j)
    {
        j--;
        return (elem + j*delta);
    }

    @Override
    public double sum()
    {
        return length*(2*elem + (length-1)*delta)/2;
    }

}