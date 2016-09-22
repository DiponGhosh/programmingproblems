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
#define ccout cout << "Case " << T << ": "
#define spout(a,b) cout << fixed << setprecision((b)) << (a)

int N;
LL cube[22];
LL dp[22][10000];

LL F(int i, int amount)
{
    if(i>21)
    {
        if(amount == 0) return 1;
        else return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];
    LL ret = 0;
    if(amount-cube[i]>=0) ret += F(i,amount-cube[i]); 
    ret += F(i+1,amount);
    return ret;
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=21; i++)
        cube[i] = (i * i * i);
     while((cin >> N))
     {
        cout << F(1,N) << "\n";
        cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
     }    
}

int main()
{
    #ifdef dipon
    read("in.in");
    //write();
    #else
    ios_base::sync_with_stdio(false); //cin.tie(0);
    #endif
    solve();
    //cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;  
    return 0;
}

