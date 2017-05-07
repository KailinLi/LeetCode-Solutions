class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        vector<int>sister;
        for (auto c = candies.begin(); c != candies.end() && sister.size() < candies.size()/2; ++c) {
            auto input = find(sister.begin(), sister.end(), *c);
            if (input == sister.end()) sister.push_back(*c);
        }
        return (int)sister.size();
    }
};