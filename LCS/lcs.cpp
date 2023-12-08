#include<bits/stdc++.h>
using namespace std;
//Recursion
/*
int LCS(string x, string y, int n, int m){
    if(n==0 || m==0) return 0;
    if(x[n-1]==y[m-1]) return 1+LCS(x,y,n-1,m-1);
    return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
}
int main(){
    
        string x,y;
        cin>>x>>y;
        cout<<LCS(x,y,x.length(),y.length());
    
    return 0;
}
*/

//Memorization
/*
int dp[100][100];
int LCS(string x, string y, int n, int m){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(x[n-1]==y[m-1]) 
        return dp[n][m]=1+LCS(x,y,n-1,m-1);
    return dp[n][m]=max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
}
int main(){
   
        string x,y;
        cin>>x>>y;
        for(int i=0;i<=x.length();i++){
            for(int j=0;j<=y.length();j++){
                dp[i][j]=-1;
            }
        }
        cout<<LCS(x,y,x.length(),y.length());
 
    return 0;
}
*/

//Bottom-up
int LCS(string x, string y){
    int n=x.length(),m=y.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<"\n-------------------------------\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n-------------------------------\n";
    return dp[n][m];
}
int main(){
   
        string x,y;
        cin>>x>>y;
        cout<<LCS(x,y);
 
    return 0;
}