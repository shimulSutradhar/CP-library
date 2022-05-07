// Tested : UVA 11526 - H(n)
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int main( ) {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
  	i64 n;
  	scanf("%lld", &n);
  	i64 ans = 0;
  	for (i64 i = 1; i * i <= n; i++) {
  		i64 hi = n / i;
  		i64 lo = n / (i + 1);
  		// here i quotient (hi - lo) is frequency of i in floors sum(n / i)
  		ans += i * (hi - lo);
  		i64 j = n / i;
  		if (i * i < n && j > i) {
  			hi = n / j;
  			lo = n / (j + 1);
  			ans += j * (hi - lo);
  		}
  	}
  	printf("%lld\n", ans);
  }
  return 0;
}
