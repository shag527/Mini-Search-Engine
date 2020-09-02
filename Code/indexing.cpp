#include "indexing.h"
using namespace std;

Map::Map(long int doc_size,long int buffer_size):doc_size(doc_size),buffer_size(buffer_size)
{
    //document=(char**)malloc(doc_size*sizeof(char*));
    //length=(int*)malloc(doc_size*sizeof(int));
    document=new char*[doc_size];
    length=new int[doc_size];
    for(long int i=0;i<doc_size;i++)
    {
        //document[i]=(char*)malloc(buffer_size*sizeof(char));
        document[i]=new char[buffer_size];
    }
}
Map::~Map()
{
    for(long int i=0;i<doc_size;i++)
    {
        delete[] document[i];
    }
    delete[] document;
    delete[]length;
}

int Map::insert(char* line,int i)
{
    int cur;
    char *token;
    token=strtok(line," \t");
    cur=atoi(token);
    if(cur!=i)
    {
        token=NULL;
        delete token;
        return -1;
    }
    token=strtok(NULL,"\n");
    while(token[0]==' ')
    {
        token++;
    }
    int end=0;
    while(token[end]!='\0')
    {
        end++;
    }
    end--;
    while(end!=0 &&token[end]==' ')
    {
        token[end--]='\0';
    }
    strcpy(document[i],token);
    token=NULL;
    delete token;
    return 1;
}

