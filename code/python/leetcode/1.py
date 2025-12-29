class Solution(object):
    def twoSum(self, nums, target):
        for ind, outer in enumerate(nums):
            for ind2, inner in enumerate(nums):
                if ind == ind2:
                    continue
                if outer + inner == target:
                    return ind, ind2