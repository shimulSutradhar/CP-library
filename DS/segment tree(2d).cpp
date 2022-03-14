#include<bits/stdc++.h>
using namespace std;
const int M = 1003;
const int MAX = 4000000 + 7;
int arr[M] [M];
int tree[MAX];
void build(int at, int x1, int x2, int y1, int y2, int depth){
	if(x1 == x2 && y1 == y2){
		tree[at] = arr[x1] [y1];
		return;
	}
	if(x1 == x2 && depth % 2 == 0) ++depth;
	if(y1 == y2 && depth % 2 == 1) ++depth;
	if(depth % 2 == 0 ){
		int mid = (x1 + x2) >> 1;
		build(2 * at,          x1, mid, y1, y2, depth + 1);
		build(2 * at + 1, mid + 1,  x2, y1, y2, depth + 1);
	}else{
		int mid = (y1 + y2) >> 1;
		build(    2 * at, x1, x2,      y1, mid, depth + 1);
		build(2 * at + 1, x1, x2, mid + 1,  y2, depth + 1);
	}
	tree[at] = tree[2 * at] + tree[2 * at + 1];
}

int queary(int at, int x1, int x2, int y1, int y2, int depth, int a1, int a2, int b1, int b2){
	if(x2 < a1 || a2 < x1 || b2 < y1 || y2 < b1) return 0;
	if(a1 <= x1 && x2 <= a2 && b1 <= y1  && y2 <= b2){
		return tree[at];
	}
	if(x1 == x2 && depth % 2 == 0) ++depth;
	if(y1 == y2 && depth % 2 == 1) ++depth;
	int x = 0, y = 0;
	if(depth % 2 == 0 ){
		int mid = (x1 + x2) >> 1;
		x = queary(2 * at,          x1, mid, y1, y2, depth + 1, a1, a2, b1, b2);
		y = queary(2 * at + 1, mid + 1,  x2, y1, y2, depth + 1, a1, a2, b1, b2);
	}else{
		int mid = (y1 + y2) >> 1;
		x = queary(    2 * at, x1, x2,      y1, mid, depth + 1, a1, a2, b1, b2);
		y = queary(2 * at + 1, x1, x2, mid + 1,  y2, depth + 1, a1, a2, b1, b2);
	}
	return x + y;
}
void update(int at, int x1, int x2, int y1, int y2, int depth, int a, int b, int val){
	if(a < x1 || x2 < a || b < y1 || y2 < b) return;
	if(x1 == x2 && y1 == y2){
		tree[at] = arr[x1] [y1] = val;
		return;
	}
	if(x1 == x2 && depth % 2 == 0) ++depth;
	if(y1 == y2 && depth % 2 == 1) ++depth;
	if(depth % 2 == 0 ){
		int mid = (x1 + x2) >> 1;
		update(2 * at,          x1, mid, y1, y2, depth + 1, a, b, val);
		update(2 * at + 1, mid + 1,  x2, y1, y2, depth + 1, a, b, val);
	}else{
		int mid = (y1 + y2) >> 1;
		update(    2 * at, x1, x2,      y1, mid, depth + 1, a, b, val);
		update(2 * at + 1, x1, x2, mid + 1,  y2, depth + 1, a, b, val);
	}
	tree[at] = tree[2 * at] + tree[2 * at + 1];
}
int main( ){
	// build(1, 1, n, 1, n, 0);
	// queary(1, 1, n, 1, n, 0, x1, x2, y1, y2);
	// update(1, 1, n, 1, n, 0, x, y, val);
	return 0;
}
