#include "search.h"
using namespace std;

void search(char* token, Trie *trie, Map *obj,int k)
{
    cout<<"ND YET\n";
}
void df(Trie *trie)
{
    char *token_;
    token_=strtok(NULL," \t\n");
    if(token_!=NULL)
    {
        cout<<token_<<" "<<trie->df_search_word(token_,0)<<endl;
    }
    else
    {
        char *buffer=new char[256];
        memset(buffer,'\0',256);
        trie->search_all(buffer,0);
        delete[] buffer;
    }
    token_=NULL;
    delete token_;
}
int tf(char* token, Trie *trie)
{
    char* token_;
    token_=strtok(NULL," \t\n");
    if(token_==NULL)
    {
        delete token_;
        return -1;
    }
    for(int l=0;l<strlen(token_);l++)
    {
        if(!isdigit(token_[l]))
        {
            token_=NULL;
            delete token_;
            return -1;
        }
    }
    int id=atoi(token_);
    token_=strtok(NULL," \t\n");
    if(token_==NULL)
    {
        delete token_;
        return -1;
    }
    cout<<id<<" "<<token_<<" "<<trie->tf_search_word(id,token_,0)<<endl;
    return 1;
}
