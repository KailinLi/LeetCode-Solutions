/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger get;
        if (s.size() == 0) return get;
        int index = 0;
        int left = 0;
        string tmp;
        while (index < s.size()) {
            switch (s[index]) {
                case '[':
                    if (index == 0) {
                        left++;
                        index++;
                        continue;
                    }
                    else {
                        int tmp = left + 1;
                        int tmpIndex = index;
                        while (tmp != left) {
                            if (s[++tmpIndex] == '[') {
                                tmp++;
                            }
                            else if (s[tmpIndex] == ']') {
                                tmp--;
                            }
                        }
                        get.add(deserialize(s.substr(index, tmpIndex - index + 1)));
                        index = tmpIndex + 1;
                    }
                    break;
                case ']':
                    if (s[index - 1] != ']') {
                        if (s[index - 1] == '[') {
                            index ++;
                            continue;
                        }
                        NestedInteger number(stoi(tmp));
                        if (get.isInteger()) {
                            get = number;
                        }
                        else {
                            get.add(number);
                        }
                        tmp.clear();
                    }
                    return get;
                    break;
                case ',':
                    if (s[index - 1] != ']') {
                        NestedInteger number(stoi(tmp));
                        if (get.isInteger()) {
                            get = number;
                        }
                        else {
                            get.add(number);
                        }
                        tmp.clear();
                    }
                    break;
                default:
                    tmp.push_back(s[index]);
                    break;
            }
            index++;
        }
        if (left == 0) {
            NestedInteger number(stoi(tmp));
            get = number;
        }
        return get;
    }
};