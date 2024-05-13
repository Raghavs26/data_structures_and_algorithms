#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int boats = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            int weight = people[left] + people[right];
            if (weight <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        return boats;
    }
};

int main() {
    return 0;
}