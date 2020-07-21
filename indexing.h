#include<bits/stdc++.h>
using namespace std;

#ifndef INDEXING_H
#define INDEXING_H
class Map
{
    long int doc_size;          //The number of documents
    long int buffer_size;   //Length of biggest document
    char **document;        //Individual Document
    int *length;
    public:         //length of each document
        Map(long int doc_size,long int buffer_size);
        ~Map();
        const long int get_doc_size(){return doc_size;}
        const long int get_buffer_size(){return buffer_size;}
        int insert(char* line,int i);
        void set_length(long int id,long int len){length[id]=len;}
        int get_length(int id){return length[id];}
        void print(int i){cout<<i<<" "<<document[i]<<endl;}
        char *get_document(int i){return document[i];}
};
#endif // INDEXING_H
