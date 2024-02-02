#User function template for Python

class Solution:
    # your task is to complete this function
    # function should return an integer
    def atoi(self,s):
        dict1={}
        for i in "1234567890":
            dict1[i]=1
        c=0
        num=0
        k=1
        for i in range(len(s)):
            if(s[i]=='-' and i==0):
                ##c=c-1
                k=0
                continue
            
            if s[i] in dict1:
                c+=1
                ok=ord(s[i])-ord('0')
                num=num*10+ok
            else:
                return -1
        if(k==0):
            return -num
        return num


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__=='__main__':
    t=int(input())
    for i in range(t):
        string = input().strip();
        ob=Solution()
        print(ob.atoi(string))
# } Driver Code Ends