// Calculate x = n/p + n/(p^2) + n/(p^3) + ....
int largestPower(int n, int p){
  int ans = 0;
  while (n){
    n /= p;
    ans += n;
  }
  return ans;
}
