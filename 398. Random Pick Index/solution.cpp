class Solution {
private:
    vector<int> myNums;
public:
    Solution(vector<int> nums) {
        myNums = nums;
    }
    
    int pick(int target) {
        int count = 1;
        int res = 0;
        for (int i = 0; i < myNums.size(); ++i) {
            if (myNums[i] == target) {
                if (!(rand() % count)) res = i;
                ++count;
            }    
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */