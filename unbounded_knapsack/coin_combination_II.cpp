/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.

*/

#include <bits/stdc++.h> 
using namespace std;
int mod=1000000007;
int coinCombinationII(vector<int> &num, int x)
{
    int n=num.size();
    int dp[n+1][x+1];
    //Initilizing 
    for(int i=0;i<=x;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(num[i-1]<=j){
                dp[i][j]=(dp[i-1][j] + dp[i][j-num[i-1]])%mod;
            }
            else{
                dp[i][j]=dp[i-1][j]%mod;
            }
        }
        
    }
    return dp[n][x];

}

int main(){
    vector<int>v;
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<coinCombinationII(v,x);
}