/*
    idea: first binary search for the outer array that the target is located in (this takes advantage of the fact that the outer arrays are sorted), then use a regular binary search on the inner array using the index found from the first pass of binary search
    
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int array_index = find_array(0, matrix.size() - 1, matrix, target);

        if (array_index == -1) return false;
        int target_index = binary_search(0, matrix[array_index].size() - 1, matrix[array_index], target);
        if (target_index == -1) return false;
        return true;
    }

    int find_array(int lower, int upper, vector<vector<int>>& matrix, int target) {
        if (lower > upper) return - 1;

        int mid = (lower + upper) / 2;
        if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size() - 1]) {
            return mid;
        } else if (target > matrix[mid][matrix[mid].size() - 1]) {
            return find_array(mid + 1, upper, matrix, target);
        } else {
            return find_array(lower, mid - 1, matrix, target);
        }
    }

    int binary_search(int lower, int upper, vector<int>& nums, int target) {
        if (lower > upper) return -1;

        int mid = (lower + upper) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binary_search(mid + 1, upper, nums, target);
        } else {
            return binary_search(lower, mid - 1, nums, target);
        }        
    }

};

