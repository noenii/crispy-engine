class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        from heapq import merge
        sortedli = list(merge(nums1, nums2))
        mid = len(sortedli)//2
        if mid % 2 == 0:
            x, y = sortedli[mid - 1], sortedli[mid]
            z = float(x + y)
            return z/2
        else:
            return sortedli[mid]