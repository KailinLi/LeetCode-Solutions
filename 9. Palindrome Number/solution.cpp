class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) {
            return false;
        }
        int number = 0;
        while (x > number) {
            number = number * 10 + x % 10;
            x /= 10;
        }
        return (x == number) || (x == number / 10);
    }
};