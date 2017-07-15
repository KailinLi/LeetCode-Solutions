class Solution {
private:
    bool similar(string& a, string& b) {
        int count = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++count;
            if (count > 1) break;
        }
        return (count == 1) ? true : false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool>notVisited(wordList.size(), true);
        int layer = 0;
        queue<size_t>q;
        for (size_t i = 0; i < wordList.size(); ++i) {
            if (similar(beginWord, wordList[i])) {
                q.push(i);
                notVisited[i] = false;
            }
        }
        while (!q.empty()) {
            ++layer;
            size_t size = q.size();
            while (size--) {
                size_t tmp = q.front();
                q.pop();
                if (wordList[tmp] == endWord) return layer + 1;
                for (size_t i = 0; i < wordList.size(); ++i) {
                    if (notVisited[i] && similar(wordList[i], wordList[tmp])) {
                        notVisited[i] = false;
                        q.push(i);
                    }
                }
            }
        }
        return 0;
    }
};