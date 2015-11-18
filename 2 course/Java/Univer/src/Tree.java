/**
 * Created by Zmiecer on 11.11.2015.
 */



public class Tree<T extends Comparable>
{
    Node<T> root;

    public Tree()
    {
        root = null;
    }

    public Tree(T t)
    {
        root = new Node(t);
    }

    public void add(T a) {
        Node x = root, y = null;
        while (x != null)
        {
            int cmp = a.compareTo(x.inf);
            if (cmp == 0)
            {
                x.inf = a;
                return;
            }
            else
            {
                y = x;
                if (cmp < 0)
                {
                    x = x.left;
                }
                else
                {
                    x = x.right;
                }
            }
        }
        Node<T> newNode = new Node<T>(a);
        if (y == null)
        {
            root = newNode;
        }
        else
        {
            if (a.compareTo(y.inf) < 0)
            {
                y.left = newNode;
            }
            else
            {
                y.right = newNode;
            }
        }
    }

    public void lcrTraversal()
    {
        lcrTraversal(root);
    }
    private void lcrTraversal(Node<T> node) {
        if(node != null)
        {
            lcrTraversal(node.left);
            System.out.println(node.inf + " ");
            lcrTraversal(node.right);
        }
    }

    public void lrcTraversal()
    {
        lrcTraversal(root);
    }
    private void lrcTraversal(Node<T> node) {
        if(node != null)
        {
            lrcTraversal(node.left);
            lrcTraversal(node.right);
            System.out.println(node.inf + " ");
        }
    }

    public void clrTraversal()
    {
        clrTraversal(root);
    }
    private void clrTraversal(Node<T> node) {
        if(node != null)
        {
            System.out.println(node.inf + " ");
            clrTraversal(node.left);
            clrTraversal(node.right);
        }
    }

    public boolean search(T t)
    {
        return search(root, t);
    }
    private boolean search(Node<T> node, T t)
    {
        if (node.left != null && node.right != null)
        {
            if (node.inf.compareTo(t) == 0)
            {
                return true;
            }
            else if (node.inf.compareTo(t) > 0)
                return search(node.right, t);
            else
                return search(node.left, t);
        }
        else
        {
            return false;
        }
    }



    public static void main(String[] args) {
        int n = 1;
        Tree<Integer> integerTree = new Tree<Integer>(n);
        integerTree.add(3);
        integerTree.add(-1);
        integerTree.add(2);
        integerTree.add(-3);
        integerTree.add(-2);
        integerTree.add(6);
        integerTree.add(5);

        integerTree.lcrTraversal();
        System.out.println();
        integerTree.lrcTraversal();
        System.out.println();
        integerTree.clrTraversal();


        double d = 1.3;
        Tree<Double> doubleTree = new Tree<Double>(d);
        doubleTree.add(2.3);
        doubleTree.add(-1.4);
        doubleTree.add(7.5);
        doubleTree.add(-2.8);
        doubleTree.add(6.5);
        doubleTree.add(1.7);

        System.out.println();
        doubleTree.lcrTraversal();
        System.out.println();
        doubleTree.lrcTraversal();
        System.out.println();
        doubleTree.clrTraversal();





        Tree<Student> studentTree = new Tree<Student>();
        studentTree.add(new Student("Bylinovich", 19, 7.0));
        studentTree.add(new Student("Michnovec", 18, 8.0));
        studentTree.add(new Student("Avizhen", 18, 9.0));
        studentTree.add(new Student("Bykinevich", 18, 7.5));
        studentTree.add(new Student("Zacharenko", 20, 6.3));
        studentTree.add(new Student("Varchenko", 21, 8.3));

        System.out.println();
        studentTree.lcrTraversal();
        System.out.println();
        studentTree.lrcTraversal();
        System.out.println();
        studentTree.clrTraversal();

        System.out.println();
        Student bylinovich = new Student("Bylinovich", 19, 7.0);
        Student demidko = new Student("Dorohovich", 18, 8.6);
        if(studentTree.search(bylinovich))
            System.out.println("Student found!");
        else
            System.out.println("Student not found.");
        if(studentTree.search(demidko))
            System.out.println("Student found!");
        else
            System.out.println("Student not found.");


    }




    public class Node<T> {
        T inf;
        Node<T> left;
        Node<T> right;

        public Node(T t)
        {
            inf = t;
            left = right = null;
        }

    }
}