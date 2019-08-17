import java.util.*;

public class genericTree {
    public static class Node {
        int data = 0;
        int level;
        ArrayList<Node> children = new ArrayList<>();

        Node(int i) {
            this.data = i;
        }

        Node(int i, int level) {
            this.data = i;
            this.level = level;
        }
    }

    // Construct Tree =================================================================
    // #include<list> push_front(x), push_back(x), pop_front(), pop_back(), front(),
    // back()
    public static Node constructor(int[] arr) {
        LinkedList<Node> st = new LinkedList<>();
        Node root = null;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1) {
                st.removeFirst();
            } else {
                Node node;
                if (st.size() == 0) {
                    node = new Node(arr[i], 0);
                    root = node;
                } else {
                    node = new Node(arr[i], st.getFirst().level + 1);
                    st.getFirst().children.add(node);
                }
                st.addFirst(node);
            }
        }
        return root;
    }

    // Display ======================================================
    static void display(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        stack.addFirst(root);

        while (!stack.isEmpty()) {
            Node remNode = stack.removeFirst();

            System.out.print(remNode.data + "@" + remNode.level + " -> ");

            for (int i = remNode.children.size() - 1; i >= 0; i--) {
                System.out.print(remNode.children.get(i).data + "@" + remNode.children.get(i).level + ", ");
                stack.addFirst(remNode.children.get(i));
            }
            System.out.println();
        }
    }

    // Display Recursive ==============================================
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

    // FindElement =====================================================
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

    // Height of tree ==================================================
    static int heightOfTree(Node root) {
        int height = 0;

        for (int i = 0; i < root.children.size(); i++) {
            int val = heightOfTree(root.children.get(i));
            height = Math.max(height, val);
        }
        return height + 1;
    }

    // Size of tree ======================================================
    static int sizeOfTree(Node root) {
        int size = root.children.size();
        for (int i = 0; i < root.children.size(); i++) {
            size += sizeOfTree(root.children.get(i));
        }
        return size;
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

    // FindMinElement ==========================================================
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

    // Lowest Common Ancestor============================================================= 
    static int lowestCommonAncestor(Node root, int child1, int child2) {
        if (root == null) {
            return -1;
        }

        int count = 0;
        for (int i = 0; i < root.children.size(); i++) {
            int val = lowestCommonAncestor(root.children.get(i), child1, child2);
            if (val != 0 && val != -1) {
                return val;
            }
            if (val == -1) {
                count++;
            }
        }
        if (count == 1 && (root.data == child1 || root.data == child2)) {
            return root.data;
        }

        else if (count == 1) {
            return -1;
        }

        if (root.data == child1 || root.data == child2) {
            return -1;
        }

        if (count == 2) {
            return root.data;
        }

        return 0;
    }

    // LevelOrder=================================================================
    static void displayLevelOrder(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        stack.addFirst(root);

        while (!stack.isEmpty()) {
            Node remNode = stack.removeLast();

            System.out.print(remNode.data + "  ");

            for (int i = 0; i < remNode.children.size(); i++) {
                // System.out.print(remNode.children.get(i).data + ", ");
                stack.addFirst(remNode.children.get(i));
            }
            // System.out.println();
        }
        System.out.println();
    }

    // LevelWise====================================================================== 
    static void displayLevelOrderWithNewLine(Node root) {
        LinkedList<Node> q = new LinkedList<>();
        q.addLast(root);
        int currentLevel = 0;

        while (!q.isEmpty()) {
            Node remNode = q.removeFirst();

            if (remNode.data == Integer.MIN_VALUE) {
                System.out.println();
                continue;
            }

            System.out.print(remNode.data + "  ");

            for (int i = 0; i < remNode.children.size(); i++) {
                if (currentLevel != remNode.children.get(i).level) {
                    q.addLast(new Node(Integer.MIN_VALUE));
                    currentLevel = remNode.children.get(i).level;
                }
                q.addLast(remNode.children.get(i));
            }
        }
        System.out.println();
    }


    // ZIGZAG===================================================================
    static void displayLevelOrderWithNewLineWithZigZag(Node root) {
        LinkedList<Node> q = new LinkedList<>();
        q.addLast(root);
        int currentLevel = 0;
        boolean toggle = false;

        while (!q.isEmpty()) {
            Node remNode = q.removeFirst();

            if (remNode.data == Integer.MIN_VALUE) {
                System.out.println();
                toggle = !toggle;
                continue;
            }

            System.out.print(remNode.data + "  ");

            if (toggle) {
                for (int i = 0; i < remNode.children.size(); i++) {
                    if (currentLevel != remNode.children.get(i).level) {
                        q.addLast(new Node(Integer.MIN_VALUE));
                        currentLevel = remNode.children.get(i).level;
                    }
                    q.addLast(remNode.children.get(i));
                }
            } else {
                for (int i = remNode.children.size() - 1; i >= 0; i--) {
                    if (currentLevel != remNode.children.get(i).level) {
                        q.addLast(new Node(Integer.MIN_VALUE));
                        currentLevel = remNode.children.get(i).level;
                    }
                    q.addLast(remNode.children.get(i));
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1,
                -1 };
        Node root = constructor(arr);

        // display(root);
        displayLevelOrder(root);
        System.out.println();
        displayLevelOrderWithNewLine(root);
        System.out.println();
        displayLevelOrderWithNewLineWithZigZag(root);
        // System.out.println();
        // System.out.println(findElement(root, 60));
        // System.out.println();
        // System.out.println(findMaxElement(root));
        // System.out.println();
        // System.out.println(findMinElement(root));
        // // System.out.println(heightOfTree(root));
        // System.out.println();
        // // System.out.println(sizeOfTree(root));
        // System.out.println(lowestCommonAncestor(root, 10, 20));
    }
}