struct line
{
    long long a, b;
    line(long long _a = 0, long long _b = 0)
    {
        a = _a, b = _b;
    }
};
line lines[maxn];
double giao(line p1, line p2)
{
    return 1.0 * (1.0 * p2.b - p1.b) / (1.0 * p1.a - p2.a);
}

void addLine(line p3)
{
    while(sz >= 2)
    {
        line p2 = lines[sz], p1 = lines[sz - 1];
        if(giao(p1, p2) >= giao(p1, p3))
            --sz;
        else
            break;
    }
    lines[++sz] = p3;
}
if(cur > sz)
            cur = sz;
        while(cur + 1 <= sz && lines[cur].a * x + lines[cur].b >= lines[cur+1].a * x + lines[cur+1].b)
            ++cur;


