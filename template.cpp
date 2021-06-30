#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("no-stack-protector")
 
#if defined(ONLINE_JUDGE)
    #pragma GCC target("aes,avx,avx2,avx512f,avx512dq,avx512cd,avx512bw,avx512vl,f16c,fma,mmx,pclmul,popcnt,rdrnd,sse,sse2,sse3,sse4.1,sse4.2,ssse3")
#endif

#include<bits/stdc++.h>
using namespace std;

#define all(c)              c.begin(), c.end()
#define clr(x,y)            memset(x,y,sizeof x)
#define to_lower(x)         transform(x.begin(), x.end(), x.begin(), ::tolower)
#define to_upper(x)         transform(x.begin(), x.end(), x.begin(), ::toupper)
#define lcm(x, y)           (x * y) / __gcd(x, y)  

int dr[] = {-1, 0, 1,  0};
int dc[] = { 0, 1, 0, -1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int hr[] = {1, 1, 2, 2,-1,-1,-2,-2};
int hc[] = {2,-2, 1,-1, 2,-2, 1,-1};

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

template<typename T>T power(T n, T p){ T res = 1;while(p > 0){if(p & 1)res *= n;n *= n;p >>= 1;}return res;}
template<typename T>T bigmod(T n, T p, T m){n %= m;T res = 1;while(p > 0){if(p & 1)res = res * n % m;n = n * n % m;p >>= 1;}return res;}

int main( ){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
