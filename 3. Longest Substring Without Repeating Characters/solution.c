int find(char* s, char c, long l) {
    for (int i = 0; i < l; i ++) {
        if (*(s + i) == c) {
            return i;
        }
    }
    return -1;
}
int lengthOfLongestSubstring(char* s) {
    if (*s == '\0') {
        return 0;
    }
    char *pf = s, *ef = s + 1;
    int max = 1;
    for (; *ef != '\0'; ef++) {
        int getI = find(pf, *ef, ef - pf);
        if (getI == -1) {
            int get = (int)(ef - pf) + 1;
            max = max > get ? max : get;
            continue;
        }
        else {
            pf += getI + 1;
        }
    }
    return max;
}