#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], head, idx;

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void Delete(int k)
{
    ne[k - 1] = ne[ne[k - 1]];
}

void insert(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx;
    idx++;
}
int main(void)
{
    int m;
    init();
    cin >> m;
    char p;
    int q, r;
    while (m--)
    {
        cin >> p;
        if (p == 'H')
        {
            cin >> q;
            add_to_head(q);
        }
        else if (p == 'D')
        {
            cin >> q;
            if (q == 0)
            {
                head = ne[head];
            }
            Delete(q);
        }
        else
        {
            cin >> q >> r;
            insert(q, r);
        }
    }
    int h = head;
    while (h != -1)
    {
        cout << e[h] << " ";
        h = ne[h];
    }
    return 0;
}