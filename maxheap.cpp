#include "maxheap.h"
using namespace std;

maxheap::maxheap(int k):max_num_of_scores(k),cur_num_of_scores(0)
{
    heap =new double[max_num_of_scores];
    ids=new int[max_num_of_scores];
}

void maxheap::swap_scores(int ind1,int ind2)
{
    double temp=0.0;
    temp=heap[ind1];
    int temp_id=ids[ind1];
    heap[ind1]=heap[ind2];
    heap[ind2]=temp;
    ids[ind1]=ids[ind2];
    ids[ind2]=temp_id;
}

int maxheap::mini_index(int low,int high)
{
    int min=-1;
    double min_score=1000000.0;
    for(int i=low;i<high;i++)
    {
        if(heap[i]<min_score)
        {
            min=i;
            min_score=heap[i];
        }
    }
    return min;
}

void maxheap::insert(double score,int id)
{
    int index;
    if(cur_num_of_scores!=max_num_of_scores)
    {
        index=cur_num_of_scores;
        cur_num_of_scores++;
    }
    else
    {
        int temp_ind=mini_index(max_num_of_scores/2,max_num_of_scores);
        if(score>temp_ind)
        index=temp_ind;
        else
        return;
    }
    heap[index]=score;
    ids[index]=id;
    while(heap[index]>heap[(index-1)/2])
    {
        swap_scores(index,((index-1)/2));
        index=(index-1)/2;
    }
}

int maxheap::max_child(int num1,int num2)
{
    if(num1<cur_num_of_scores&&num2<cur_num_of_scores)
    {
        if(heap[num1]>heap[num2])
        return num1;
        else
        return num2;
    }
    else if(num1<cur_num_of_scores)
    return num1;
    else if(num1<cur_num_of_scores)
    return num2;
    else
    return -1;
}

double maxheap::remove()
{
    int index=0,chosen_child;
    double return_val=0.0;
    if(cur_num_of_scores>0)
    {
        return_val=heap[0];
        cur_num_of_scores--;
        heap[0]=heap[cur_num_of_scores];
        ids[0]=ids[cur_num_of_scores];
        while(1)
        {
            chosen_child=max_child(2*index+1,2*index+2);
            if(chosen_child!=-1&&heap[chosen_child]>heap[index])
            {
                swap_scores(chosen_child,index);
                index=chosen_child;
            }
            else
            break;
        }
    }
    return return_val;
}
