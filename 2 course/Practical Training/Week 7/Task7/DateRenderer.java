import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import java.awt.*;
import java.util.Date;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Zmiecer on 27.03.2016.
 */

class DateRenderer extends DefaultTableCellRenderer
{
    JTextField textField = new JTextField();
    Date [][] dates = new Date[10][10];
    String [][] strings = new String[10][10];
    Pattern date = Pattern.compile("^("
            + "((([0][1-9])|([1-2]\\d)|([3][0-1]))" + "[.]" + "(([0][13578])|([1][0])|([1][2])))"
            + "|" + "((([0][1-9])|([1-2]\\d)|([3][0]))" + "[.]" + "(([0][46])|([1][1])))" + "|"
            + "((([0-1][1-9])|([1][0])|([2][0-8]))" + "[.]" + "([0][2]))"
            + ")" + "[.]" + "(\\d+)$");
    Pattern longDate = Pattern.compile("^[=]("
            + "((([0][1-9])|([1-2]\\d)|([3][0-1]))" + "[.]" + "(([0][13578])|([1][0])|([1][2])))"
            + "|" + "((([0][1-9])|([1-2]\\d)|([3][0]))" + "[.]" + "(([0][46])|([1][1])))" + "|"
            + "((([0-1][1-9])|([1][0])|([2][0-8]))" + "[.]" + "([0][2]))"
            + ")" + "[.]" + "(\\d+)[+-](\\d+)$");
    boolean plus = false;


    public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column)
    {

        //dates[row][column] = (Date)value;
        if(value != null && value != "")
        {
            String temp = (String) value;
            if (temp.charAt(0) == '=')
            {
                Matcher m = longDate.matcher(temp);
                if (m.matches())
                {
                    int index;
                    if(temp.indexOf('+') > temp.indexOf('-'))
                    {
                        plus = true;
                        index = temp.indexOf('+');
                    }
                    else
                        index = temp.indexOf('-');
                    int change = Integer.parseInt(temp.substring(index + 1));
                    int day = Integer.parseInt(temp.substring(1, 3));
                    int month = Integer.parseInt(temp.substring(4, 6));
                    int year = Integer.parseInt(temp.substring(7, index));
                    if(plus)
                        day += change;
                    else
                        day -= change;
                    String tmpday = "" + day;
                    String tmpmonth = "" + month;
                    if (day < 10)
                        tmpday = "0" + day;
                    if (month < 10)
                        tmpmonth = "0" + month;
                    temp = tmpday + "." + tmpmonth + "." + year;
                    m = date.matcher(temp);
                    if (m.matches())
                    {
                        strings[row][column] = temp;
                    }
                    else
                    {
                        day = Integer.parseInt(temp.substring(0, 2));
                        month = Integer.parseInt(temp.substring(3, 5));
                        day -= 30;
                        month += 1;
                        tmpday = "" + day;
                        tmpmonth = "" + month;
                        if (day < 10)
                            tmpday = "0" + day;
                        if (month < 10)
                            tmpmonth = "0" + month;
                        temp = tmpday + "." + tmpmonth + "." + year;
                        m = date.matcher(temp);
                        if (m.matches())
                        {
                            strings[row][column] = temp;
                        }
                        else
                        {
                            month = Integer.parseInt(temp.substring(3, 5));
                            year = Integer.parseInt(temp.substring(6));
                            month -= 12;
                            year += 1;
                            if (day < 10)
                                tmpday = "0" + day;
                            if (month < 10)
                                tmpmonth = "0" + month;
                            temp = tmpday + "." + tmpmonth + "." + year;
                            strings[row][column] = temp;
                        }
                    }
            }
            else
                {
                    setValue("");
                    setText("");
                    //JOptionPane.showMessageDialog(getParent(),"Please, enter correct data!");
                    strings[row][column] = "";
                    setValue("");
                }
            }
            else
            {
                Matcher m = date.matcher(temp);
                if (m.matches())
                {
                    strings[row][column] = temp;
                }
                else
                {
                    setValue("");
                    setText("");
                    //JOptionPane.showMessageDialog(getParent(),"Please, enter correct data!");
                    strings[row][column] = "";
                    setValue("");
                }
            }
        }
        //strings[row][column] = (String)value;
        try
        {
            if (!(strings[row][column]).equals(""))
                textField.setText(strings[row][column]);
        }
        catch (NullPointerException e)
        {
            textField.setText("");
        }
        return textField;
    }
}