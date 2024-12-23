class Solution {
  public:
  

  /*
  * idea: since the string can be in any order, check for the frequency of each character in bothstrings, then compare the frequencies of each character. if they match, then the strings are anagrams, otherwise they are not
  *
  * pseudocode
  *
  * check for edge cases
  *
  * map s_freq
  * map t_freq
  *
  * from index 0 to index len(s) - 1:
  *   s_freq[character]++
  *   t_freq[character]++
  *
  * if key/values of s_freq == key/values of t_freq
  *   return true
  * else 
  *   return false
  *
  */


  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false; // checking for edge cases since the problem specifies that t could be a different length than s
  
    std::unordered_map<char, int> s_char_freq; // keys are the characters of s, values are the number of times that character appears in s
    std::unordered_map<char, int> t_char_freq;

    for (int i = 0; i < s.length(); i++) {
      s_char_freq[s[i]]++; // for each character we go through, we add one to the frequency of that character since it has appeared one more time
      t_char_freq[t[i]]++; 
    }

    return s_char_freq == t_char_freq; // you can check for the equality of two unordered_map using ==, checks all keys in both maps to make sure they exist in one another and that their corresponding values match
  }
};
