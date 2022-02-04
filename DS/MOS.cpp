#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7;
int SIZE, queary, arr[MAX], fre[MAX], ans[MAX];
struct node{
	int left = 0;
	int right = 0;
	int ind = 0;
	int bucket_number = 0;
	node(int left = 0, int right = 0, int ind = 0):left(left), right(right), ind(ind){
		bucket_number = left / SIZE;
	}
	bool operator<(const node& v) const{
		if(bucket_number == v.bucket_number){
			if(bucket_number % 2)
				return right > v.right;
			return right < v.right;
		}
		return bucket_number < v.bucket_number;
	}
};
void add(int ind){
	++fre[arr[ind]];
	if(fre[arr[ind]] == 1) ++queary;
}
void rem(int ind){
	--fre[arr[ind]];
	if(!fre[arr[ind]]) --queary;
}
vector<node> q;
int m;
void MOS(){
	sort(q.begin(), q.end());
	queary = 0;
	unsigned l = 0, r = 0;
	add(l);
	for(unsigned i = 0; i < m; i++){
		while(l < q[i].left){
			rem(l), l++;
		}
		while(l > q[i].left){
			l--, add(l);
		}
		while(r < q[i].right){
			r++, add(r);
		}
		while(r > q[i].right){
			rem(r), r--;
		}
		ans[q[i].ind] = queary;
	}
}
int main(){
    int n, l, r;
	scanf("%d", &n);
	SIZE = sqrt(n * 1.0);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &l, &r);
		q.emplace_back(node(l - 1, r - 1, i));
	}
	MOS();
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
