//Cây BIT để tính số lượng phần tử, max hoặc min trong cây nhỏ hơn 1 giá trị x nào đó
//Cập nhật cây
void update(int x,int sl) // log(n)
{
    while (x < maxa)
    {
        Tree[x] = Tree[x] + sl;
        x = x + (x & (-x));
    }
}
long long tinh(int x) // log(n)
{
    long long S = 0;
    while (x > 0)
    {
        S = S + Tree[x];
        x = x - (x & (-x));
    }
    return S;
}
//Tham khảo bài: https://oj.vnoi.info/problem/nkinv


