using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>indexByValue;
        for(int i=0;i<nums.size();i++){
            int tmp=target-nums[i];
            auto ts=indexByValue.find(tmp);
            if(ts!=indexByValue.end()){return{ts->second,i};}
            indexByValue[nums[i]]=i;
        }
        return{};
    }
};