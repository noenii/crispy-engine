//  LeetCode Problem No. 1: Two Sum
/*      original solution
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                int* ret=malloc(sizeof(int)*2);
                ret[0]=i,ret[1]=j;
                *returnSize=2;
                return ret;
            }
        }
    }
    *returnSize=0;
    return NULL;
}
*/

// hash table implementation
#define HASH_SIZE 10007

typedef struct node{
    int key;
    int index;
    struct node* next;
} node;

int hash(int key){
    return abs(key)%HASH_SIZE;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    node* table[HASH_SIZE] = {0};
    for(int i=0;i<numsSize;i++){
        int temp=target-nums[i];
        int h=hash(temp);
        node* cur=table[h];
        while(cur){
            if(cur->key==temp) {
                int* result=malloc(sizeof(int)*2);
                result[0]=cur->index;
                result[1]=i;
                *returnSize=2;
                return result;
            }
            cur=cur->next;
        }
        h = hash(nums[i]);
        node* new=malloc(sizeof(node));
        new->key=nums[i];
        new->index=i;
        new->next=table[h];
        table[h]=new;
    }
    *returnSize=0;
    return NULL;
}