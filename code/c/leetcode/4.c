double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int total=nums1Size+nums2Size;
    int mid=total/2;
    int i=0,j=0;
    int prev=0,cur=0;
    for(int k=0;k<=mid;k++){
        prev=cur;
        if(i<nums1Size&&(j>=nums2Size||nums1[i]<=nums2[j])){cur=nums1[i++];}
        else{cur=nums2[j++];}
    }
    if(total%2==0){
        return(prev+cur)/2.0;
    }
    return cur;
}