#time complexity: O(N)
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        #first, deal with the sign and overflow
        sign = 0
        if x == 0 or (x > 2**31 - 1) or (x < -2**31):
            return 0
        elif x > 0:
            sign = 0
        else:
            sign = 1
            x = (-1) * x
        
        #get all digits of the integer
        x_list = []
        while(x//10 != 0):
            x_list.append(x%10)
            x = x // 10
        x_list.append(x%10)
        
        #reverse
        size = len(x_list)
        new = 0
        time = 1
        for index in range(size):
            new = new + time * x_list[size - 1 - index]
            time = time * 10
        
        #deal with the sign and overflow
        if sign == 1:
            new = (-1) * new
        else:
            new = new
        if (new > 2**31 - 1) or (new < -2**31):
            return 0
        else:
            return new