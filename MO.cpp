//code by sonhotrung
//2 dòng này sẽ mất:)))
#include <bits/stdc++.h>
const int maxn=3e4+5;
const int maxm=1e6+5;
const long long oo=1e18;
using namespace std;
int bs;
struct query
{
    int L,R,vt;
    bool operator <(query&other)const
    {
        return (make_pair((L-1)/bs+1,R)<make_pair((other.L-1)/bs+1,other.R));
    }
};

int n,m;
int A[maxn];
query Q[maxm];
int kq[maxm],nho[maxm],cnt=0;
void add(int u)
{
    ++nho[A[u]];
    if (nho[A[u]]==1)
        ++cnt;
}
void def(int u)
{
    --nho[A[u]];
    if (nho[A[u]]==0)
        --cnt;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> A[i];
    bs=sqrt(n);
    cin >> m;
    for (int i=1; i<=m; ++i)
    {
        int u,v;
        cin >> u >> v;
        Q[i]=query{u,v,i};
    }
    sort(Q+1,Q+1+m);
    int L=1,R=0;
    for (query q:Q)
    {
        while (L>q.L)
            add(--L);
        while (R<q.R)
            add(++R);
        while (L<q.L)
            def(L++);
        while (R>q.R)
            def(R--);
        kq[q.vt]=cnt;
    }
    for (int i=1;i<=m;++i)
        cout << kq[i] <<endl;
    return 0;
}
