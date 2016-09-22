/*
longest common subsequence
*/
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

string S1,S2;
int dp[1010][1010];
bool mark[1010];

int F(int i,int j)
{
    if(i == L(S1) || j == L(S2)) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(S1[i] == S2[j]) {
        dp[i][j] = 1+F(i+1,j+1);
        mark[i]=true;
    }
    else dp[i][j] = max(F(i+1,j),F(i,j+1));

    return dp[i][j];
}

void solve()
{
    memset(dp,-1,sizeof dp);
    memset(mark,false, sizeof mark);
    cin >> S1 >> S2;
    cout << F(0,0) << "\n";
    rep(i,L(S1))
        if(mark[i] == true)
            cout << S1[i];
    cout << "\n";
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

