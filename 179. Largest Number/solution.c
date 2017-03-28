int length (int number) {
    if (number == 0) {
        return 1;
    }
    int length = 0;
    while (number != 0) {
        number /= 10;
        length++;
    }
    return length;
}
int getMax (int number) {
    while (number > 9) {
        number /= 10;
    }
    return number;
}
int cmp (const void *fisrt, const void *second) {
    int getFirst = *(int*) fisrt;
    int getSecond= *(int*) second;
    int lf = length(getFirst);
    int ls = length(getSecond);
    int min = lf - ls;
    int modFirst = 0, modSecond = 0;
    int left = 0;
    int save = min;
    if (min > 0) {
        while (min != 0) {
            modFirst = getFirst % 10;
            left += modFirst * powf(10, (save - min)) ;
            getFirst /= 10;
            min--;
        }
        if (getFirst == getSecond) {
            if (modFirst == 0 && left != 0) {
                return 1;
            }
            return cmp(&left, &getSecond);
        }
    }
    else if (min < 0) {
        while (min != 0) {
            modSecond = getSecond % 10;
            left += modSecond * powf(10, (min - save));
            getSecond /= 10;
            min++;
        }
        if (getFirst == getSecond) {
            if (modSecond == 0 && left != 0) {
                return -1;
            }
            return cmp(&getFirst, &left);
        }
    }
    return getSecond - getFirst;
}
char answer[100] = {};
char* largestNumber(int* nums, int numsSize) {
    *answer = 0;
    if (numsSize == 0) {
        return answer;
    }
    int jud = 1;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i ++) {
        if (jud != 1 && nums[0] == 0) {
            continue;
        }
        char buffer[20];
        snprintf(buffer, 20, "%d", nums[i]);
        strcat(answer, buffer);
        jud = 0;
    }
    return answer;
}