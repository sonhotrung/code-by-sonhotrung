const int mod = (int)1e9+7;

void add(int &x, const int &y)
{
    x += y;
    if(x >= mod) x -= mod;
}
void sub(int &x, const int &y)
{
    x -= y;
    if(x < 0) x += mod;
}
#define PRODUCT(x,y) (1LL*(x)*(y)%mod)

int power(int x, int y)
{
    int res = 1;
    while(y > 0)
    {
        if(1&y) res = PRODUCT(res, x);
        x = PRODUCT(x, x);
        y /= 2;
    }
    return res;
}
