

/*
* idea: iterate through array, for each integer, check if it is in the set, otherwise log it in the set
*
* 
* pseudocode
*
* for each integer in nums:
*   if set contains integer, return true
*   else insert the integer in the set
* return false
*/

class Solution {

public: 
  bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> visited;
    for (int i = 0; i < nums.size(); i++) {
      if (visited.count(nums[i]) == 1) {
        return true;
      }
      visited.insert(nums[i]);
    }
    return false;
  }
};
