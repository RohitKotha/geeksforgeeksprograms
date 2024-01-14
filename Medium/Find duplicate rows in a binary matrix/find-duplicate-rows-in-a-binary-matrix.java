//{ Driver Code Starts
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int m = Integer.parseInt(inputLine[1]);
            int[][] arr = new int[n][m];
            
            for(int i = 0; i < n; i++){
                String[] s = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++){
                    arr[i][j] = Integer.parseInt(s[j]);
                }
            }
            ArrayList<Integer> ans = new Solution().repeatedRows(arr, n, m);
            for(int i=0;i<ans.size();i++)
                System.out.print(ans.get(i)+" ");
                
            System.out.println();
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    public static ArrayList<Integer> repeatedRows(int arr[][], int m, int n)
    {
        int ok=0;
        int[] arr1=new int[m];
        //code here
        for(int i=0;i<m;i++){
            ok=0;
            for(int j=0;j<n;j++ ){
                ok=ok*10+arr[i][j];
            }
            arr1[i]=ok;
        }
        ArrayList<Integer> arr2=new ArrayList<>();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(arr1[i]==arr1[j]){
                    arr2.add(j);
                    break;
                }
            }
        }
        Collections.sort(arr2); 
        return arr2;
    }
}