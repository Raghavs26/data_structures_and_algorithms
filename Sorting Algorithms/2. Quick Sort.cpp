#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low, j = high;
        while (i < j) {
            while (i < high && nums[i] <= pivot) i++;
            while (j > low && nums[j] > pivot) j--;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int idx = partition(nums, low, high);
            quickSort(nums, low, idx - 1);
            quickSort(nums, idx + 1, high);
        }
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    return 0;
}