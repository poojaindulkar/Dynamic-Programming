#include<bits/stdc++.h>
using namespace std;
int getANS(int arr[],int n,int cur_ind,int prev_ind,vector<vector<int>>& dp){
    if(cur_ind==n) return 0;

    if(dp[cur_ind][prev_ind+1]!=-1) return dp[cur_ind][prev_ind+1];

    if(prev_ind==-1||arr[prev_ind]<arr[cur_ind]){
        return dp[cur_ind][prev_ind+1]=  1+getANS(arr,n,cur_ind+1,prev_ind+1,dp);
    }

    return dp[cur_ind][prev_ind+1]=max(getANS(arr,n,cur_ind+1,prev_ind,dp),1+getANS(arr,n,cur_ind+1,prev_ind+1,dp));
    
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return getANS(arr, n, 0, -1, dp);
}
int main(){
    int arr[]={1,1,1};
    cout<<longestIncreasingSubsequence(arr,3);
}