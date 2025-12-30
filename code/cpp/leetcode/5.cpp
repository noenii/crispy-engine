class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){return "";}
        string t;
        t.reserve(2*s.size()+3);
        t.push_back('^');
        for(char c:s) {
            t.push_back('#');
            t.push_back(c);
        }
        t.push_back('#');
        t.push_back('$');
        vector<int> P(t.size(),0);
        int center=0,right=0;
        int maxLen=0,centerIdx=0;
        for(int i=1;i<t.size()-1;i++){
            int mirror=2*center-i;
            if(i<right){P[i]=min(right-i,P[mirror]);}
            while(t[i+P[i]+1]==t[i-P[i]-1]){++P[i];}
            if(i+P[i]>right){center=i; right=i+P[i];}
            if(P[i]>maxLen){maxLen=P[i]; centerIdx=i;}
        }
        int start=(centerIdx-maxLen)/2;
        return s.substr(start,maxLen);
    }
};