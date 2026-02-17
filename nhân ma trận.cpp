1. Bài toán Lát Gạch TILE. Cho một hình chữ nhật kích thước 2xN (1<=N<109). Hãy đếm số cách lát các viên
gạch nhỏ kích thước 1x2 và 2x2 vào hình trên sao cho không có phần nào của các viên
gạch nhỏ thừa ra ngoài, cũng không có vùng diện tích nào của hình chữ nhật không được lát.
//code by sonhotrung
//2 dòng này sẽ mất:)))
#include <bits/stdc++.h>
const long long oo=1e18;
const long long MOD=1e9+7;
using namespace std;
int T;
struct matrix
{
    long long val[2][2];
};
matrix a,c;

matrix operator *(matrix a,matrix b)
{
    matrix c;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
        {
            c.val[i][j]=0;
            for (int k=0; k<2; k++)
                c.val[i][j]=(c.val[i][j]+(a.val[i][k]*b.val[k][j])%MOD)%MOD;
        }
    return c;
}

matrix operator ^(matrix a, long long k)  //chia de tri
{
    matrix x;
    if (k==1)
        return a;
    x=a^(k/2);
    x=x*x;
    if (k%2==1)
        x=x*a;
    return x;
}
void init()
{
    //khoi tao ma tran co so
    a.val[0][0]=1;
    a.val[0][1]=2;
    a.val[1][0]=1;
    a.val[1][1]=0;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    long long n;
    init();
    cin>>T;
    while (T--)
    {
        cin>>n;
        if (n==1)
            cout<<1<<endl;
        else
        {

            c=a^(n-1);
            cout<<(c.val[0][0]+c.val[0][1])%MOD<<endl;
        }
    }
    return 0;
}
