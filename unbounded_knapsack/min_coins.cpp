#include <bits/stdc++.h> 
using namespace std;
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    // Write your code here.
    int dp[n+1][x+1];
    //Initilizing 
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=x;i++){
        dp[0][i]=INT_MAX-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(num[i-1]<=j){
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-num[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
         
        }
        
    }
    if(dp[n][x]==INT_MAX-1)  return -1;
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
    cout<<minimumElements(v,x);
}