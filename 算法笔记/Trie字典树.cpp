#include <bits/stdc++.h>
using namespace std;

//take storing alpbate for example
const int SIZE = 10e3;        // SIZE is the max num trie can store
int tries[SIZE][26];        // use two-dimensional arrays 
int tot = 1;
bool eow[SIZE];

void insert(char* str) {
    int len = strlen(str);
    int p = 1;
    for(int i = 0; i < len; i++) {
        int ch = str[i] - 'a';
        if(tries[p][ch] == 0) 
            tries[p][ch] = ++tot;
        p = tries[p][ch];
    }
    eow[p] = true;
}

bool search(char* str) {
    int len = strlen(str);
    int p = 1;
    for(int i = 0; i < len; i++) {
        p = tries[p][str[i]-'a'];
        if(p == 0)
            return false;
    }
    return true;
}

// test
int main() {
    memset(tries, 0, sizeof tries);
    char str[10] = "test";
    insert(str);
    if(search(str))
        cout << "yes" << endl;
    char str2[10] = "what";
    if(!search(str2))
        cout << "yes" << endl;
}