///code by sonhotrung
///2 dòng này sẽ mất:)))
#include <bits/stdc++.h>
#define pb push_back
const int maxn = 1e5+5;
const long long oo = 1e18;
using namespace std;
int n,m,p;
vector <int> E[maxn],S;
int Lab[maxn],match[maxn];
bool found;
int vst,res;
void DFS(int x)
{
    for (int y : E[x])
    {
        if (Lab[y] == vst)
            continue;
        Lab[y] = vst;
        if (match[y] == 0)
            found = true;
        else
            DFS(match[y]);
        if (found)
        {
            match[y] = x;
            return;
        }
    }

}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p;
    for (int I = 1; I <= p; ++i)
    {
        int u,v;
        cin >> u >> v;
        v= v + n;
        E[u].pb(v);
        E[v].pb(u);
    }
    for (int I = 1; I <= n; ++i)
        S.pb(i);
    fill(Lab + 1,Lab + 1 + n,0);
    vst = 0;
    while (1)
    {
        vst++;
        int k = S.size();
        for (int I = S.size() - 1; I >= 0; --i)
        {
            found = false;
            DFS(S[i]);
            if (found)
            {
                res++;
                S[i] = S.back();
                S.pop_back();
            }
        }
        if (k == S.size())
            break;
    }
    cout << res;
    return 0;
}
