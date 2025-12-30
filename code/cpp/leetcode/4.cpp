class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        result.reserve(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(result));
        return(result.size()%2==0)?(result[(result.size()/2)-1]+result[result.size()/2])/2.0:result[result.size()/2];
    }
};