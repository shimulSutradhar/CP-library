// n points are given you have to traverse all the point Start traversing from point 0 and return at point 0. find out minimum cost.
struct point{
    int x = 0; 
    int y = 0;
    point(int x = 0, int y = 0):x(x), y(y){}
};
inline int dist(point a, point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int memo[1 << 11] [11];
int tsp(){
    vector<point> points;
    for(int i = 0; i < (1 << n); i++){
    	for(int j = 0; j < n; j++){
    		memo[i] [j] = (int)1e5 + 7;
    	}
    }
    memo[0] [0] = 0;
    for(int mask = 0; mask < (1 << n); mask++){
    	for(int prev = 0; prev < n; prev++){
    		for(int i = 0; i < n; i++){
    			if(!(mask & (1 << i))){
    				memo[mask | (1 << i)] [i] = min(memo[mask | (1 << i)] [i], memo[mask] [prev] + dist(points[i], points[prev]));
    			}
    		}
    	}
    }
    int ans = (int)1e5 + 7;
    for(int i = 0; i < n; i++){
    	ans = min(ans, memo[(1 << n) - 1] [i] + dist(points[i], points[0]));
    }
    return ans;
}
