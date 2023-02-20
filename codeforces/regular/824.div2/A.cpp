#include <iostream>
#define ll long long
using namespace std;

int main(void) {
  int t;

  scanf("%d", &t);

  while (t--) {
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", n / 3 - 2);
  }

  return 0;
}

// a+b+c=x;
// a<b<c;

// b-a=x-a-c-a=x-2*a-c;
// c-b=c-(x-a-c)=c*2+a-x;
