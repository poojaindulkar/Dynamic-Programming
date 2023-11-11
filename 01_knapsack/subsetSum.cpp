/*
Subset Sum Problem(Dynamic Programming)
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long sum=0;
        for(auto x: nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int targetSum=sum/2;
        int n=nums.size();
        bool dp[n+1][targetSum+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<targetSum;j++){
                if(j==0) dp[i][j]=false;
                if(i==0) dp[i][j]=true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=targetSum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][targetSum];
    }
};

int main()
{
    vector<int>nums={1,1};
    Solution s;
    cout<<s.canPartition(nums);


    return 0;
}