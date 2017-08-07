class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        (*this).nums.push_back(0);
        for (auto i : nums) {
            (*this).nums.push_back(sum += i);
        }
    }
    
    int sumRange(int i, int j) {
        return nums[j + 1] - nums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */