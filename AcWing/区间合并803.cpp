#include <iostream>
#include <algorithm>
#define PII pair<int, int>

using namespace std;

const int N = 1e5 + 10;
PII a[N];
int n;

int main(void)
{
    cin >> n;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        a[i] = {l, r};
    }
    sort(a, a + n);
    int sum = n;
    l = a[0].first;
    r = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if (r >= a[i].first)
        {
            r = max(a[i].second, r);
            l = min(a[i].first, l);
            sum--;
        }
        else
        {
            r = a[i].second;
            l = a[i].first;
        }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}