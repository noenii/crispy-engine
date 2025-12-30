class Solution(object):     # reverse digits of an int
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        sign = -1 if x < 0 else 1
        x_abs = abs(x)
        reversed_str = str(x_abs)[::-1]
        reversed_int = sign * int(reversed_str)
        if reversed_int < INT_MIN or reversed_int > INT_MAX:
            return 0
        return reversed_int