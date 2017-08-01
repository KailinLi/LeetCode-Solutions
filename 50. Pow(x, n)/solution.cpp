class Solution {
private:
    double helpPow(double x, long n) {
        if (!n) return 1;
        if (n < 0) return 1.0 / helpPow(x, -n);
        if (n % 2) return x * pow(helpPow(x, n >> 1), 2);
        else return pow(helpPow(x, n >> 1), 2);
    }
public:
    double myPow(double x, int n) {
        return helpPow(x, static_cast<long>(n));
    }
};