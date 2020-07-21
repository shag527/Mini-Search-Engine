#include<bits/stdc++.h>


#ifndef TRIE_LIST_H
#define TRIE_LIST_H
class list_node
{
    list_node *next;
    int id;
    int times;
    public:
        list_node(int doc_id):id(doc_id),times(0){next=NULL;}
        ~list_node();
        void add(int doc_id);
        int search(int doc_id);
        int volume();

};
#endif
