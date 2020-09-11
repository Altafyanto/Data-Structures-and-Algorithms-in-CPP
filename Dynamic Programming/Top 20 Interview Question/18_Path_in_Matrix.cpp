// https://practice.geeksforgeeks.org/problems/path-in-matrix/0

#include<iostream>
using namespace std;

int MaximumPathSum(int **A,int i,int j,int n,int **dp)
{
    // Boundary conditions , as we are not going in upward direction so we haven't took i<0 condition.
    if(i >= n || j < 0 || j >= n) 
        return 0;
    
    // if we are at the last row then we are done.
    if(i == n-1) 
        return A[i][j];
        
    // if value for these indexes is already processed.
    if(dp[i][j] != -1) 
        return dp[i][j];
        
    int a = MaximumPathSum(A,i+1,j-1,n,dp); // diagonally left.
    int b = MaximumPathSum(A,i+1,j,n,dp); // downward.
    int c = MaximumPathSum(A,i+1,j+1,n,dp); // diagonally right.
    return dp[i][j] = A[i][j] + max(a,max(b,c)); // taking max of all.
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int **matrix = new int*[n]; // dynamically allocated matrix.
	    for(int i = 0; i < n; i++)
	    matrix[i] = new int[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin >> matrix[i][j];
	        }
	    }
	    
	    int max_ans = 0;
	    
	    int **dp = new int*[n];
	    for(int i=0;i<n;i++)
	    dp[i] = new int[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            dp[i][j]=-1;
	        }
	    }
	    
	    // calculating max sum for every column taking row 0 and taking its maximum.
	    for(int i=0;i<n;i++)
	    {
	        int ans = MaximumPathSum(matrix,0,i,n,dp);
	        max_ans = max(ans,max_ans);
	    }
	    cout << max_ans << endl;
	}
}
