/*

idea: for encoding, use a hash function to turn each string in the array into a unique value.
also use a delimiting character to indicate when that hash is over (this will prevent the formation of one long hash)

for decoding, create a string from each character in the hash until the delimitng chracter is hit, meaning we have one original word.
Then add it to the solution array.

*/

class Solution {
public:

    unordered_map<size_t, string> map;
    hash<string> hash_function; // std::hash

    string encode(vector<string>& strs) {
        string encoded_string = "";
        size_t hash_value; // size_t is the return type of std::hash
        for (const string& s : strs) {
            hash_value = hash_function(s);
            map[hash_value] = s;
            encoded_string += to_string(hash_value) + '_'; // "delimiting character"
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        string new_string = ""; // temporary string
        for (char c : s) {
            if (c != '_') {
                new_string += c; // if the character isn't a delimiter, we know it's part of the current string
            } else {
                size_t hash_value = stoull(new_string); 
                decoded_strings.push_back(map[hash_value]);
                new_string = ""; // reset temporary string for the next hash value
            }
        }
        return decoded_strings;
    }
};

