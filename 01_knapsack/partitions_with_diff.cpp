/*
Given an array Arr[] and a difference diff, find the number of subsets that array can be divided so that each the difference between the two subset is the given diff.

Example1:
Input:
Arr[] : 1,1,2,3
diff: 1
Output: 3 . 

*/
#include<bits/stdc++.h>
using namespace std;
int count_subsetSum(vector<int>& arr, int k,int n)
{
	 int mod = 1e9+7;
     
	// Write your code here.
	int dp[n+1][k+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(i==0) dp[i][j]=0;
			if(j==0) dp[i][j]=1;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
            }
            else{
                dp[i][j]=(dp[i-1][j])%mod;
            }
		}
	}
    cout<<"    ";
    for(int i=0;i<=k;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=0;i<=k;i++){
        cout<<"__";
    }
    cout<<"\n";

    for(int i=0;i<=n;i++){
        cout<<i<<" | ";
		for(int j=0;j<=k;j++){
			cout<<dp[i][j]<<" ";
		}
        cout<<"\n";
	}
	return dp[n][k];

}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    long sum=0;
    for(auto x:arr){
        sum+=x;
    }
    int s1=((d+sum)/2) + ((d+sum)%2);
    
   
    return count_subsetSum(arr,s1,n);

}


int main(){
    vector<int>v={2,7,2,6};
    cout<<countPartitions(4,12,v);
    return 0;
}