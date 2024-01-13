#User function Template for python3

class Solution:
    def getPairsCount(self, lit, n, k):
        lit.sort()
        ##k=4
        ok=0
        i=0
        j=len(lit)-1
        dict={}
        co=0
        for i in lit:
            if i in dict:
                dict[i]+=1
            else:
                dict[i]=1
        ##print(dict)
        for i in lit:
            if i in dict:
                dict[i]-=1
                val=abs(i-k)
               ## print(val)
            if val in dict:
                co+=dict[val]
                ##print(dict[val])
        
        return co
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getPairsCount(arr, n, k)
        print(ans)
        tc -= 1

# } Driver Code Ends