class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        from heapq import merge
        import numpy
        sortedli = numpy.array(list(heapq.merge(nums1, nums2)))
        return numpy.median(sortedli)