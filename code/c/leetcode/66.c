//  LeetCode Problem No. 66: Plus One
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* res=malloc(sizeof(int)*(digitsSize+1));
    int carry=1;
    for(int i=digitsSize-1;i>=0;i--){int sum=digits[i]+carry; res[i+1]=sum%10; carry=sum/10;}
    if(carry){res[0]=1; *returnSize=digitsSize+1; return res;}
    *returnSize=digitsSize;
    return res+1;
}