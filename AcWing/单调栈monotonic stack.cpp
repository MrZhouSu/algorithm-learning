#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt = -1;
int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        while (tt != -1 && stk[tt] >= x)
            tt--;
        if (tt != -1)
            cout << stk[tt] << " ";
        else
            cout << -1 << " ";

        stk[++tt] = x;
    }
    return 0;
}