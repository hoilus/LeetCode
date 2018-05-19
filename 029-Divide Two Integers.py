class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if (dividend > 0  and divisor > 0) or (dividend < 0  and divisor < 0):
            positive = True
        else:
            positive = False
        dividend = abs(dividend)
        divisor = abs(divisor)
        res = 0
        while dividend >= divisor:
            tmp, i = divisor, 0
            while dividend >= tmp:
                dividend -= tmp
                i += 1
                tmp = (tmp << 1)
            res += ((1<<i)-1) # 2^0+2^1+...+2^n-1 = 2**n-1
        if not positive:
            res = -res
        return min(max(-2**31,res), 2**31-1)
        
