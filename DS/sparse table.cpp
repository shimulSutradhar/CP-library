//sparse table
const int MAX = 100007;
int st[MAX] [20], logs[MAX];
template <typename t>
t f(t a, t b){
  // operation
}

void preprocess( ){
  for(int i = 2; i < MAX; i++){
    logs[i] = logs[i / 2] + 1;
  }
}

void build(int n){
  for(int i = 0; i <= n; i++){
    st[i] [0] = i; // assign value
  }
  for(int i = 1; i <= logs[n]; i++){
    for(int j = 0; j + (1 << i) <= n; j++){
      st[j] [i] = f(st[j] [i - 1], st[j + (1 << (i - 1))] [i - 1]);
    }
  } 
}

int queary(int l, int r){
  if(l > r){
    swap(l, r);
  }
  int k = logs[r - l + 1];
  return f(st[l] [k], st[r - (1 << k) + 1] [k]);
}
