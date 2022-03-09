// tested: https://codeforces.com/contest/855/problem/E
#include<bits/stdc++.h>
using namespace std;
using i64 = long long int;
bool mark[65] [1 << 10] [11];
i64 dp[65] [1 << 10] [11];
i64 DP(int at, int mask, int base){
	if(at <= 0){
		return at == 0 && mask == 0;
	}
	if(mark[at] [mask] [base]) return dp[at] [mask] [base];
	i64 k = 0;
	for(int i = 0; i < base; i++){
		k += DP(at - 1, mask ^ (1 << i), base);
	}
	mark[at] [mask] [base] = true;
	return dp[at] [mask] [base] = k;
}
string num;
int len;
i64 DFS(int at, int mask, int base){
	if(at == len){
		return mask == 0;
	}
	int digit = num[at] - '0';
	i64 k = DFS(at + 1, mask^(1 << digit), base); 
	for(int i = at == 0 ? 1 : 0; i < digit; i++){
		k += DP(len - (at + 1), mask ^ (1 << i), base);
	}
	return k;
}
i64 solved(i64 n, int base){
	if(n == 0) return 0;
	num.clear();
	while(n){
		char c = n % base + '0';
		num = num + c;
		n /= base;
	}
	reverse(num.begin(), num.end());
	len = num.size();
	i64 k = DFS(0, 0, base);
	for(int i = 0; i < len - 1; i++){
		for(int j = 1; j < base; j++){
			k += DP(i, 1 << j, base);
		}
	}
	return k;
}
int main( ){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		int base;
		i64 l, r;
		scanf("%d %lld %lld", &base, &l, &r);
		i64 ans = solved(r, base) - solved(l - 1, base);
		printf("%lld\n", ans);
	}
	return 0;
}
