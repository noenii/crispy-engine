class Solution(object):     # convert string to a zigzag
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        res = []
        inc = (numRows - 1) * 2
        for outer in range(numRows):
            for inner in range(outer, len(s), inc):
                res.append(s[inner])
                diag = inner + inc - 2 * outer
                if outer > 0 and outer < numRows - 1 and diag < len(s):
                    res.append(s[diag])
        return ''.join(res)