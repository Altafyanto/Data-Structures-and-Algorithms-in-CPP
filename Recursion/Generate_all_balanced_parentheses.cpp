// Question:- https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

/*
Approach:-
1. Base case:- We will get a balanced parentheses everytime when count of opening and closing parentheses becomes zero.
2. Otherwise , we can always push opening parentheses to our output until its zero.
3. But if our opening parentheses count is less than the closing count then we can include it in our output to make it balanced.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int open , int close , string op , vector<string>&v)
{
	if(open == 0 && close == 0) 
	{
		v.push_back(op);
		return ;
	}
	
	if(open != 0)
	{
		solve(open-1 , close , op + '(' , v);
	}
	
	if(close > open)
	{
		solve(open , close-1 , op + ')' , v);
	}
}

int main()
{
	vector<string>v;
	int n ;
	cin>>n;
	int open = n , close = n ;
	string op = "" ;
	solve(open , close , op , v);
	for(int i = 0 ; i < v.size() ; i++)
	    cout<<v[i]<<" ";
}
