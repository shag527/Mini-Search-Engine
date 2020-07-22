#include "search.h"
using namespace std;
const float k1=1.2;
const float b=0.75;

void search(char* token, Trie *trie, Map *obj,int k)
{
    char arr[10][256];
    double idf[10];
    token=strtok(NULL," \t\n");
    score_list* scorelist=new score_list();
    int i;
    for(i=0;i<10;i++)
    {
        if(token==NULL)
        break;
        strcpy(arr[i],token);
        idf[i]=log10(((double)obj->get_doc_size()-(double)trie->df_search_word(arr[i],0)+0.5)/((double)trie->df_search_word(arr[i],0)+0.5));
        trie->search(arr[i],0,scorelist);
        token=strtok(NULL," \t\n");
    }
    double avg=0;
    for(int m=0;m<obj->get_doc_size();m++)
    {
        avg+=(double)obj->get_length(m);
    }
    avg/=(double)obj->get_doc_size();
    double score=0;
    score_list* temp=scorelist;
    maxheap *heap=new maxheap(k);
    int ceil=0;
    while(temp!=NULL)
    {
        for(int l=0;l<i;l++)
        {
            score+=idf[l]*((double)trie->tf_search_word(temp->get_id(),arr[l],0)*(k1+1.0))/((double)trie->tf_search_word(temp->get_id(),arr[l],0)+k1*(1.0-b+b*(double)obj->get_length(temp->get_id())/(double)avg));
            //score+=idf[l]*((double)trie->tf_search_word(temp->getid(),warray[l],0)*(k1+1.0))/((double)trie->tfsearchword(templist->getid(),warray[l],0)+k1*(1.0-b+b*(double)map->getlength(templist->getid())/(double)avgdl));
        }
        //cout<<"1\n";
        heap->insert(score,temp->get_id());
        score=0;
        temp=temp->get_next();
        ceil++;
    }
    if(ceil>k)
    ceil=k;
    struct winsize w;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
    for(int l=0;l<ceil;l++)
    {
        int id=heap->get_id();
        if(id==1)
        break;
        double score=(double)heap->remove();
        cout<<"("<<id;
        int x=10;
        int f=1;
        while(id/x!=0)
        {
            x*=10;
            f++;
        }
        while(5-f>=0)
        {
            cout<<" ";
            f++;
        }
        printf(")[%10.6f]",score);
        char* line=new char[obj->get_buffer_size()];
        strcpy(line,obj->get_document(id));
        char *temp=strtok(line," \t\n");
        int cur_length=0;
        int counter=0;
        int new_line=1;
        int line_flag=0;
        int underline[2][100],u_counter=0;
        while(temp!=NULL)
        {
            if(new_line)
            {
                cur_length+=20;
                if(counter!=0)
                {
                    for(int c=0;c<20;c++)
                    {
                        cout<<" ";
                    }
                }
                new_line=0;
            }

            for(int n=0;n<i;n++)
            {
                if(!strcmp(arr[n],temp))
                {
                    if(cur_length+strlen(temp)+1<=w.ws_col)
                    {
                        underline[0][u_counter]=cur_length;
                        underline[1][u_counter]=strlen(temp);
                        u_counter++;
                        line_flag=1;
                    }
                    break;
                }
            }
            cur_length+=strlen(temp)+1;
            if(cur_length-1>=w.ws_col)
            {
                cur_length=0;
                new_line=1;
                cout<<endl;
                if(line_flag)
                {
                    char *output_line=new char[w.ws_col+1];
                    for(int j=0;j<w.ws_col;j++)
                    {
                        output_line[j]=' ';
                    }
                    output_line[w.ws_col]='\0';
                    line_flag=0;
                    for(int j=0;j<u_counter;j++)
                    {
                        for(int v=underline[0][j];v<underline[0][j]+underline[1][j];v++)
                        output_line[v]='^';
                    }
                    u_counter=0;
                    cout<<output_line;
                    delete[] output_line;
                }
                continue;
            }
            cout<<temp<<" ";
            temp=strtok(NULL," \t\n");
            counter++;
        }
        cout<<endl;
        delete line;
        delete temp;
    }
    delete heap;
    delete scorelist;
    cout<<endl;
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
