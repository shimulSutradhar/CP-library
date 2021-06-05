const int ALPHABET = 26;
struct trie{
    trie *next[ALPHABET];
    int cnt = 0;
    bool isEnd = false;
    trie(){
        for(int i = 0; i < ALPHABET; i++){
            next[i] = NULL;
        }
        cnt = 0;
        isEnd = false;
    }
}*root;
void insert(string a){
    trie *temp = root;
    for(int i = 0; a[i]; i++){
        if(temp->next[a[i] - 'A'] == NULL){
            temp-> next[a[i] - 'A'] = new trie();
        }
        temp = temp->next[a[i] - 'A'];
        ++temp->cnt;
    }
    temp->isEnd = true;
}
