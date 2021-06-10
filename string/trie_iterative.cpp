const int ALPHABET = 26;
const int MAX = 1e6 + 7;
int trie[MAX][ALPHABET];
bool isEnd[MAX];
int node;
void insert(string a){
    int now = 0;
    for(int i = 0; a[i]; i++){
        if(trie[now] [cmap[a[i]]] == -1){
            trie[now] [cmap[a[i]]] = ++node;
            for(int j = 0; j < ALPHABET; j++){
                trie[node] [i] = -1;
            }
        }
        now = trie[now] [cmap[a[i]]];
    }
    isEnd[now] = true;
}
