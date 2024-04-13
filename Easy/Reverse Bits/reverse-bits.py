#User function Template for python3

class Solution:
    def reversedBits(self, n):
        bit = format(n, '032b')
        ##bit=bit[::-1]
       
        num=0
        i=1
        
        co=0
        while(co<32):
            num+=i*int(bit[co])
            i=i*2
            co+=1
       
        return num
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        X=int(input())
        
        ob = Solution()
        print(ob.reversedBits(X))
# } Driver Code Ends