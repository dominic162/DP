///chefArrangement
#include<bits/stdc++.h>
using namespace std;
#define ff               first
#define ss               second
#define ll               long long int
#define test(x)          int x; cin>>x; for(;x>0;x--)
map<int,int> mp1;
int ans=0;
void dominic()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
}

void getcount(int fj){
	mp1[fj]++;
	if(mp1[fj]==2){
		ans=ans+2;
	}
	else{
		if(mp1[fj]>2){
			ans++;
		}
	}
}

int getans(int dp[],int n,int tblcost,int f[]){
	
	int j,ref;
	for(j=n;j>=1;j--){
		getcount(f[j]);
		ref=dp[j-1]+tblcost+ans;
		dp[n]=min(dp[n],ref);
	}
	mp1.clear();
	return dp[n];

}

int main()
{
    dominic();

	test(t){
		int n,k,f[1001]={0},i,dp[1001];
		cin>>n>>k;
		for(i=1;i<=n;i++){
			cin>>f[i];
		}
		dp[0]=0;
		for(i=1;i<=n;i++){
			ans=0;
			dp[i]=INT_MAX;
			dp[i]=getans(dp,i,k,f);
		}
		cout<<dp[n]<<endl;

	}

    
    return 0;
}