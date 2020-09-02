#include "scorelist.h"
using namespace std;

score_list::~score_list()
{
    if(next!=NULL)
    delete next;
}

void score_list::insert(int doc_id)
{
    if(id==doc_id)
    return;
    if(id==-1)
    id=doc_id;
    else
    {
        if(next==NULL)
        next=new score_list(doc_id);
        else
        next->insert(doc_id);
    }
}
