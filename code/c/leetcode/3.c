int lengthOfLongestSubstring(char* s) {
    int freq[256]={0};
    int left=0;
    int maxLen=0;
    for(int right=0;s[right]!='\0';right++){
        freq[(unsigned char)s[right]]++;
        while(freq[(unsigned char)s[right]]>1){freq[(unsigned char)s[left]]--; left++;}
        int currLen=right-left+1;
        if(currLen>maxLen){maxLen = currLen;}
    }
    return maxLen;
}