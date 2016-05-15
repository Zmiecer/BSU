package by.bsu.zmiecer;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import java.awt.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Zmiecer on 27.03.2016.
 */
public class ExcelFrame extends JFrame
{
    private JTable table;
    private final int ROWS = 10;
    private final int COLUMNS = 6;
    private String [][] strings = new String[ROWS][COLUMNS];
    public ExcelFrame() throws HeadlessException
    {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setBounds(100, 100, 800, 400);
        setTitle("Excel");

        table = new JTable(ROWS, COLUMNS)
        {
            //  Returning the Class of each column will allow different
            //  renderers to be used based on Class
            public Class getColumnClass(int column)
            {
                return String.class;
            }
        };
        for (int i = 0; i < table.getColumnCount(); i++) {
            table.getColumnModel().getColumn(i).setCellRenderer(new DateRenderer());
        }
        table.setPreferredScrollableViewportSize(table.getPreferredSize());
        table.setRowHeight(48);

        JScrollPane scrollPane = new JScrollPane(table);
        JPanel contentPane = new JPanel();
        contentPane.setLayout(new BorderLayout());
        contentPane.add(scrollPane, BorderLayout.CENTER);
        setContentPane(contentPane);

        setVisible(true);
    }

    private class DateRenderer extends DefaultTableCellRenderer
    {
        private JTextField textField = new JTextField();
        private Pattern datePattern = Pattern.compile("(\\d+)[.](\\d+)[.](\\d+)");
//        private Pattern datePattern = Pattern.compile("^("
//                + "((([0]?[1-9])|([1-2]\\d)|([3][0-1]))" + "[.]" + "(([0]?[13578])|([1][0])|([1][2])))"
//                + "|" + "((([0]?[1-9])|([1-2]\\d)|([3][0]))" + "[.]" + "(([0]?[46])|([1][1])))" + "|"
//                + "((([0]?|[1][1-9])|([1][0])|([2][0-8]))" + "[.]" + "([0]?[2]))"
//                + ")" + "[.]" + "(\\d+)$");
        private Pattern longDatePattern = Pattern.compile("[=](\\d+)[.](\\d+)[.](\\d+)[+-](\\d+)");
//        private Pattern longDatePattern = Pattern.compile("^[=]("
//                + "((([0]?[1-9])|([1-2]\\d)|([3][0-1]))" + "[.]" + "(([0]?[13578])|([1][0])|([1][2])))"
//                + "|" + "((([0]?[1-9])|([1-2]\\d)|([3][0]))" + "[.]" + "(([0]?[46])|([1][1])))" + "|"
//                + "((([0]?|[1][1-9])|([1][0])|([2][0-8]))" + "[.]" + "([0]?[2]))"
//                + ")" + "[.]" + "(\\d+)[+-](\\d+)$");

        private Pattern letterDatePattern = Pattern.compile("^[=]([A-Z](\\d+))[+-](\\d+)$");
        private Pattern funcPattern = Pattern.compile("^[=]((MIN)|(MAX))[(]((\\d+)[.](\\d+)[.](\\d+)[,])*([A-Z](\\d+)[,])*(((\\d+)[.](\\d+)[.](\\d+))|([A-Z](\\d+)))[)]");
        private Matcher m;


        public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column)
        {
            if(value != null)
            {
                String temp = (String) value;
                temp = temp.replaceAll(" ", "");
                match(temp, row, column);
            }

            textField.setText(strings[row][column]);

            return textField;
        }

        private void match(String str, int row, int column)
        {
            Matcher dateMatcher = datePattern.matcher(str);
            Matcher longDateMatcher = longDatePattern.matcher(str);
            Matcher linkMatcher = letterDatePattern.matcher(str);
            Matcher funcMatcher = funcPattern.matcher(str);
            if(dateMatcher.matches())
            {
                m = Pattern.compile("(\\d+)").matcher(str);
                m.find();
                int day = Integer.parseInt(m.group());
                m.find();
                int month = Integer.parseInt(m.group());
                month--;
                m.find();
                int year = Integer.parseInt(m.group());

                GregorianCalendar calendar = new GregorianCalendar(year, month, day);
                strings[row][column] = calendar.get(GregorianCalendar.DAY_OF_MONTH) + "." + (calendar.get(GregorianCalendar.MONTH) + 1) + "." + calendar.get(GregorianCalendar.YEAR);
            }
            else
            if(longDateMatcher.matches())
            {
                m = datePattern.matcher(str);
                m.find();
                String dat = m.group();

                m = Pattern.compile("(\\d+)").matcher(dat);
                m.find();
                int day = Integer.parseInt(m.group());
                m.find();
                int month = Integer.parseInt(m.group());
                month--;
                m.find();
                int year = Integer.parseInt(m.group());

                m = Pattern.compile("[+-](\\d+)").matcher(str);
                m.find();
                int change = Integer.parseInt(m.group());

                GregorianCalendar calendar = new GregorianCalendar(year, month, day);
                calendar.add(GregorianCalendar.DAY_OF_MONTH, change);
                strings[row][column] = calendar.get(GregorianCalendar.DAY_OF_MONTH) + "." + (calendar.get(GregorianCalendar.MONTH) + 1) + "." + calendar.get(GregorianCalendar.YEAR);

            }
            else
            if(linkMatcher.matches())
            {
                try
                {
                    int indexX = str.charAt(1) - 'A';
                    int indexY = str.charAt(2) - '0' - 1;
                    m = Pattern.compile("[+-](\\d+)").matcher(str);
                    m.find();
                    int change = Integer.parseInt(m.group());

                    //String temp1 = (String) table.getValueAt(indexY, indexX);
                    String temp1 = strings[indexY][indexX];
                    m = Pattern.compile("(\\d+)").matcher(temp1);
                    m.find();
                    int day = Integer.parseInt(m.group());
                    m.find();
                    int month = Integer.parseInt(m.group());
                    month--;
                    m.find();
                    int year = Integer.parseInt(m.group());

                    GregorianCalendar calendar = new GregorianCalendar(year, month, day);
                    calendar.add(GregorianCalendar.DAY_OF_MONTH, change);
                    strings[row][column] = calendar.get(GregorianCalendar.DAY_OF_MONTH) + "." + (calendar.get(GregorianCalendar.MONTH) + 1) + "." + calendar.get(GregorianCalendar.YEAR);

                }
                catch (IllegalStateException|ArrayIndexOutOfBoundsException e)
                {
                    strings[row][column] = "Illegal link!";
                }
                catch (NullPointerException e)
                {
                    strings[row][column] = "No data in linked item!";
                }
            }
            else
            if(funcMatcher.matches())
            {
                try
                {
                    SortedSet<GregorianCalendar> calendars = new TreeSet<>();

                    m = datePattern.matcher(str);
                    while(m.find())
                    {
                        String dat = m.group();
                        Matcher m1 = Pattern.compile("(\\d+)").matcher(dat);
                        m1.find();
                        int day = Integer.parseInt(m1.group());
                        m1.find();
                        int month = Integer.parseInt(m1.group());
                        month--;
                        m1.find();
                        int year = Integer.parseInt(m1.group());

                        GregorianCalendar tmpCalendar = new GregorianCalendar(year, month, day);
                        calendars.add(tmpCalendar);
                    }
                    m = Pattern.compile("[A-Z](\\d+)").matcher(str);
                    while(m.find())
                    {
                        String dat = m.group();
                        int indexX = dat.charAt(0) - 'A';
                        int indexY = dat.charAt(1) - '0' - 1;

                        String temp1 = strings[indexY][indexX];
                        Matcher m1 = Pattern.compile("(\\d+)").matcher(temp1);
                        m1.find();
                        int day = Integer.parseInt(m1.group());
                        m1.find();
                        int month = Integer.parseInt(m1.group());
                        month--;
                        m1.find();
                        int year = Integer.parseInt(m1.group());

                        GregorianCalendar tmpCalendar = new GregorianCalendar(year, month, day);
                        calendars.add(tmpCalendar);
                    }
                    GregorianCalendar calendar;
                    if(str.contains("MAX"))
                        calendar = calendars.last();
                    else
                        calendar = calendars.first();

                    strings[row][column] = calendar.get(GregorianCalendar.DAY_OF_MONTH) + "." + (calendar.get(GregorianCalendar.MONTH) + 1) + "." + calendar.get(GregorianCalendar.YEAR);

                }
                catch (NullPointerException e)
                {
                    //JOptionPane.showMessageDialog(getParent(),"Please, enter correct data!");
                    strings[row][column] = "No data in linked item!";
                }
                catch (IllegalStateException e)
                {
                    strings[row][column] = "Incorrect data in linked item!";
                }
            }
            else
            {
                if(str.equals(""))
                    strings[row][column] = "";
                else
                    strings[row][column] = "Illegal data!";
            }
        }
    }
}
