/*solution for single input*/

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
#define pii pair<int,int>
#define ss(a) stringstream sin(a)
#define ALL(a) ((a).begin(),(a).end())
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)
#define ccout(T) cout << "Case " << T << ": "
#define spout(a,b) cout << fixed << setprecision((b)) << (a)

int input[100][100];
int vis[100][100];
int dis[100][100];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
vector<vector<pair<int,int> > > v;
int r,c,rowbomb,dx,dy;

void bfs(int sx, int sy)
{
    int flag = 0,ans = 0;
    memset(vis, 0, sizeof vis);
    vis[sx][sy] = 1;
    queue<pair<int,int> > q;
    pair<int,int> top;
    q.push(pair<int,int>(sx,sy));
    while(!q.empty())
    {
        pair<int,int> top;
        top = q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int tx = top.xx + fx[i];
            int ty = top.yy + fy[i];
            if(tx == dx && ty == dy) 
            {
                ans = dis[top.xx][top.yy] + 1;
                flag = 1;
                break;
            }
            if(tx>=0 and tx<r and ty>=0 and ty<c and 
            input[tx][ty]!= -1 and vis[tx][ty] == 0)
            {
                vis[tx][ty] = 1;
                q.push(pair<int,int>(tx,ty));
                dis[tx][ty] = dis[top.xx][top.yy] + 1;
                //v[tx][ty] = pair<int,int>(top.xx,top.yy);
            }
        }
        if(flag == 1) break;
    }
    cout << ans;
}


void solve()
{
    cin >> r >> c;
    cin >> rowbomb;
    for(int i=0; i<rowbomb; i++)
    {
        int colbomb,rowwithbomb;
        cin >> rowwithbomb >> colbomb;
        for(int j=0; j<colbomb; j++)
        {
            int colwithbomb;
            cin >> colwithbomb;
            input[rowwithbomb][colwithbomb] = -1;
        }
    }
    int sx,sy; 
    cin >> sx >> sy;
    cin >> dx >> dy;

    /*v.resize(10);
    for(int i=0; i<v.size(); i++)
        v[i].resize(10);*/
    memset(dis,0,sizeof dis);
    bfs(sx,sy);	
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

