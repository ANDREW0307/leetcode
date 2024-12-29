/*

idea: use a hashing function and a hashmap to encode longUrl into a tinyUrl

*/

class Solution {
public:

    unordered_map<string, string> map;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        hash<string> hash_function;
        size_t hash_value = hash_function(longUrl);
        string shortUrl = "http://tinyurl.com/" + to_string(hash_value);

        map[shortUrl] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
