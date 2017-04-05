class Solution {
public:
    string simplifyPath(string path) {
        vector<string>answer;
        string tmp = "";
        int point = 0;
        for (auto c : path) {
            switch (c) {
                case '/':
                    if (!tmp.empty()) {
                        answer.push_back(tmp);
                        tmp = "";
                    }
                    else {
                        if (point == 2) {
                            if (!answer.empty()) {
                                answer.pop_back();
                            }
                        }
                        else if (point > 2) {
                            if (tmp.empty()) {
                                answer.push_back(string(point, '.'));
                            }
                            else {
                                tmp.push_back('.');
                            }
                        }
                        point = 0;
                    }
                    break;
                case '.':
                    if (tmp.empty()) point++;
                    else tmp.push_back(c);
                    break;
                default:
                    if (point != 0) {
                        tmp += string(point, '.');
                        point = 0;
                    }
                    tmp.push_back(c);
                    break;
            }
        }
        if (!tmp.empty()) answer.push_back(tmp);
        if (point > 2) {
            tmp += string(point, '.');
            answer.push_back(tmp);
        }
        else if (point == 2) {
            if (!answer.empty()) answer.pop_back();
        }
        tmp = "";
        if (answer.size() == 0) return "/";
        for (auto s : answer) {
            tmp += "/";
            tmp += s;
        }
        return tmp;
    }
};