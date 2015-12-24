package by.bsu.zmiecer;

/**
 * Created by Zmiecer on 22.12.2015.
 */
public abstract class Paper implements Comparable<Paper> {

    String name;
    String editor;
    int numberOfPages;

    public Paper(String name, String editor, int numberOfPages) {
        this.name = name;
        this.editor = editor;
        this.numberOfPages = numberOfPages;
    }

    @Override
    public int compareTo(Paper otherPaper) {
        if(!editor.equals(otherPaper.editor))
            return editor.compareTo(otherPaper.editor);
        else
        if(!name.equals(otherPaper.name))
            return name.compareTo(otherPaper.name);
        else
            return otherPaper.numberOfPages - numberOfPages;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Paper paper = (Paper) o;

        return numberOfPages == paper.numberOfPages && name.equals(paper.name) && editor.equals(paper.editor);

    }

    public String getName() {
        return name;
    }

    public String getEditor() {
        return editor;
    }

    public int getNumberOfPages() {
        return numberOfPages;
    }
}
