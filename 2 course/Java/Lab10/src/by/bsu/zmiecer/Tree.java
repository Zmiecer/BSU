package by.bsu.zmiecer;

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