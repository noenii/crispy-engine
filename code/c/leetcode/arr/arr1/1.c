//  LeetCode Array I - Q1: Concatenation of Array
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int n=numsSize*2;
    int* ptr=malloc(sizeof(int)*n);
    for(int i=0;i<numsSize;i++){
        ptr[i]=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        ptr[i+numsSize]=nums[i];
    }
    *returnSize=n;
    return ptr;
}