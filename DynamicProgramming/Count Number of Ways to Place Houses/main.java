import java.util.*;

class Solution {
    final int mod = (int) 1e9 + 7;

    public int countHousePlacements(int n) {
        if (n == 1) {
            return 4;
        }

        Long prevHouse = 1L, prevSpace = 1L, total = 2L;

        for (int i = 2; i <= n; i++) {
            Long currentHouse = prevSpace;
            Long currentSpace = total;
            total = (currentHouse + currentSpace) % mod;
            prevHouse = currentHouse;
            prevSpace = currentSpace;
        }

        return (int) ((total * total) % mod);
    }
}

public class main {

}
