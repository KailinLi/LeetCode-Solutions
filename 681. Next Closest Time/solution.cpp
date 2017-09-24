class Solution {
    int firstH, firstM;
    int later (int secondH, int secondM) {
        if (firstH == secondH && firstM == secondM) return 24 * 60;
        if (secondH > 23 || secondM > 59) return INT_MAX;
        if (secondH < firstH || (secondH == firstH && secondM < firstM)) secondH += 24;
        return (secondH - firstH) * 60 + (secondM - firstM);
    }
public:
    string nextClosestTime(string time) {
        set<char> nums;
        nums.insert(time[0]);
        nums.insert(time[1]);
        nums.insert(time[3]);
        nums.insert(time[4]);
        int minLate = INT_MAX;
        firstH = stoi(time.substr(0, 2)), firstM = stoi(time.substr(3, 2));
        string secondH = time.substr(0, 2), secondM = time.substr(3, 2);
        string bestH, bestM;
        for (auto t1 : nums) {
            secondM[1] = t1;
            int tmp = later(stoi(secondH), stoi(secondM));
            if (tmp < minLate) {
                minLate = tmp;
                bestH = secondH;
                bestM = secondM;
            }
            for (auto t2 : nums) {
                secondM[0] = t2;
                int tmp = later(stoi(secondH), stoi(secondM));
                if (tmp < minLate) {
                    minLate = tmp;
                    bestH = secondH;
                    bestM = secondM;
                }
                for (auto t3 : nums) {
                    secondH[1] = t3;
                    int tmp = later(stoi(secondH), stoi(secondM));
                    if (tmp < minLate) {
                        minLate = tmp;
                        bestH = secondH;
                        bestM = secondM;
                    }
                    for (auto t4 : nums) {
                        secondH[0] = t4;
                        int tmp = later(stoi(secondH), stoi(secondM));
                        if (tmp < minLate) {
                            minLate = tmp;
                            bestH = secondH;
                            bestM = secondM;
                        }
                    }
                }
            }
        }
        return bestH + ":" + bestM;
    }
};