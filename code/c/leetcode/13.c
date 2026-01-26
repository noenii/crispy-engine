int romanToInt(char* s) {
    int slen=strlen(s);
    if(!slen){return 0;}
    int ret=0;
    int numerals[256]={0};
    numerals[73]=1,numerals[86]=5,numerals[88]=10,numerals[76]=50,numerals[67]=100,numerals[68]=500,numerals[77]=1000;
    if(slen==1){return numerals[s[0]];}
    for(int i=0;i<slen-1;i++){
        if(numerals[s[i]]>=numerals[s[i+1]]){ret+=numerals[s[i]];}
        else{ret-=numerals[s[i]];}
    }
    ret+=numerals[s[slen-1]];
    return ret;
}