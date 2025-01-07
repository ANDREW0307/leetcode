/*
    idea: go through each character (besides the last character to avoid an out of bounds error) and finthe absolute difference of the difference between the ascii values (no need to convert char to int in C++)
*/

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            sum += abs(s[i] - s[i + 1]);
        }   
        return sum;
    }
};
