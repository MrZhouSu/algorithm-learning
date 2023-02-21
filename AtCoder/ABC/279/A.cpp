#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string str;
  cin >> str;
  ll sum = 0;
  for (ll i = 0; i < str.size(); i++) {
    if (str[i] == 'v')
      sum++;
    else
      sum += 2;
  }
  cout << sum << endl;
  return 0;
}
