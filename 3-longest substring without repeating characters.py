#attempted but not solved 
#testcases: 84/987 passed
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        #first, find all repeated characters in string
        max = 1
        characters = {}
        for ch in s:
            if ch not in characters:
                characters[ch] = 1
            else:
                characters[ch] += 1
        
        flag = True
        for key in characters:
            if characters[key] == 1:
                continue
            else:
                flag = False
                
        if characters == {}:
            return 1
        elif flag == True:
            return len(s)
        elif flag == False:
            for key in characters:
                tmp = s.split(key)
                print tmp
                for t in tmp:
                    if len(t) > max:
                        l = self.lengthOfLongestSubstring(t)
                        if l + 1 > max:
                            max = l + 1
                        else:
                            continue
                    else:
                        continue
            return max
        else: 
            return 1