class Solution(object):     # longest palindromic substring
    def longestPalindrome(self, s):
        if not s:
            return ""
        t = "^#" + "#".join(s) + "#$"
        n = len(t)
        P = [0] * n
        center = right = 0
        for i in range(1, n - 1):
            mirror = 2 * center - i
            if i < right:
                P[i] = min(right - i, P[mirror])
            while t[i + P[i] + 1] == t[i - P[i] - 1]:
                P[i] += 1
            if i + P[i] > right:
                center = i
                right = i + P[i]
        max_len = 0
        center_index = 0
        for i in range(1, n - 1):
            if P[i] > max_len:
                max_len = P[i]
                center_index = i
        start = (center_index - max_len) // 2
        return s[start:start + max_len]