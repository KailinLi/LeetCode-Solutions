/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    for (int *p = nums; p < nums + numsSize; p ++) {
        int minus = target - *p;
        for (int *nextP = p + 1; nextP < nums + numsSize; nextP ++) {
            if (*nextP == minus) {
                int *answer = malloc(sizeof(int) * 2);
                *(answer) = (int)(p - nums);
                *(answer + 1) = (int)(nextP - nums);
                return answer;
            }
        }
    }
    return NULL;
}