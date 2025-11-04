class Solution(object):
    def lengthOfLongestSubstring(self, s):
        max_len = 0
        r = 0
        stri = []

        for x, y in enumerate(s):
            stri.append(y)
            while len(stri) != len(set(stri)):
                stri.pop(0)
            if len(stri) > max_len:
                max_len = len(stri)

        return max_len