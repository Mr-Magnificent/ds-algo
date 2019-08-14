import java.util.*;

public class genericTree {
    public static class Node {
        int data = 0;
        ArrayList<Node> children = new ArrayList<>();

        Node(int i) {
            this.data = i;
        }
    }

    // #include<list> push_front(x), push_back(x), pop_front(), pop_back(), front(),
    // back()
    public static Node constructor(int[] arr) {
        LinkedList<Node> st = new LinkedList<>();
        Node root = null;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1) {
                st.removeFirst();
            } else {
                Node node = new Node(arr[i]);
                if (st.size() == 0) {
                    root = node;
                } else {
                    st.getFirst().children.add(node);
                }
                st.addFirst(node);
            }
        }
        return root;
    }

    static void display(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        stack.addFirst(root);

        while (!stack.isEmpty()) {
            Node remNode = stack.removeFirst();

            System.out.print(remNode.data + " -> ");

            for (int i = remNode.children.size() - 1; i >= 0; i--) {
                System.out.print(remNode.children.get(i).data + ", ");
                stack.addFirst(remNode.children.get(i));
            }
            System.out.println();
        }
    }

    static void displayRecursive(Node root) {

        System.out.print(root.data + " -> ");

        for (int i = 0; i < root.children.size(); i++) {
            System.out.print(root.children.get(i).data + ", ");
        }
        System.out.println();

        for (int i = 0; i < root.children.size(); i++) {
            display(root.children.get(i));
        }
    }

    static boolean findElement(Node root, int data) {
        LinkedList<Node> stack = new LinkedList<>();
        stack.addFirst(root);

        while (!stack.isEmpty()) {
            Node remNode = stack.removeFirst();

            if (remNode.data == data) {
                return true;
            }

            for (int i = remNode.children.size() - 1; i >= 0; i--) {
                stack.addFirst(remNode.children.get(i));
            }
        }
        return false;
    }

    static int findMaxElement(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        stack.addFirst(root);
        int max = Integer.MIN_VALUE;

        while (!stack.isEmpty()) {
            Node remNode = stack.removeFirst();

            if (remNode.data > max) {
                max = remNode.data;
            }

            for (int i = remNode.children.size() - 1; i >= 0; i--) {
                stack.addFirst(remNode.children.get(i));
            }
        }
        return max;
    }

    static int findMinElement(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        stack.addFirst(root);
        int min = Integer.MAX_VALUE;

        while (!stack.isEmpty()) {
            Node remNode = stack.removeFirst();

            if (remNode.data < min) {
                min = remNode.data;
            }

            for (int i = remNode.children.size() - 1; i >= 0; i--) {
                stack.addFirst(remNode.children.get(i));
            }
        }
        return min;
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1,
                -1 };
        Node root = constructor(arr);

        display(root);
        System.out.println();
        System.out.println(findElement(root, 60));
        System.out.println();
        System.out.println(findMaxElement(root));
        System.out.println();
        System.out.println(findMinElement(root));
    }
}