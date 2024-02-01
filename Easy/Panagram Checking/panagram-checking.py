class Solution:
    def checkPangram(self, s):
        ss = set(s.lower())
        c1=0
        dict1={}
        for i in"qwertyuiopasdfghjklzxcvbnm":
            dict1[i]=1
        for i in ss:
            if i in dict1:
                c1+=1
        if(c1>=26):
            return 1
        
        else:
            return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        obj = Solution()
        if(obj.checkPangram(s)):
            print(1)
        else:
            print(0)
# } Driver Code Ends