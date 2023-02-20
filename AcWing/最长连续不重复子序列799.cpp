#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int j = 0, maxid = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && b[a[j]] == 0)
        {
            b[a[j]]++;
            j++;
        }
        maxid = max(maxid, j - i);
        b[a[i]]--;
    }
    cout << maxid;
    system("pause");
    return 0;
}