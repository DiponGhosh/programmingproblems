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
#define ss(a) stringstream sin(a)
#define ALL(a) ((a).begin(),(a).end())
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)
#define ccout(T) cout << "Case " << T << ": "
#define spout(a,b) cout << fixed << setprecision((b)) << (a)

LL dp[110][510];
int coin[110];
int n;

int f(int i, int amount)
{
    if(i == n+1) return 0;
    if(amount<0) return 0;
    if(dp[i][amount] != -1) return dp[i][amount];
    LL ret=0,ret1=0,ret2=0;
    if(amount-coin[i] >= 0) ret1 = f(i+1,amount-coin[i])+coin[i];
    ret2 = f(i+1,amount);
    ret = max(ret1,ret2);
    return dp[i][amount] = ret; 
}

void solve()
{
   	int sum; 
   	memset(dp,-1,sizeof dp);
   	memset(dir,-1,sizeof dir);
   	cin >> n;
   	FOR(i,1,n+1)
   	{
        cin >> coin[i];
    	sum += coin[i];
   	}
   	int limit = sum / 2;
   	LL t = f(1,limit);
   	int answ;
  	if(sum % 2 == 0)
  		answ = 2 * (limit-t);
  	else{
  		answ = 2 * (limit-t) + 1;
  		//answ = 2 * (abs(limit - t));
  	}
  	cout << answ << "\n";
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

