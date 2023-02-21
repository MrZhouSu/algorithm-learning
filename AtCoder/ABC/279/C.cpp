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

const int N = 4e5 + 10;

bool st[N];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll h, w;
  cin >> h >> w;

  multiset<string> st, stt;

  char s1[h][w];
  char s2[h][w];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s1[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s2[i][j];
    }
  }

  vector<string> v(w, "");

  for (int j = 0; j < w; j++) {
    string str;
    for (int i = 0; i < h; i++) {
      str += s1[i][j];
    }
    st.emplace(str);
  }
  bool flag = true;
  for (int j = 0; j < w; j++) {
    string str;
    for (int i = 0; i < h; i++) {
      str += s2[i][j];
    }
    stt.emplace(str);
  }
  if (st == stt)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
