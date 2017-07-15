class Solution {
public:
    vector<vector<int>> res;
    void combination (vector<int> &v, int k, vector<int> &s) {
        int i = s.empty() ? 0 : s.back() + 1;
        while (i <= v.size() - k) {
            if (k == 1) {
                vector<int>list;
                for (int i = 0; i < s.size(); ++i) {
                    list.push_back(v[s[i]]);
                }
                list.push_back(v[i]);
                res.push_back(list);
            }
            else {
                s.push_back(i);
                combination(v, k - 1, s);
            }
            ++i;
        }
        if (!s.empty()) s.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.emplace_back(vector<int>{});
        vector<int>s;
        for (int i = 1; i <= nums.size(); ++i) {
            combination(nums, i, s);
        }
        return res;
    }
};