class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long m = (long long)(numerator < 0 ? -(long long)numerator : numerator);
        long long n = (long long)(denominator < 0 ? -(long long)denominator : denominator);

        res += to_string(m / n);
        long long d = m % n;
        if (!d) return res;

        res += ".";
        map<long long, int> r;
        r[d] = res.size();
        while (d) {
            d *= 10;
            res += to_string(d / n);
            d %= n;
            map<long long, int>::iterator f = r.find(d);
            if (f == r.end()) r[d] = res.size();
            else {
                res.insert(res.begin() + f->second, '(');
                res += ")";
                break;
            }
        }
        return res;
    }
};