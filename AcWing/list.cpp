#include <iostream>

using namespace std;

const int N = 1e5 + 10;

// head表示头结点下标
// e[i]表示结点i的值
// ne[i]表示结点i的下一个结点指针的值
// idx表示当前用到了哪个点
int e[N], ne[N], head, idx;

//初始化
void init()
{
    head = -1;
    idx = 0;
}
//将x插到头结点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
//将x插到下标是k的点的后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
//将下标是k的点后面的点删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main(void)
{
    return 0;
}