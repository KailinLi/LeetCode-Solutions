bool cmp (int &one, int &two) {
    return one > two;
}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) {
            return 0;
        }
        sort(citations.begin(), citations.end(), cmp);
        if (citations[citations.size() - 1] >= citations.size()) {
            return citations.size();
        }
        for (int index = 0; index < citations.size(); index++) {
            if (citations[index] <= index) {
                return index;
            }
        }
        return 0;
    }
};