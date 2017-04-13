class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int>stack;
        vector<int>answer;
        vector<pair<int, int>>dic;
        for (auto num : nums) {
            while (!stack.empty() && stack.top() < num) {
                int key = stack.top();
                dic.push_back(make_pair(key, num));
                stack.pop();
            }
            stack.push(num);
        }
        for (auto key : findNums) {
            answer.push_back((*this).find(dic, key));
        }
        return answer;
    }
    int find(vector<pair<int, int>>& nums, int key) {
        for (auto pair : nums) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }
};