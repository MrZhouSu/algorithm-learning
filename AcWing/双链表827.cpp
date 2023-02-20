#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;
//初始化 0的右边是1，1的左边是0;
void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
//在k的右边插入x，左边插入令k=l[k];
void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}
//删除下标为k的结点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main(void)
{
    init();
    int m;
    cin >> m;
    while (m--)
    {
        string p;
        int k, x;
        cin >> p;
        if (p == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (p == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (p == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (p == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    cout << endl;
    return 0;
}