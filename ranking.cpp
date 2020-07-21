#include "ranking.h"

Trie::Trie():val(-1)
{
    sibling=NULL;
    child=NULL;
    list=NULL;
}

Trie::~Trie()
{
    if(list!=NULL)
    delete list;
    if(child!=NULL)
    delete child;
    if(sibling!=NULL)
    delete sibling;
}

void Trie::insert(char *token, int id)
{
    if(val==-1||val==token[0])
    {
        val=token[0];
        if(strlen(token)==1)
        {
            if(list==NULL)
            list=new list_node(id);
            list->add(id);
        }
        else
        {
            if(child==NULL)
            child=new Trie;
            child->insert(token+1,id);
        }
    }
    else
    {
        if(sibling==NULL)
        sibling=new Trie;
        sibling->insert(token,id);
    }
}

int Trie::tf_search_word(int id,char* word,int cur)
{
    if(word[cur]==val)
    {
        if(cur==strlen(word)-1)
        {
            if(list!=NULL)
            return list->search(id);
            else
            return 0;
        }
        else
        {
            if(child!=NULL)
            return child->tf_search_word(id,word,cur+1);
            else
            return 0;
        }
    }
    else
    {
        if(sibling!=NULL)
        return sibling->tf_search_word(id,word,cur);
        else
        return 0;
    }
}

int Trie::df_search_word(char* word,int cur)
{
    if(word[cur]==val)
    {
        if(cur==strlen(word)-1)
        {
            if(list!=NULL)
            return list->volume();
            else
            return 0;
        }
        else
        {
            if(child!=NULL)
            return child->df_search_word(word,cur+1);
            else
            return 0;
        }
    }
    else
    {
        if(sibling!=NULL)
        return sibling->df_search_word(word,cur);
        else
        return 0;
    }
}

void Trie::search_all(char* buffer,int cur)
{
    buffer[cur]=val;
    if(list!=NULL)
    cout<<buffer<<" "<<list->volume()<<endl;
    if(child!=NULL)
    child->search_all(buffer,cur+1);
    if(sibling!=NULL)
    sibling->search_all(buffer,cur);
    buffer[cur]='\0';

}
