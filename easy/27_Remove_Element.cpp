/*

idea: whenever we find an element that we want to keep, we will swap it with a pointer to the next available spot in the array from left to right. In this way, all the values that we dont' want will be replaced by values that we do want


*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // pointer to next available index

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++; // since k only increases when we finda value that we don't want to remove, swaps will only occur to replace the leftmost available index with a value that we want, meaning the correct k value will be returned in the end
            }
        }

        return k;
    }
};
