class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        switch (nums.size()) {
            case 1:
                return to_string(nums[0]);
                break;
            case 2: {
                string answer;
                answer += to_string(nums[0]);
                answer += "/";
                answer += to_string(nums[1]);
                return answer;
            }
            default: {
                string answer;
                answer += to_string(nums[0]);
                answer += "/(";
                answer += to_string(nums[1]);
                for (int i = 2; i < nums.size(); i++) {
                    answer += "/";
                    answer += to_string(nums[i]);
                }
                answer += ")";
                return answer;
                break;
            }
        }
    }
};