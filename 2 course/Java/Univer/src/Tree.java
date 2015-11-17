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

    public void lcrtraversal()
    {
        lcrtraversal(root);
    }
    private void lcrtraversal(Node<T> node) {
        if(node != null)
        {
            lcrtraversal(node.left);
            System.out.println(node.inf + " ");
            lcrtraversal(node.right);
        }
    }

    public void lrctraversal()
    {
        lrctraversal(root);
    }
    private void lrctraversal(Node<T> node) {
        if(node != null)
        {
            lrctraversal(node.left);
            lrctraversal(node.right);
            System.out.println(node.inf + " ");
        }
    }

    public void clrtraversal()
    {
        clrtraversal(root);
    }
    private void clrtraversal(Node<T> node) {
        if(node != null)
        {
            System.out.println(node.inf + " ");
            clrtraversal(node.left);
            clrtraversal(node.right);
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
                System.out.println("Student found!");
                return true;
            }
            else if (node.inf.compareTo(t) > 0)
                return search(node.right, t);
            else
                return search(node.left, t);
        }
        else
        {
            System.out.println("Student not found.");
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

        integerTree.lcrtraversal();
        System.out.println();
        integerTree.lrctraversal();
        System.out.println();
        integerTree.clrtraversal();


        double d = 1.3;
        Tree<Double> doubleTree = new Tree<Double>(d);
        doubleTree.add(2.3);
        doubleTree.add(-1.4);
        doubleTree.add(7.5);
        doubleTree.add(-2.8);
        doubleTree.add(6.5);
        doubleTree.add(1.7);

        System.out.println();
        doubleTree.lcrtraversal();
        System.out.println();
        doubleTree.lrctraversal();
        System.out.println();
        doubleTree.clrtraversal();





        Tree<Student> studentTree = new Tree<Student>();
        studentTree.add(new Student("Bylinovich", 19, 7.0));
        studentTree.add(new Student("Michnovec", 18, 8.0));
        studentTree.add(new Student("Avizhen", 18, 9.0));
        studentTree.add(new Student("Bykinevich", 18, 7.5));
        studentTree.add(new Student("Zacharenko", 20, 6.3));
        studentTree.add(new Student("Varchenko", 21, 8.3));

        System.out.println();
        studentTree.lcrtraversal();
        System.out.println();
        studentTree.lrctraversal();
        System.out.println();
        studentTree.clrtraversal();

        System.out.println();
        Student bylinovich = new Student("Bylinovich", 19, 7.0);
        Student demidko = new Student("Demidko", 18, 8.6);
        studentTree.search(bylinovich);
        studentTree.search(demidko);


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