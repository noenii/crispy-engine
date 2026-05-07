//  LeetCode Problem No. 13: Integer to Roman
char* intToRoman(int num) {
    int nums[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const char *symbols[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char *res=calloc(16,sizeof(char));
    int cur=0;
    for(int i=0;i<13;i++){
        while(num>=nums[i]){
            int len=strlen(symbols[i]);
            memcpy(res+cur,symbols[i],len);
            cur+=len;
            num-=nums[i];
        }
    }
    res[cur]='\0';
    return res;
}