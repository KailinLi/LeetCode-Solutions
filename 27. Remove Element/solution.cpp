class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sum = 0;
        for (auto n = nums.begin(); n < nums.end(); n++) {
            if (*n != val) sum++;
            else {
                nums.erase(n);
                n--;
            }
        }
        return sum;
    }
};