char* convert(char* s, int numRows) {
    if(numRows==1){return s;}
    int l=strlen(s);
    char* res=malloc(l+1);
    int inc=(numRows-1)*2;
    int tmp=0;
    for(int i=0;i<numRows;i++){
        for(int j=i;j<l;j+=inc){
            res[tmp++]=s[j];
            int diag=j+inc-2*i;
            if(i>0&&i<numRows-1&&diag<l){res[tmp++]=s[diag];}
        }
    }
    res[tmp]='\0';
    return res;
}