const int MAX = 10000001;
int prime[MAX], p_index;
bool mark[MAX];
void sieve( ){
  int maxN = sqrt(MAX * 1.0) + 2;
  mark[0] = mark[1] = true;
  prime[p_index++] = 2;
  prime[p_index++] = 3;
  for(int i = 4; i < MAX; i += 2){
    mark[i] = true;
  }
  for(int i = 9; i < MAX; i += 6){
    mark[i] = true;
  }
  for(int i = 5; i < MAX; i += 6){
    if(!mark[i]){
      prime[p_index++] = i;
      if(i <= maxN){
        for(int j = i * i; j < MAX; j += i * 2){
          mark[j] = true;               
        }
      }
    }
    if(!mark[i + 2]){
      int x = i + 2;
      prime[p_index++] = x;
      if(x <= maxN){
        for(int j = x * x; j < MAX; j += 2 * x){
          mark[j] = true;
        }
      }
    }
  }
}
