#define maxN  100007
int mob[maxN];
void mobious(){
    int i, j;
    for(i = 0; i < maxN; i++){
        mob[i] = 1;
    }
    for(i = 2; i < maxN; i++){
        if(!mark[i]){
            mob[i] *= -1;
            for(j = i + i; j < maxN; j += i){
                mark[j] = true;
                mob[j] *= j % (i * i) ? -1 : 0;
            }
        }
    }
}
