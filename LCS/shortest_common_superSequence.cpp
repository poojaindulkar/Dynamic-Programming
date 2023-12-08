#include<bits/stdc++.h>
using namespace std;

string LCS(int n, int m, string x,string y){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<=m;j++){
		dp[0][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i-1]==y[j-1]) {
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string ans="";
	int i=n,j=m;
	while(dp[i][j]>0){
		if(x[i-1]==y[j-1]){
			ans+=x[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]) i--;
			else j--;
		}
	}
    reverse(ans.begin(),ans.end());
	return ans;
}
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	int n=a.length(),m=b.length();
	string lcs=LCS(n, m, a, b);
	int l=lcs.length();
	int len=n+m-l;
	int i=0,j=0;
	string ans="";
	for(auto &x:lcs){
		while(x!=a[i]){
			ans+=a[i];
			i++;
		}
		while(x!=b[j]){
			ans+=b[j];
			j++;
		}
		ans+=x;
        i++;
        j++;
	}
	while(i<n){
			ans+=a[i];
			i++;
	}
	while(j<m){
			ans+=b[j];
			j++;
	}
	return ans;


}
int main(){
    string a="brute";
    string b="groot";
    cout<<shortestSupersequence(a,b);
}