package Trees;

import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Tree {
    // Recursive function to print right view of a binary tree.
    ArrayList<Integer> Kdistance(Node root, int k) {
        if (k == 0)
            return new ArrayList<>(root.data);
        ArrayList<Integer> res = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            if (k < 0)
                break;
            while (size-- > 0) {
                Node current = q.poll();
                if (k == 0) {
                    res.add(current.data);
                }
                if (current.left != null) {
                    q.add(current.left);
                }
                if (current.right != null) {
                    q.add(current.right);
                }
            }
            k--;
        }
        return res;
    }
}

public class KDistanceFromRoot {

}
