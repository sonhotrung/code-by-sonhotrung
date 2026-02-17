#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
const int maxn=1e5+5;
using namespace std;
int n, m, s, t;
vector <pii> E[maxn];
int D[maxn],Trace[maxn];
void Dij()
{
    memset(D, 0x3f, sizeof(D));
    D[s] = 0 ;
    priority_queue<pii> q;
    q.push({-D[s], s});
    while(!q.empty())
    {
        int u = q.top().se ;
        q.pop();
        for(int i = 0 ; i < E[u].size() ; i++)
        {
            int v = E[u][i].fi;
            int w = E[u][i].se;
            if(D[v] > D[u] + w)
            {
                D[v] = D[u] + w;
                Trace[v]=u;
                q.push({-D[v], v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t ;
    for(int i = 1 ; i <= m ; i++)
    {
        int u, w, v;
        cin >> u >> v >> w ;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }
   Dij();
    cout << D[t];
}


