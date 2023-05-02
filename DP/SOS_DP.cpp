#include <bits/stdc++.h>
using namespace std;

const int MAX(1 << 20);
const int MOD(1000000007);
int dp[MAX], p[MAX];

int main( ) {
  int n, m, vim = 0, sub_mask, re;

  p[0] = 1;
  for (int i = 1; i < MAX; i++) {
    p[i] = (2 * p[i - 1]) % MOD;
  }
  for (int i = 0; i < MAX; i++) {
    p[i] = (p[i] - 1 + MOD) % MOD;
  }
  for (int i = 0; i < 20; i++) {
    for (int mask = 0; mask < MAX; mask++) {
      if (mask & 1 << i) {
        dp[mask] = dp[mask] + dp[mask ^ 1 << i];
      }
    }
  }

  for (int mask = 0; mask < MAX; mask++) { 
    dp[mask] = p[dp[mask]];
  }

  for (int i = 0; i < 20; i++) {
    for (int mask = 0; mask < MAX; mask++) {
      if (mask & (1 << i)) {
        dp[mask] = (dp[mask] - dp[mask ^ 1 << i] + MOD) % MOD;
      }
    }
  }
    // number of subset with mask i is dp[i]
  return 0;
}
