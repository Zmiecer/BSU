package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 22.12.2015.
 */
public class Newspaper extends Paper {
    String coloring;

    public Newspaper(String name, String editor, int numberOfPages, String coloring) {
        super(name, editor, numberOfPages);
        this.coloring = coloring;
    }

    public String getColoring() {
        return coloring;
    }
}
