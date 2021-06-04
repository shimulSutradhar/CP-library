// tested: uva 353 - Pesky Palindromes
// hashing
// getForwardHash(l...r)   = forwardHash[r] - forwardHash[l - 1] * base ^ (r - l + 1);
// getBackwardHash(l...r)  = backwardHash[l] - backwardHash[r + 1] * base ^ (r - l + 1);
#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int MAX = 100009;
i64 mods[2] = {1000000007, 1000000009};
//Some back-up primes: 1072857881, 1066517951, 1040160883
i64 bases[2] = {137, 281};
i64 powBase[2][MAX];
void procedure(){
    powBase[0] [0] = powBase[1] [0] = 1;
    for(int i = 1; i < MAX; i++){
        powBase[0] [i] = (powBase[0] [i - 1] * bases[0]) % mods[0];
        powBase[1] [i] = (powBase[1] [i - 1] * bases[1]) % mods[1];
    }
}
struct hashing{
    i64 forwardHash[2] [MAX];
    i64 backwardHash[2] [MAX];
    string str;
    int len;
    hashing(string _str){
        str = _str;
        len = str.length() - 1;
        for(int i = 0; i <= len + 5; i++){
            forwardHash[0] [i] = 0;
            forwardHash[1] [i] = 0;
            backwardHash[0] [i] = 0;
            backwardHash[1] [i] = 0;
        }
        Build();
    }
    void Build(){
        forwardHash[0] [0] = str[0];
        forwardHash[1] [0] = str[0];
        backwardHash[0] [len] = str[len];
        backwardHash[1] [len] = str[len];
        for(int i = 1, j = len - 1; i <= len; i++, j--){
            forwardHash[0] [i] = (forwardHash[0] [i - 1] * bases[0] + str[i]) % mods[0];
            forwardHash[1] [i] = (forwardHash[1] [i - 1] * bases[1] + str[i]) % mods[1];
            backwardHash[0] [j] = (backwardHash[0] [j + 1] * bases[0] + str[j]) % mods[0];
            backwardHash[1] [j] = (backwardHash[1] [j + 1] * bases[1] + str[j]) % mods[1];
        }
    }
    pair<i64, i64> getForwardHash(int left, int right){
        assert(left <= right);
        i64 ans[2];
        for(int i = 0; i < 2; i++){
            ans[i] = forwardHash[i] [right];
            if(left > 0){
                ans[i] -= (forwardHash[i] [left - 1] * powBase[i] [right - left + 1]) % mods[i];
                if(ans[i] < 0){
                    ans[i] += mods[i];
                }
            }
        }
        return {ans[0], ans[1]};
    }
    pair<i64, i64> getBackwardHash(int left, int right){
        assert(left <= right);
        i64 ans[2];
        for(int i = 0; i < 2; i++){
            ans[i] = backwardHash[i] [left];
            if(right < len){
                ans[i] -= (backwardHash[i] [right + 1] * powBase[i] [right - left + 1]) % mods[i];
                if(ans[i] < 0){
                    ans[i] += mods[i];
                }
            }
        }
        return {ans[0], ans[1]};
    }
};
