/*
    idea: use two loops, in the second loop, use i + nums.size() to fill the second half of the solution array
*/


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> concatenation(2 * nums.size());
        for (int i = 0; i < nums.size(); i++) {
            concatenation[i] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            concatenation[i + nums.size()] = nums[i];
        }
        return concatenation;
    }
};
