#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class BubbleSort {
   public:
    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};

int main() {
    BubbleSort* bs = new BubbleSort();
    vector<int> nums{3, 1, 4, 0};
    bs->bubbleSort(nums);
    for (auto i : nums) cout << i << " ";
    return 0;
}