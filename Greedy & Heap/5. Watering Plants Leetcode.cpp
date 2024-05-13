#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
   public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int steps = 0;
        int currentWater = 0;
        for (int i = 0; i < n; i++) {
            if (plants[i] > currentWater) {
                steps += (2 * i);
                currentWater = capacity;
            }
            currentWater -= plants[i];
            steps++;
        }
        return steps;
    }
};

int main() {
    return 0;
}