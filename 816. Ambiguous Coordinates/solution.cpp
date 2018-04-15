class Solution {
public:
    bool ok(string &S, int begin, int length, int bp) {
        if (length == bp) {
            if (S[begin] == '0'  && length > 1) return false;
            else return true;
        }
        else if (S[begin] == '0' && bp == 1 && S[begin + length - 1] != '0') return true;
        else if (S[begin] == '0' && bp > 1) return false;
        else if (S[begin + length - 1] == '0') return false;
        else return true;
    }
    vector<string> ambiguousCoordinates(string S) {
        S.erase(0, 1);
        S.erase(S.size() - 1, 1);
        vector<string> res;
        for (int cp = 1; cp < S.size(); ++cp) {
            for (int bp = 1; bp <= cp; ++bp) {
                if (ok(S, 0, cp, bp)) {
                    cout << bp << endl;
                    for (int pp = 1; pp <= S.size() - cp; ++pp) {
                        if (ok(S, cp, S.size() - cp, pp)) {
                            string tmp = "(";
                            for (int i = 0; i < cp; ++i) {
                                if (bp == i) tmp += ".";
                                tmp += S[i];
                            }
                            tmp += ",";
                            tmp += " ";
                            for (int i = cp; i < S.size(); ++i) {
                                if (pp + cp == i) tmp += '.';
                                tmp += S[i];
                            }
                            tmp += ')';
                            res.push_back(tmp);
                        }
                    }
                }
            }
        }
        return res;
    }
};