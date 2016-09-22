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
#define mem(a,v) memset(a, v, sizeof(a))
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)
#define ccout cout << "Case " << T << ": "
#define spout(a,b) cout << fixed << setprecision((b)) << (a)

int dp[32][1010];
int d[32];
int cost[32];
int tim[32];
int mark[32];
int dir[32][1010];
int T,W,N;

void solution()
{
    int cnt=0;
    FOR(i,1,N+1)
    {
        FOR(j,0,T+1){
            if(dir[i][j] == 1) 
            {
                cnt++;
                mark[i] = 1;
                i++; 
                j=j+tim[i];
            }
            else if(dir[i][j] == 2)
            {
                i++; j = j;   
            }
        }
    }
    cout << cnt << "\n";
    if(cnt){
    FOR(i,1,N+1)
    {
        if(mark[i])
        {
            cout << d[i] << " " << cost[i] << "\n";
        }
    }
}
}

int F(int i, int remain)
{
    if(i == N+1) return 0;
    if(dp[i][remain] != -1) return dp[i][remain];

    int ret=0,ret1=0,ret2=0;

    if(tim[i]+remain <= T) { 
        ret1 = (F(i+1,tim[i]+remain)+cost[i]);
    }
    ret2 = F(i+1,remain); 
    ret = max(ret1,ret2);
    if(ret==ret1 && ret > 0) dir[i][remain]=1;
    else dir[i][remain]=2;
    return dp[i][remain]=ret;
}

void solve()
{
    bool line = false;
   while(cin >> T >> W >> N)
    {
        mem(dp,-1); mem(d,0); mem(cost,0); mem(dir,-1);
        FOR(i,1,N+1)
            cin >> d[i] >> cost[i];
        for(int i=1; i<=N; i++)
            tim[i] = (d[i]*W + 2*d[i]*W);
        if(line) {cout <<"\n"; }
        line=true;
        cout << F(1,0) << "\n";
        solution();
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

