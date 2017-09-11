class Solution {
public:
    int calculate(string s) {
        size_t index = 0;
        vector<string> nums;
        stack<string> opt;
        while (index < s.size()) {
            while (s[index] == ' ') {
                ++index;
            }
            if (!isdigit(s[index])) {
                switch (s[index]) {
                    case '+': case '-':
                        while (!opt.empty()) {
                            nums.push_back(opt.top());
                            opt.pop();
                        }
                        opt.push(string(1, s[index]));
                        break;
                    case '*': case '/':
                        while (!opt.empty() && !(opt.top() == "+" || opt.top() == "-")) {
                            nums.push_back(opt.top());
                            opt.pop();
                        }
                        opt.push(string(1, s[index]));
                        break;
                }
                ++index;
                continue;
            }
            string number;
            while (isdigit(s[index])) {
                number += s[index];
                ++index;
            }
            nums.push_back(number);
        }
        while (!opt.empty()) {
            nums.push_back(opt.top());
            opt.pop();
        }
        stack<int> res;
        for (size_t i = 0; i < nums.size(); ++i) {
            int num1, num2;
            if (nums[i] == "*") {
                num1 = res.top();
                res.pop();
                num2 = res.top();
                res.pop();
                res.push(num2 * num1);
            }
            else if (nums[i] == "/") {
                num1 = res.top();
                res.pop();
                num2 = res.top();
                res.pop();
                res.push(num2 / num1);
            }
            else if (nums[i] == "+") {
                num1 = res.top();
                res.pop();
                num2 = res.top();
                res.pop();
                res.push(num2 + num1);
            }
            else if (nums[i] == "-") {
                num1 = res.top();
                res.pop();
                num2 = res.top();
                res.pop();
                res.push(num2 - num1);
            }
            else {
                res.push(stoi(nums[i]));
            }
        }
        return res.top();
    }
};