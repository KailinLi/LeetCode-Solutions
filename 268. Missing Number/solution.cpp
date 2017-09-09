class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, x = 0;
        for_each(nums.begin(), nums.end(), [&](int n){
            x ^= i++ ^ n;
        });
        return x ^ i;
    }
};