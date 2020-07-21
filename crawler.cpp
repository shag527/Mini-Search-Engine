#include "crawler.h"
using namespace std;
int get_file_size(long int* num_of_lines, long int* max_length, char* text_file)
{
    FILE *file=fopen(text_file,"r");
    if (file!=NULL)
    {
        char *line=NULL;
        size_t buffer=0;
        int cur_length;
        while(-1!=(cur_length=getline(&line,&buffer,file)))
        {
             if(*max_length<cur_length)
             {
                 *max_length=cur_length;
             }
             //cout<<*num_of_lines<<endl;
             (*num_of_lines)++;
             delete line;
             line=NULL;
             buffer=0;
        }
        fclose(file);
        delete line;
        if(*num_of_lines==0 || *max_length<3)
        {
            cout<<"Nothing to check!"<<endl;
            return -1;
        }
        return 1;
    }
    else
    {
        cout<<"Error opening file"<<endl;
        return -1;
    }
}

void split(char* temp, int id, Trie *trie, Map *obj)
{
    char *token;
    token=strtok(temp," \t");
    int i=0;
    while(token!=NULL)
    {
        i++;
        trie->insert(token,id);
        token=strtok(NULL," \t");
    }
    obj->set_length(id,i);
    delete token;
}

int read_input(Map *obj, Trie *trie, char* doc_file)
{
    FILE *file=fopen(doc_file,"r");
    char* line=NULL;
    size_t buffer=0;
    int cur_length;
    char* temp=new char[obj->get_buffer_size()];
    for(int i=0;i<obj->get_doc_size();i++)
    {
        getline(&line,&buffer,file);
        //cout<<"gl "<<line<<endl;
        if (obj->insert(line,i)==-1)
        {
            cout<<"File doesnot meet the requirements"<<endl;
            fclose(file);
            delete line;
            delete[] temp;
            return -1;
        }
        strcpy(temp,obj->get_document(i));
        split(temp,i,trie,obj);
        delete line;
        line=NULL;
        buffer=0;
    }
    fclose(file);
    delete[] temp;
    return 1;
}

