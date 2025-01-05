/*
    idea: use binary search to select the minimum rate at which you can eat bananas
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search between 1 and the largest number in the pile
        return binary_search_speed(1, *max_element(piles.begin(), piles.end()), piles, h);
    }

    int binary_search_speed(int lower, int upper, vector<int>& piles, int h) {
        if (lower >= upper) return lower;

        int rate = (lower + upper) / 2;

        // if this rate works, see if lower ones work
        if (check_rate(rate, piles, h) == true) {
            return binary_search_speed(lower, rate, piles, h);
        } else {
            return binary_search_speed(rate + 1, upper, piles, h);
        }
    }

    bool check_rate(int rate, vector<int>& piles, int h) {
        int total_hours = 0;
        for (int num : piles) {
            total_hours += ceil(1.0 * num / rate);
        }
        if (total_hours <= h) {
            return true;
        } else {
            return false;
        }
    }
};

