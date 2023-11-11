/*
Sum of subset differences
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11
*/


#include<bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum=0;
	for(auto x:arr){
		sum+=x;
	}
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0) dp[i][j]=false;
			if(j==0) dp[i][j]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	vector<int>possibleSum;
	for(int i=0;i<=sum/2;i++){
		if(dp[n][i]){
			possibleSum.push_back(i);
		}
	}
	int mn=INT_MAX;
	for(int i=0;i<possibleSum.size();i++){
		mn=min(mn,sum-2*possibleSum[i]);
	}
	return mn;

}


int main(){
    vector <int>v={8 ,6 ,5};
    int n=3;
    cout<<minSubsetSumDifference(v,n);


}