/* 
*
* idea: create a map of frequency of each integer. Then, sort by frequency in linear time using buckets
*   
*   pseudocode:
*       
*   create frequency map
*   map each frequency map entry to its corresponding bucket
*   go through buckets in reverse order since we want most frequent to least frequent integers
*
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> solution;
        unordered_map<int, int> freq_map;

        // create a hashmap for frequency of each integer
        for (int num : nums) {
            freq_map[num]++;
        }

        // each index of the outer array represents a frequency (ex. buckets[3] contains all integers that appear 3 times)
        vector<vector<int>> buckets(nums.size() + 1);
        
        // mapping freq_map entries to the corresponding bucket
        for (auto& [number, freq] : freq_map) {
            buckets[freq].push_back(number);
        }

        // go through buckets in reverse order since we want most frequent to least frequent integers
        for (int i = buckets.size() - 1; i > 0; i--) {
            for (int num : buckets[i]) {
                solution.push_back(num);
                if (solution.size() == k) { 
                    // if the solution size is equal to k, we know we have k elements and can return a solution
                    return solution;
                }
            }
        }
        
        return solution;
    }
};
