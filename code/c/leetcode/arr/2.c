int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* ans=malloc(sizeof(int)*numsSize);
    for (int i = 0; i < n; ++i) {
        ans[2 * i]     = nums[i];
        ans[2 * i + 1] = nums[i + n];
    }
    *returnSize = numsSize;
    return ans;
}