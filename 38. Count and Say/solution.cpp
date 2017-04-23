class Solution {
public:
    string countAndSay(int n) {
        string say = "1";
        string answer = "1";
        while (n > 1) {
            int count = 0;
            char current = say[0];
            answer.erase();
            for (auto c : say) {
                if (c == current) {
                    count++;
                }
                else {
                    answer += to_string(count);
                    answer.push_back(current);
                    current = c;
                    count = 1;
                }
            }
            answer += to_string(count);
            answer.push_back(current);
            say = answer;
            n--;
        }
        return answer;
    }
};