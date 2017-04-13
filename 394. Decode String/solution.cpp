class Solution {
public:
    string decodeString(string s) {
        string answer;
        if (s.empty()) {
            return answer;
        }
        string time;
        int getTime = 0;
        int index = 0;
        while (index < s.size()) {
            switch (s[index]) {
                case '[': {
                    getTime = stoi(time);
                    time.clear();
                    int nextIndex = index;
                    int count = 1;
                    while (count != 0) {
                        if (s[++nextIndex] == '[') {
                            count++;
                        }
                        else if (s[nextIndex] == ']') {
                            count--;
                        }
                    }
                    if (nextIndex == index + 1) {
                        index++;
                        continue;
                    }
                    string repeat = decodeString(s.substr(index + 1, nextIndex - index - 1));
                    index = nextIndex;
                    while (getTime > 0) {
                        answer += repeat;
                        getTime--;
                    }
                    break;
                }
                case ']':
                    break;
                default:
                    if (isdigit(s[index])) {
                        time.push_back(s[index]);
                    }
                    else {
                        answer.push_back(s[index]);
                    }
                    break;
            }
            index++;
        }
        return answer;
    }
};