#User function Template for python3
class Solution:
     
    #Function to find if there exists a triplet in the 
    #array A[] which sums up to X.
    def find3Numbers(self,lit, n, X):
        c=0
        lit.sort()
        j=0
        k=0
        for i in range (len(lit)):
            j=i+1
            k=len(lit)-1
            s=X-lit[i]
            while(j<k):
                if((lit[j]+lit[k])==s):
                    return 1   
                
                if(lit[j]+lit[k]>s):
                    k-=1
                
                else:
                    j+=1
                
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
        n,X=map(int,input().strip().split())
        A=list(map(int,input().strip().split()))
        ob=Solution()
        if(ob.find3Numbers(A,n,X)):
            print(1)
        else:
            print(0)
# } Driver Code Ends