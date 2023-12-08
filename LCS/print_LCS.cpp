#include<bits/stdc++.h>
using namespace std;

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}	
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
    // cout<<"\n-----------------------------\n";
    // cout<<"  ";
    // for(int i=0;i<=m;i++){
    //     cout<<s2[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<s1[i-1]<<" ";
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n-----------------------------\n";

	string ans="";
	int i=n,j=m;
	while(dp[i][j]>0){
		if(s1[i-1]==s2[j-1]){
			ans+=s1[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]) i--;
			else if(dp[i-1][j]<dp[i][j-1]) j--;
			
		}
	}
    reverse(ans.begin(),ans.end());
	return ans;

}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    string ans=findLCS(s1.length(),s2.length(),s1,s2);
    for(auto &x: ans){
        cout<<x<<"\n";
    }

}