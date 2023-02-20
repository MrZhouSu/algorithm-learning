#include <iostream>
#include <string>
#define ll long long
using namespace std;

string ch[10];
string a = "RRRRRRRR";
string b = "BBBBBBBB";
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--) {
    for (int i = 0; i < 8; i++) {
      cin >> ch[i];
    }
    char c;
    bool flag = false;
    for (int i = 0; i < 8; i++) {
      if (ch[i] == a) {
        flag = true;
        cout << "R" << endl;
        break;
      }
      // else if (ch[i] == b)
      // {
      //     flag = true;
      //     cout << "B" << endl;
      //     break;
      // }
    }
    if (!flag) cout << "B" << endl;
    // for (int j = 0; j < 8; j++)
    // {
    //     if (ch[0][j] == '.' || ch[0][j] == 'R')
    //     {
    //         continue;
    //     }
    //     bool tg = true;
    //     for (int i = 1; i < 8; i++)
    //     {
    //         if (ch[i][j] != ch[0][j])
    //         {
    //             tg = false;
    //             break;
    //         }
    //     }
    //     if (tg)
    //     {
    //         cout << ch[0][j] << endl;
    //         break;
    //     }
    // }
  }
  return 0;
}
