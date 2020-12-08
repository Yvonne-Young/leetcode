/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& a, int start, int end) {
        int pivot = a[end];
        int P_index = start;
        int temp;
        for (int i = start; i < end; i ++) {
            if (a[i] <= pivot) {
                temp = a[i];
                a[i] = a[P_index];
                a[P_index] = temp;
                P_index ++;
            }
        }
        temp = a[end];
        a[end] = a[P_index];
        a[P_index] = temp;

        return P_index; //return the position of the pivot;
    }

    void QuickSort(vector<int>& nums, int start, int end) {
        if(start < end) {
            int P_index = partition(nums, start, end);
            QuickSort(nums, start, P_index - 1);
            QuickSort(nums, P_index + 1, end);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        QuickSort(nums, 0, size - 1);
        int count = 0;
        /*
        for (int i = size - 1; i > 1; i --) {
            if (nums[i] != nums[i - 1]) {
                count ++;
            }
            if (count == k) {
                return nums[i];
            }
        }*/
        return nums[size - k];
    }
};
// @lc code=end

