//  LeetCode Problem No. 21: Find the Index of the First Occurrence in a String
int strStr(char* haystack, char* needle) {
    int hlen=strlen(haystack);
    int nlen=strlen(needle);
    if(nlen==0){return 0;}
    for(int i=0;i<=hlen-nlen;i++){
        char cur[nlen+1];
        strncpy(cur,haystack+i,nlen);
        cur[nlen]='\0';
        if(strcmp(cur,needle)==0){return i;}
    }
    return -1;
}