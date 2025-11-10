class Solution(object):
    def twoSum(self, nums, target):
        for index, outer in enumerate(nums):
            for index1, inner in enumerate(nums):
                if index1 == index:
                    continue
                if outer + inner == target:
                    return index, index1