///code by sonhotrung
///2 dòng này sẽ mất:)))
#include <bits/stdc++.h>
#define pb push_back
const int maxn=1e4+5;
const long long oo=1e18;
using namespace std;
int n,m;
int nchild[maxn],low[maxn],num[maxn],Par[maxn];
vector <int> E[maxn];
int timee;
int KT[maxn];
void DFS(int u)
{
    timee++;
    low[u] = timee;
    num[u] = timee;
    for (int v : E[u])
        if (Par[u] != v)
        {
            if (num[v])
                low[u] = min(low[u],num[v]);
            else
            {
                nchild[u]++;
                Par[v] = u;
                DFS(v);
                low[u] = min(low[u],low[v]);
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
    cin >> n >> m;
    while (m--)
    {
        int u,v;
        cin >> u >> v;
        E[u].pb(v);
        E[v].pb(u);
    }
    for (int i= 1; i <= n; ++i)
        if (num[i] == 0)
        {
            Par[i] = 0;
            DFS(i);
        }

    int cau = 0,khop = 0;
    for (int I = 1;i <= n; ++i)
    {
        int v = Par[i];
        if (v != 0 && low[i] >= num[i])
            cau++;
    }

    for (int i = 1; i <= n; ++i)
    {
        int v = Par[i];
        if (v == 0 && nchild[i] > 1)
            KT[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        int v = Par[i];
        if (Par[v] != 0 && low[i] >= num[v])
            KT[v] = 1;
    }
    for (int i= 1; i <= n; ++i)
        if (KT[i])
        {
            //cout << i << endl;
            khop++;
        }
    cout << khop << " " << cau;
    return 0;
}

Nén cây
void DFS(int u)
{
    KT[u] = false;
    Low[u] = Num[u] = dem++;
    top++;
    DS[top] = u;

    for (int v : E[u])
        if (KT[v])
        {
            DFS(v);
            Low[u] = min(Low[u],Low[v]);
        }
        else
            Low[u] = min(Low[u],Num[v]);

    if (Low[u] == Num[u])
    {
        int v;
        kq++;
        do
        {
            V = DS[top];
            top--;
            Low[v] = Num[v]=oo;
        }
        while (u != v);
    }

}

