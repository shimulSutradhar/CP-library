// Tasted: LOJ-1255
#include<bits/stdc++.h>
using namespace std;
namespace kmp{
    const int MAX = 1e6 + 7;
    int plen, pi[MAX];
    char p[MAX], str[MAX];
    void lps( ){
        pi[0] = 0;
        for(plen = 1; p[plen]; plen++){
            int now = pi[plen - 1];
            while(now > 0 && p[plen] != p[now]){
                now = pi[now - 1];
            }
            if(p[plen] == p[now]){
                ++now;
            }
            pi[plen] = now;
        }
    }
    int kmpSearch(){
        int ans = 0;
        int now = 0; 
        for(int i = 0; str[i]; i++){
            while(now > 0 && str[i] != p[now]){
                now = pi[now - 1];
            }
            if(p[now] == str[i]){
                ++now;
            }
            if(now == plen){
                ++ans;
                now = pi[now - 1];
            }
        }
        return ans;
    }
}
