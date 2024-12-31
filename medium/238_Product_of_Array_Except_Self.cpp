/*

idea: for each element, we can split the product we want into two sides: the total product of integers before that element (prefix / left product) and the total product of integers after that element (suffix / right product). After obtaining the products for the left and right sides, we can store them in previous entries and call upon them later to save computations. Then we can create a new array where each element is the product of the left and right sides, which leaves out that element.

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> solution(nums.size(), 1);
        vector<int> prefix_products(nums.size(), 1);
        vector<int> suffix_products(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            prefix_products[i] = prefix_products[i - 1] * nums[i - 1];
        }

        for (int j = nums.size() - 2; j >= 0; j--) {
            suffix_products[j] = suffix_products[j + 1] * nums[j + 1];
        }
     
        for (int i = 0; i < prefix_products.size(); i++) {
            solution[i] = prefix_products[i] * suffix_products[i];
        }

        return solution;
    }
};
