#include<bits/stdc++.h>
#ifndef SCORELIST_H
#define SCORELIST_H

class score_list
{
    int id;
    score_list *next;
    public:
        score_list(int doc_id=-1):id(doc_id){next=NULL;}
        ~score_list();
        void insert(int doc_id);
        score_list* get_next(){return next;}
        int get_id(){return id;}
};

#endif
