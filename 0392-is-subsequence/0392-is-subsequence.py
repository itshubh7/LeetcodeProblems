class Solution(object):
    def isSubsequence(self, s, t):
        
        n = len(s)
        m = len(t)
        j = 0

        for i in range(m):
            if j < n and s[j] == t[i]:
                j += 1
                
        return j == n