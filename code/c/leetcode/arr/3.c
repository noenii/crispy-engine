int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int res=0,count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==1){count++; if(count>res){res=count;}}
        else{count=0;}
    }
    return res;
}