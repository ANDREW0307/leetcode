/*
    idea: use recursion and split the array in half in each recursive call based on if the middle index is greater than or less than the target
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, nums, target);
    }

    int binary_search(int lower, int upper, vector<int>& nums, int target) {
        if (lower > upper) return -1;

        int mid = (lower + upper) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return binary_search(lower, mid - 1, nums, target);
        } else {
            return binary_search(mid + 1, upper, nums, target);
        }
    }
};

