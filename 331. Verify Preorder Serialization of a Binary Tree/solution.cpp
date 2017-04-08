class Solution {
private:
    vector<int>stack;
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return false;
        }
        int index = 1;
        preorder += ",";
        if (preorder[0] == '#') {
            if (preorder.size() == 2) return true;
            else return false;
        }
        else {
            while (preorder[index] != ',') {
                index++;
            }
            stack.push_back(0);
            index++;
        }
        for (; index < preorder.size(); index++) {
            switch (preorder[index]) {
                case ',':
                    if (stack.empty()) {
                        return false;
                    }
                    else {
                        stack.back()++;
                        if (stack.back() == 2) {
                            stack.pop_back();
                        }
                    }
                    stack.push_back(0);
                    break;
                case '#':
                    index++;
                    if (stack.empty()) {
                        return false;
                    }
                    else {
                        stack.back()++;
                        if (stack.back() == 2) {
                            stack.pop_back();
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        return stack.empty();
    }
};