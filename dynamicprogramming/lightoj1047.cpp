#include <bits/stdc++.h>

using namespace std;

#define NL "\n"
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define L(a) a.length()
#define mod 1000000007ll
#define ss(a) stringstream sin(s)
#define ALL(a) ((a).begin(),(a).end())
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)
#define ccout(T) cout << "Case " << T << ": "
#define spout(a,b) cout << fixed << setprecision((b)) << (a)

int N;
int ans[4];
LL dp[1010][5];
int home[1010][5]; 

LL F(int i, int c)
{
	if(i > N) return 0;
	if(dp[i][c] != -1) return dp[i][c];
	LL ret1=0,ret2=0,ret=0;
	if(c==0)
	{
		ret1 = F(i+1,c+1) + home[i][c];
		ret2 = F(i+1,c+2) + home[i][c];
	}
	if(c==1)
	{
		ret1 = F(i+1,c+1) + home[i][c];
		ret2 = F(i+1,c-1) + home[i][c];
	}
	if(c==2)
	{
		ret1 = F(i+1,c-1) + home[i][c];
		ret2 = F(i+1,c-2) + home[i][c];
	}
	ret = min(ret1,ret2);
	return dp[i][c] = ret;
}

void solve()
{
 	int T; cin >> T;
 	FOR(i,1,T+1)
 	{
 		cin >> N;
 		memset(dp,-1,sizeof dp);
 		memset(home,0,sizeof home); 
 		for(int i=1; i<=N; i++)
 			for(int j=0; j<3; j++)
 				cin >> home[i][j];
 		ans[0] = F(1,0);
 		ans[1] = F(1,1);
 		ans[2] = F(1,2);
 		sort(ans,ans+3);
 		ccout(i) << ans[0] << "\n";
 	}   
}

int main()
{
    #ifdef dipon
    read("in.in");
    //write();
    #else
    ios_base::sync_with_stdio(false); cin.tie(0);
    #endif
    solve();
    //cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;  
    return 0;
}

