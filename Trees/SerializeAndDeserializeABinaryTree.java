package Trees;

import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null)
            return "";
        Queue<TreeNode> q = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode current = q.poll();
            if (current == null) {
                sb.append("# ");
                continue;
            }
            sb.append(current.val + " ");
            q.add(current.left);
            q.add(current.right);
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.length() == 0)
            return null;
        Queue<TreeNode> q = new LinkedList<>();
        String[] values = data.split(" ");
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        int n = values.length;
        for (int i = 1; i < n; i += 2) {
            TreeNode parent = q.poll();
            if (!values[i].equals("#")) {
                TreeNode left = new TreeNode(Integer.parseInt(values[i]));
                parent.left = left;
                q.add(left);
            }
            if (i + 1 < n && !values[i + 1].equals("#")) {
                TreeNode right = new TreeNode(Integer.parseInt(values[i + 1]));
                parent.right = right;
                q.add(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));

class Tree {

    public ArrayList<Integer> serialize(Node root) {
        if (root == null)
            return new ArrayList<Integer>();
        Queue<Node> q = new LinkedList<>();
        ArrayList<Integer> res = new ArrayList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node current = q.poll();
            if (current == null) {
                res.add(Integer.MAX_VALUE);
                continue;
            }
            res.add(current.data);
            q.add(current.left);
            q.add(current.right);
        }
        return res;
    }

    public Node deSerialize(ArrayList<Integer> A) {
        if (A.isEmpty())
            return null;
        int n = A.size();
        Queue<Node> q = new LinkedList<>();
        Node root = new Node(A.get(0));
        q.add(root);
        for (int i = 1; i < n; i += 2) {
            Node parent = q.poll();
            if (A.get(i) != Integer.MAX_VALUE) {
                Node left = new Node(A.get(i));
                parent.left = left;
                q.add(left);
            }
            if (i + 1 < n && A.get(i + 1) != Integer.MAX_VALUE) {
                Node right = new Node(A.get(i + 1));
                parent.right = right;
                q.add(right);
            }
        }
        return root;
    }
};

public class SerializeAndDeserializeABinaryTree {

}
