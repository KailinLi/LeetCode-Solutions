void sortColors(int* nums, int numsSize) {
    int red = 0, white = 0, blue = 0;
    for (int* p = nums; p < nums + numsSize; p++) {
        switch (*p) {
            case 0:
                red++;
                break;
            case 1:
                white++;
                break;
            case 2:
                blue++;
                break;
            default:
                break;
        }
    }
    int *p = nums;
    for (; p < nums + red; p++) {
        *p = 0;
    }
    for (; p < nums + red + white; p++) {
        *p = 1;
    }
    for (; p < nums + blue + red + white; p++) {
        *p = 2;
    }
}