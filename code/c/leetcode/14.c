//  LeetCode Problem No. 14: Longest Common Prefix
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0){return "";}
    if(strsSize==1){return strs[0];}
    int shortest=strlen(strs[0]);
    for(int i=1;i<strsSize;i++){
        int len=strlen(strs[i]);
        if(len<shortest){shortest=len;}
    }
    int i;
    int mismatch=0;
    for(i=0;i<shortest;i++){
        char cur=strs[0][i];
        for(int j=1;j<strsSize;j++){if(strs[j][i]!=cur){mismatch=1; break;}}
        if(mismatch){break;}
    }
    char* res=malloc(sizeof(char)*(i+1));
    memcpy(res,strs[0],i);
    res[i]='\0';
    return res;
}