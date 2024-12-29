/*
idea: have a pointer at the beginning of the string and at the end of the string. since a palindrome has to match forwards and backwards, iterating forwards and backwards at the same time can be used to check for equality at each character at both pointers. To deal with non alphanumeric characters, we can create a new string but only add alphanumerical characters by checking with std::isalnum(char c).
*/

class Solution {
public:
    bool isPalindrome(string s) {

        string new_string = "";
        for (char c : s) {
            if (isalnum(c)) {
                new_string += tolower(c); // use tolower() because A = a, B = b, etc. in this case
            }
        }

        int start_pointer = 0;
        int end_pointer = new_string.size() - 1;

        // can divide new_string.size() by 2 to avoid extra comparisons
        for (int i = 0; i < new_string.size() / 2; i++) {
            if (new_string[start_pointer] != new_string[end_pointer]) {
                return false;
            }
            start_pointer++;
            end_pointer--;
        }
        return true;
    }
};
