class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for (auto s : ops) {
            if (s == "C") score.pop_back();
            else if (s == "D") {
                score.push_back(score.back() * 2);
            }
            else if (s == "+") {
                score.push_back(score.back() + score[score.size() - 2]);
            }
            else {
                score.push_back(stoi(s));
            }
        }
        int res = 0;
        for (auto i : score) {
            res += i;
        }
        return res;
    }
};