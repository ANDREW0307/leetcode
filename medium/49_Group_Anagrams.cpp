/*
  *
  *  idea: each string will have a character frequency table that matches only with anagrams of itself.
  *   Therefore, a hashmap can be used, where the key is the character frequency table and the value is the set of strings associated with that character frequency table (aka anagrams of each other)
  *
  * pseudocode:
  * 
  *   for each string in strings
  *     initialize frequency table
  *     for each character in the string
  *       add one to that character's entry in the frequency table
  *
  *     turn the frequency table into a key that can be used by the hashmap
  *     insert the current string into the set of strings that share the same key (the same character frequency table -> other anagrams)
  *     
  *     return all groups in the hashmap
  */



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;
        unordered_map<string, vector<string>> map;

        for (const string& curr_string : strs) {
            int frequency_table[26] = {0};
            for (char c : curr_string) {
                frequency_table[c - 'a']++; // offsetting each index by 'a' so that 'a' is at index 0, 'b' is at index 1, etc.
            }

            // creating a unique string (key) for each frequency table
            string key = "";
            for (int freq : frequency_table) {
                key += "#" + to_string(freq); // use "#" in between each string of the hash to avoid edge case conflicts
            }

            map[key].push_back(curr_string); // insert the current string into the set of its anagrams (other strings with the same key)
            
        }

        // insert the formed groups into the solution 2D array
        for (auto& [key, group] : map) {
            solution.push_back(group);
        }
        return solution;

    }
};
