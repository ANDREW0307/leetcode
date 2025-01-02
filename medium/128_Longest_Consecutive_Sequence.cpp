/*

    for each possible start of a sequuence, see how long that sequence can go. keep a global maximum encountered sequence length variable to cmopare to. To check if an integer is the start of a sequence, check if there exists an integer that is one less than it. If so, that integer can't be at the start of the sequence (since there must be at least one integer in the sequence that comes before it).

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> set(nums.begin(), nums.end()); // copy the array into the set

        int longest_seq_streak = 0;

        // search through the set rather than the original array in order to reduce iterations
        for (int num : set) {
            // we know this is the start of a possible longest sequence, begin building the sequence
            if (set.find(num - 1) == set.end()) {
                int curr_streak = 1;
                while (set.find(num + curr_streak) != set.end()) {
                    curr_streak++;
                }
                longest_seq_streak = max(longest_seq_streak, curr_streak);
            }
        }       
        return longest_seq_streak; 
    }
};

