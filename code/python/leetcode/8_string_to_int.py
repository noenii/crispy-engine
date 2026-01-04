class Solution(object):     # string to int
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        s = s.strip()
        sign = -1 if s[0] == "-" else 1
        if s[0] in {"-", "+"}:
            s = s[1:]
        res = 0
        for i in s:
            if not i.isdigit():
                break
            res = res * 10 + ord(i) - ord("0")
            if res * sign <= -2**31:
                return -2**31
            if res * sign > 2**31 - 1:
                return 2**31 - 1
        return res * sign