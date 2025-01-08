/*
    idea: remember that we need num to be equal to x in order for x to be considered achievable. since we want to maximize the value of x and we still need num and x to be equal, we should increment num while decremeneting x. since we can only do this operation t times, and each increment + decrement operation brings num and x 2 numbers closer to being equal to each other, num and x are at a maximum 2t units apart, meaning the maximum value of x is num + 2t
*/

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (2*t);
    }
};
