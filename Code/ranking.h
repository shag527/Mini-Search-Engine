#include<bits/stdc++.h>
#ifndef RANKING_H
#define RANKING_H
#include "trie_list.h"
#include "scorelist.h"
using namespace std;

class Trie
{
    Trie *sibling;
    Trie *child;
    char val;
    list_node* list;
    public:
        Trie();
        ~Trie();
        void insert(char *token,int id);
        int tf_search_word(int id,char* word,int cur);
        int df_search_word(char* word,int cur);
        void search_all(char* buffer,int cur);
        void search(char* word,int cur, score_list* scorelist);
};

#endif
