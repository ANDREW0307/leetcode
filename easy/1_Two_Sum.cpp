class Solution {
  
  public:

    /*
  * idea: check if complement of each element exists (complement = target - element). if the complement exists in the map for a certain element, we know that element + its complement = target
  * 
  * pseudocode: 
  *
  * for each element in nums:
  *   complement = target - element
  *   if complement is in map
  *     return indices of element and complement
  *   else 
  *     add new entry to map for the current element (key = element, value = index of element)
  *
  */

  
    vector<int> twoSum(vector<int>& nums, int target) {
      std::unordered_map<int, int> map;
      std::vector<int> solution;
      
      for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) { // if the complement exists in map
          solution.push_back(i); // add the current index to the solution
          solution.push_back(map[complement]); // add the complement index to the solution, note: it's specified that answers can be returned in any order
          return solution; // return solution early to avoid extra iteration
        } else {
          map[nums[i]] = i;
        }
      }
      return solution;
  }

};
