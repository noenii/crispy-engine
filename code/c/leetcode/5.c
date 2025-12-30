char* longestPalindrome(char* s) {
    if(!s||s[0]=='\0'){
        char* empty=malloc(1);
        empty[0]='\0';
        return empty;
    }
    int n=strlen(s);
    int t_len=2*n+1;
    int* P=calloc(t_len,sizeof(int));
    if(!P){return NULL;}
    int center=0,right=0;
    int max_len=0,center_index=0;
    for(int i=0;i<t_len;i++){
        int mirror=2*center-i;
        if(i<right){P[i]=(right-i<P[mirror])?right-i:P[mirror];}
        while(1){
            int left=i-P[i]-1;
            int right_i=i+P[i]+1;
            int l_char=left/2;
            int r_char=right_i/2;
            if(left<0||right_i>=t_len){break;}
            if(left%2==0||right_i%2==0){}
            else if(s[l_char]!=s[r_char]){break;}
            P[i]++;
        }
        if(i+P[i]>right){
            center=i;
            right=i+P[i];
        }
        if(P[i]>max_len){max_len=P[i]; center_index=i;}
    }
    int start=(center_index - max_len)/2;
    char* result=malloc(max_len + 1);
    if(!result){free(P); return NULL;}
    strncpy(result,s+start,max_len);
    result[max_len]='\0';
    free(P);
    return result;
}