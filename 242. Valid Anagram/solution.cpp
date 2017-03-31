class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> bucket(26, 0);
        for (auto c : s) {
            bucket[c - 97]++;
        }
        for (auto c : t) {
            bucket[c - 97]--;
        }
        for (auto item : bucket) {
            if (item != 0) return false;
        }
        return true;
    }
};