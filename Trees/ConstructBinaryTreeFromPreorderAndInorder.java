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

    private TreeNode solve(int[] preOrder, int[] preIndex, int[] inOrder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return null;
        }
        int rootValue = preOrder[preIndex[0]];
        TreeNode root = new TreeNode(rootValue);
      

        preIndex[0]++;
        root.left = solve(preOrder, preIndex, inOrder, inStart, index - 1);
        root.right = solve(preOrder, preIndex, inOrder, index + 1, inEnd);
        return root;
    }

    public TreeNode buildTree(int[] preOrder, int[] inOrder) {
        int n = preOrder.length;
        int[] preIndex = { 0 };
        for (int i = 0; i < n; i++) {
            mp.put(inOrder[i], i);
        }
        return solve(preOrder, preIndex, inOrder, 0, n - 1);
    }
}

public class ConstructBinaryTreeFromPreorderAndInorder {

}
