//  LeetCode Array II - Q2: How Many Numbers Are Smaller Than the Current Number
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    if(!nums){return NULL;}
    int freq[101]={0};
    for(int i=0;i<numsSize;i++){freq[nums[i]]++;}
    for(int i=1;i<=100;i++){freq[i]+=freq[i-1];}
    int* ret=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){ret[i]=0;}
        else{ret[i]=freq[nums[i]-1];}
    }
    return ret;
}