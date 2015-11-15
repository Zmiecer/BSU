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
            System.out.print(node.inf + " ");
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
            System.out.print(node.inf + " ");
        }
    }

    public void clrtraversal()
    {
        clrtraversal(root);
    }
    private void clrtraversal(Node<T> node) {
        if(node != null)
        {
            System.out.print(node.inf + " ");
            clrtraversal(node.left);
            clrtraversal(node.right);
        }
    }





    public static void main(String[] args) {
        int n = 1;
        Tree<Integer> tree = new Tree<Integer>(n);
        tree.add(2);
        tree.add(-1);
        tree.add(4);
        tree.add(-3);
        tree.add(-2);
        tree.add(3);
        
        tree.lcrtraversal();
        System.out.println();
        tree.lrctraversal();
        System.out.println();
        tree.clrtraversal();
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
