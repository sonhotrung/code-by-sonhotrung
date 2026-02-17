int getroot(int u)
{
    return ((Root[u] == 0)  ?  u  :  Root[u] = getroot(Root[u]));
}	
int getroot(int u)
{
    while (Root[u] != 0) 
u = Root[u];
    return u;
}
   
void Union(int u,int v)
{
    U = getroot(u);
    V = getroot(v);
    if (u != v)
    {
        if (Lab[u] > Lab[v]) 
swap(u,v); // v la thang co Lab to hon
        Root[u] = v;
        Lab[v] = Lab[v] + Lab[u];
    }
}

Tham khảo bài : https://oj.vnoi.info/problem/ioibin

