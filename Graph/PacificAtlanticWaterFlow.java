package Graph;

import java.util.*;
import java.io.*;

class Pair {
    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

}

class Solution {
    private boolean isValid(int r, int c, int[][] heights) {
        return r >= 0 && c >= 0 && r < heights.length && c < heights[0].length;
    }

    private void dfs(int[][] heights, boolean[][] visited, int prevHeight, int r, int c) {
        if (!isValid(r, c, heights) || visited[r][c] || heights[r][c] < prevHeight)
            return;
        visited[r][c] = true;
        dfs(heights, visited, heights[r][c], r + 1, c);
        dfs(heights, visited, heights[r][c], r - 1, c);
        dfs(heights, visited, heights[r][c], r, c + 1);
        dfs(heights, visited, heights[r][c], r, c - 1);
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> res = new LinkedList<>();

        int rows = heights.length, cols = heights[0].length;
        boolean[][] pacific = new boolean[rows][cols];
        boolean[][] atlantic = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, Integer.MIN_VALUE, i, 0);
            dfs(heights, atlantic, Integer.MIN_VALUE, i, cols - 1);
        }
        for (int i = 0; i < cols; i++) {
            dfs(heights, pacific, Integer.MIN_VALUE, 0, i);
            dfs(heights, atlantic, Integer.MIN_VALUE, rows - 1, i);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(i);
                    temp.add(j);
                    res.add(temp);
                }
            }
        }
        return res;
    }

}

public class PacificAtlanticWaterFlow {
    public static void main(String[] args) {
        Pair p = new Pair(0, 0);
        Set<Pair> st = new HashSet<>();
        st.add(p);
        System.out.println(st.contains(p));
    }
}
