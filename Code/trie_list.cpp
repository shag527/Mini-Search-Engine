#include "trie_list.h"

list_node::~list_node()
{
    if(next!=NULL)
    {
        delete next;
    }
}
void list_node::add(int doc_id)
{
    if(doc_id==id)
    times++;
    else
    {
        if(next==NULL)
        next=new list_node(doc_id);
        next->add(doc_id);
    }
}

int list_node::search(int doc_id)
{
    if(doc_id==id)
    return times;
    else
    {
        if(next==NULL)
        return 0;
        else
        return next->search(doc_id);
    }
}

int list_node::volume()
{
    if(next!=NULL)
    return 1+next->volume();
    else
    return 1;
}

void list_node::pass_documents(score_list *scorelist)
{
    scorelist->insert(id);
    if(next!=NULL)
    next->pass_documents(scorelist);
}
