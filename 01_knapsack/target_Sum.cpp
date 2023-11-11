/*
Target Sum Problem
Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

*/

#include <bits/stdc++.h> 
using namespace std;
int subset_sum(int n,int target,vector<int>& arr){
    int mod=(int)1e9+7;
    int dp[n+1][target+1];
    
    for(int i=0;i<=target;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
            }
            else{
                dp[i][j]=dp[i-1][j]%mod;
            }
        }
    }
    return dp[n][target];

}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<"sum"<<sum<<endl;
    int s1=(target+sum)/2;
    if((target+sum)%2!=0) return 0;
    return subset_sum(n, s1, arr);
}
int main(){
    vector <int>v={24, 36, 1, 3, 29, 0, 38, 17, 35, 31, 42 ,30 ,44, 35, 22};
    cout<<targetSum(15,21,v);
}