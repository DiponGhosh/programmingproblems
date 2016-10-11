/*uva p336 solution for single  input*/

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

vector<int> adjlist[100];
int dis[100];
int visited[100];
int n;

int f(int i)
{
	
}

void solve()
{
	cin >> n;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >>b;
        adjlist[a].pb(b);
        adjlist[b].pb(a);
    }
    /*for(int i=0; i<=100; i++)
    {
        if(!adjlist[i].empty()){
            cout << i << " -> ";
            for(vector<int> :: iterator it = adjlist[i].begin(); it != adjlist[i].end(); ++it)
            {
                cout << " -> " << *it << " -> ";
            }
            cout << "NULL";
            cout << "\n";
        }
    }*/
    int s,ttl;
    cin >> s >> ttl;
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<adjlist[u].size(); i++)
        {
            int ve = adjlist[u][i];
            if(visited[ve] != 1)
            {
                visited[ve] = 1;
                q.push(ve);
                dis[ve] = dis[u] + 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 101; ++i)
    {
        if(dis[i] > ttl)
            cnt++;
    }
    cout << cnt << "\n";
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

