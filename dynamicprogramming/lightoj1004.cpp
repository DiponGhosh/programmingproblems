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

LL mat[510][510];
LL dp[510][510];
int N;

void reset()
{
	memset(mat,0,sizeof(mat));
	memset(dp,-1,sizeof(dp));
}

LL F(int i, int j)
{
	//if( (i < 0 || i > 2*N-2) || (j < 0 || j > i || j > 2*N-2-i) ) return 0;
	if(mat[i][j] == 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	LL ret=-1ll;
	if(i >= N-1){
		ret = max(ret,F(i+1,j-1)+mat[i][j]);
		ret = max(ret,F(i+1,j)+mat[i][j]);
	}
	else
	{
		ret = max(ret,F(i+1,j)+mat[i][j]);
		ret = max(ret,F(i+1,j+1)+mat[i][j]);
	}
	return dp[i][j]=ret;
}

void solve()
{
    int T; cin >> T;
    FOR(ks,1,T+1)
    {
    	reset();
    	cin >> N;
    	FOR(i,0,N)
    		FOR(j,0,i+1)
    			cin >> mat[i][j];
    	int k=1;
    	FOR(i,N,2*N-1)
    	{
    		int j=0,cnt=N-k;
    		while(cnt--)
    		{
    			cin >> mat[i][j];
    			j++;
    		}
    		k++;
    	}
    	ccout(ks) << F(0,0) << "\n";
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

