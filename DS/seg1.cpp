#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)5e5 + 700;
struct node{
    long long sum;
    long long lazyVal;
    bool isLazy;
    node(long long sum = 0, long long lazyVal = 0, bool isLazy = false):sum(sum), lazyVal(lazyVal), isLazy(isLazy){};
}tree[4 * maxN];

void popagation(int at, int left, int right){
    if(!tree[at].isLazy) return;
    int mid = (left + right) >> 1;
    tree[at << 1].sum += (long long)(mid - left + 1) * tree[at].lazyVal;
    tree[at << 1].lazyVal += tree[at].lazyVal;
    tree[at << 1].isLazy = true;
    tree[at << 1 | 1].sum += (long long)(right - mid) * tree[at].lazyVal;
    tree[at << 1 | 1].lazyVal += tree[at].lazyVal;
    tree[at << 1 | 1].isLazy = true;
    tree[at].lazyVal = 0;  
    tree[at].isLazy = false;  
}
void build(int at, int left, int right){
    if(left == right){
        tree[at] = node(0, 0, false);
        return;
    }
    int mid = (left + right) >> 1;
    build(at << 1, left, mid);
    build(at << 1 | 1, mid + 1, right);
    tree[at] = node(0, 0, false);
}
long long queary(int at, int left, int right, int l, int r){
    if(r < left or right < l){
        return 0;
    }
    if(l <= left and right <= r){
        return tree[at].sum;
    }
    popagation(at, left, right);
    int mid = (left + right) >> 1;
    long long x = queary(at << 1, left, mid, l, r); 
    long long y = queary(at << 1 | 1, mid + 1, right, l, r); 
    return x + y;
}
void update(int at, int left, int right, int l, int r, long long val){
    if(r < left or right < l)
        return;
    if(l <= left and right <= r){
        tree[at].sum += (long long)(right - left + 1) * val;
        tree[at].lazyVal += val;
        tree[at].isLazy = true;
        return;
    }
    popagation(at, left, right);
    int mid = (left + right) >> 1;
    update(at << 1, left, mid, l, r, val);
    update(at << 1 | 1, mid + 1, right, l, r, val);
    tree[at].sum = tree[at << 1].sum + tree[at << 1 | 1].sum;
}

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tt, ca = 1;
    scanf("%d", &tt);
    while(tt--){
        int n, q;
        printf("Case %d:\n", ca++);
        scanf("%d %d", &n, &q);
        build(1, 1, n);
        while(q--){
            int c, l, r;
            long long val;
            scanf("%d", &c);
            if(c == 0){
                scanf("%d %d %lld", &l, &r, &val);
                ++l, ++r;
                update(1, 1, n, l, r, val);
            }else{
                scanf("%d %d", &l, &r);
                ++l, ++r;
                long long ans = queary(1, 1, n, l, r);
                printf("%lld\n", ans);
            }
        }
    }   
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
