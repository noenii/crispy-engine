class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1||numRows>=s.size()){return s;}
        int l=s.size();
        string res;
        res.reserve(l);
        int inc=(numRows-1)*2;
        for(int i=0;i<numRows;i++){
            for (int j=i;j<l;j+=inc){
                res.push_back(s[j]);
                int diag=j+inc-2*i;
                if(i>0&&i<numRows-1&&diag<l){res.push_back(s[diag]);}
            }
        }
        return res;
    }
};