
#include<bits/stdc++.h>
#ifndef MAXHEAP_H
#define MAXHEAP_H

class maxheap
{
    double *heap;
    int *ids;
    int cur_num_of_scores;
    int max_num_of_scores;
    void swap_scores(int ind1,int ind2);
    int mini_index(int low,int high);

    public:
    maxheap(int k);
    ~maxheap(){delete heap; delete ids;}
    void insert(double score,int id);
    int max_child(int num1,int num2);
    double remove();
    int get_id(){return ids[0];}
};

#endif
