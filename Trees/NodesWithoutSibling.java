package Trees;

import java.util.git ;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Tree {
    ArrayList<Integer> noSibling(Node node) {
        ArrayList<Integer> ans = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        while (!q.isEmpty()) {
            Node front = q.poll();
            if (front.left != null) {
                q.add(front.left);
            }
            if (front.right != null) {
                q.add(front.right);
            }
            if (front.left != null && front.right == null) {
                ans.add(front.left.data);
            }
            if (front.right != null && front.left == null) {
                ans.add(front.right.data);
            }
        }
        if (ans.size() == 0) {
            ans.add(-1);
            return ans;
        }
        Collections.sort(ans);
        return ans;
    }
}

public class NodesWithoutSibling {

}
