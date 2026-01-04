int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    long long n=numsSize;
    long long a=n*(n+1)/2;
    long long b=n*(n+1)*(2*n+1)/6;
    long long c=0,d=0;
    for (int i=0;i<numsSize;i++){c+=nums[i]; d+=(long long)nums[i]*nums[i];}
    long long e=a-c;
    long long f=b-d;
    long long g=f/e;
    int missing=(e+g)/2;
    int duplicate=missing-e;
    int* res=(int*)malloc(sizeof(int)*2);
    res[0]=duplicate;
    res[1]=missing;
    *returnSize=2;
    return res;
}