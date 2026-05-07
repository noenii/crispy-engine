//  LeetCode Array II - Q3: Find All Numbers Disappeared in an Array
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for(int n=0;n<numsSize;n++){
        int i=abs(nums[n])-1;
        nums[i]=-abs(nums[i]);
    }
    int* res=calloc(sizeof(int),numsSize);
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]>0){res[count]=i+1; count++;}
    }
    *returnSize=count;
    return res;
}