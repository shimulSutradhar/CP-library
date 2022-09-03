#include <bits/stdc++.h>
using namespace std;
const int MAX = 30007;
int arr[MAX], l_cover[MAX], r_cover[MAX];
int main( ){
  int tc, n;
  scanf("%d", &tc);
  for (int ca = 1; ca <= tc; ca++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }
    stack<int> st;
    for (int i = 1; i <= n; i++) {
      while (!st.empty( ) && arr[i] < arr[st.top( )]) {
        r_cover[st.top( )] = i - 1;
        st.pop( );
      }
      st.emplace(i);
    }
    while (!st.empty( )) {
      r_cover[st.top( )] = n;
      st.pop( );
    }
    for (int i = n; i > 0; i--) {
      while (!st.empty( ) && arr[i] < arr[st.top( )]) {
        l_cover[st.top( )] = i + 1;
        st.pop( );
      }
      st.emplace(i); 
    }
    while (!st.empty( )) {
      l_cover[st.top( )] = 1;
      st.pop( );
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      long long k = r_cover[i] - l_cover[i] + 1;
      ans = max(ans, k * arr[i]);
    }
    printf("Case %d: %lld\n", ca, ans);
  }
  return 0;
}
