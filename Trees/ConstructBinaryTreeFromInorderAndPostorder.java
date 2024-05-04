package Trees;

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    Map<Integer, Integer> mp = new HashMap<>();

    private TreeNode solve(int[] postOrder, int[] postIndex, int[] inOrder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return null;
        }
        int rootValue = postOrder[postIndex[0]];
        TreeNode root = new TreeNode(rootValue);
        int index = mp.get(rootValue);
        postIndex[0]--;
        root.right = solve(postOrder, postIndex, inOrder, index + 1, inEnd);
        root.left = solve(postOrder, postIndex, inOrder, inStart, index - 1);
        return root;
    }

    public TreeNode buildTree(int[] inOrder, int[] postOrder) {
        int n = inOrder.length;
        int[] postIndex = { n - 1 };
        for (int i = 0; i < n; i++) {
            mp.put(inOrder[i], i);
        }
        return solve(postOrder, postIndex, inOrder, 0, n - 1);
    }
}

public class ConstructBinaryTreeFromInorderAndPostorder {

}
