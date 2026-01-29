//  LeetCode Array II - Q1: Set Mismatch
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    long long a=0;
    long long b=0;
    for(int i=0;i<numsSize;i++){a+=nums[i]; b+=(long long)nums[i]*nums[i];}
    long long c=(long long)numsSize*(numsSize+1)/2;
    long long d=(long long)numsSize*(numsSize+1)*(2*numsSize+1)/6;
    long long e=a-c;
    long long f=(b-d)/e;
    int x=(int)((e+f)/2);
    int y=(int)(x-e);
    int* ret=(int*)malloc(sizeof(int)*2);
    ret[0]=x;
    ret[1]=y;
    *returnSize=2;
    return ret;
}