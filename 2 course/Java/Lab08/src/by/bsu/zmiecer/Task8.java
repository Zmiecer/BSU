package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 28.10.2015.
 */

public class Task8
{
    public static StringBuilder strChange(StringBuilder str)
    {

        String str1 = "";
        String str2 = "";
        StringBuilder str3 = new StringBuilder ();
        StringBuilder str4 = new StringBuilder ();
        for (int i = 0; i < str.length() - 1; i++)
            if (str.charAt(i+1) == str.charAt(i))
            {
                if (str1.equals(""))
                    str1 += str.charAt(i);
                str1 += str.charAt(i+1);


                //if (str.length() == 0)
                //    str3.append(str.charAt(i));
                str3.append(str.charAt(i+1));
            }
            else
            {
                if (str1.length() > str2.length())
                    str2 = str1;
                str1 = "";

                str3.append(str.charAt(i));
                if (str3.length() > str4.length())
                    str4 = str3;
                str3 = new StringBuilder();
            }

        StringBuilder a = new StringBuilder(str2);
        return str4;
    }

        public static void main(String[] args)
    {
        //String str="";
        try
        {
            if (args.length == 0)
                throw new ArrayIndexOutOfBoundsException();

            //for (int i = 0; i <args.length ; i++)
           // {
           //     str += args[i] + " ";

            //}
            StringBuilder str = new StringBuilder();
            for (int i = 0; i <args.length ; i++)
            {
                 str.append(args[i]);
            }
            System.out.println(strChange(str));

        }
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Enter data!");
        }


    }
}
