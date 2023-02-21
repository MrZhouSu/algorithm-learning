### E.Cheating Amidakuji

#### 解题思路:

类似于找个数组跟着B数组里面的数一起动，我们可以很容易知道自己设置的数组最后会跑到哪，所以只需要看B数组中的1的位置和自己设置的数组中的哪个数对应就行了

将第i次输出的结果分开成1到i-1次交换和i+1到m次交换的结果

难点在于如何处理从i+1~m次交换的结果

不妨设一个数组S

S[i]表示第i个位置的数最后一定会跑到第S[i]个的位置

S数组顺着跑完一定会变成初始数组

只需要先让S数组逆着跑一遍就行了

显然当i==m时 S数组应该初始化为S[i]=i;方便找位置

假设当经过i-1次变化后 1所在的位置是3，此时S[3]==2;

由变化的逆推可知

2在经过后面的一系列变化后一定会回到第二个位置，此时S数组对应的2在第三个位置，1也在第三个位置，那么1经过后面的变化就会到第二个位置去

也就是说:S[3]==2表示逆着跑m到i+1后，再顺着跑，第三个位置的数最后一定会跑到第二个位置

代码如下：

```cpp
#include <bits/stdc++.h>
#define ll long long

const int N = 2e5 + 10;

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(N);

    for (ll i = 1; i <= m; i++)
        std::cin >> a[i];

    std::vector<int> p(N), s(N), b(N);
    /*
        p[i]表示i的位置
        s[i]=x表示经过i+1~m的交换后 1如果位于i的位置，最后会变到s[i]的位置
    */

    std::iota(p.begin(), p.end(), 0);
    s = b = p;

    for (ll i = m; i >= 1; i--)
        std::swap(s[a[i]], s[a[i] + 1]);

    for (ll i = 1; i <= m; i++)
    {
        std::swap(s[a[i]], s[a[i] + 1]);
        std::cout << s[p[1]] << std::endl;
        std::swap(b[a[i]], b[a[i] + 1]);
        std::swap(p[b[a[i]]], p[b[a[i] + 1]]);
    }

    return 0;
}
```
