#User function Template for python3
class Solution:
	def countTriplet(self, lit, n):
	    c=0
	    lit.sort()
	    dict = {}
        for i in range(len(lit)):
            dict[lit[i]] = i
        
        for i in range(len(lit)):
            for j in range(i + 1, len(lit)):
                ok = lit[i] + lit[j]
                if ok in dict and dict[ok] != i and dict[ok] != j:
                    c+=1
        return c

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		arr = [int(x) for x in input().split()]

		ob = Solution()
		ans = ob.countTriplet(arr, n)
		print(ans)

# } Driver Code Ends