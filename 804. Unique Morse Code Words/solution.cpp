class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dic{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        for (auto s: words) {
            string tmp;
            for (auto c: s) {
                tmp += dic[c - 'a'];
            }
            res.insert(tmp);
        }
        return res.size();
    }
};