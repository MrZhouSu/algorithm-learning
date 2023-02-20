#include <iostream>
#define lowbit(x) x &(-x)
using namespace std;

int main(void)
{
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        int ans = 0;
        while (x)
        {
            x -= lowbit(x);
            ans++;
        }
        cout << ans << " ";
    }
    system("pause");
    return 0;
}