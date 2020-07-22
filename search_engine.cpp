#include "search_engine.h"
using namespace std;

int input_manager(char *input,Trie *trie, Map *obj,int k)
{
    char *token=strtok(input," \t\n");
    if(!strcmp(token,"/search"))
    search(token,trie,obj,k);
    else if(!strcmp(token,"/df"))
    df(trie);
    else if(!strcmp(token,"/tf"))
    {
        if(tf(token,trie)==-1)
        return -1;
    }
    else if(!strcmp(token,"/exit"))
    {
        cout<<"Exiting.....\n";
        token=NULL;
        delete token;
        return 2;
    }
    else
    return -1;
    token=NULL;
    delete token;
    return 1;
}
int main(int argc, char **argv)
{
    if(argc!=5 || strcmp(argv[1],"-d") || strcmp(argv[3],"-k"))
    {
        cout<<"PLease provide correct arguments"<<endl;
        return -1;
    }

    cout<<"Checking....."<<endl;

    long int num_of_lines=0, max_length=-1, k=atoi(argv[4]);

    if(get_file_size(&num_of_lines,&max_length,argv[2])==-1)
    return -1;

    Map *obj=new Map(num_of_lines,max_length);
    Trie *trie=new Trie();

    //cout<<num_of_lines<<" "<<max_length<<endl;
    //cout<<"ri "<<read_input(obj,argv[2])<<endl;;

    if(read_input(obj,trie,argv[2])==-1)
    {
        delete obj;
        return -1;
    }
    //for(int i=0;i<obj->get_doc_size();i++)
    //(obj->print(i));
    cout<<"Initialization Finished! System is ready to search."<<endl;
    //cout<<num_of_lines<<" "<<max_length<<endl;
    cout<<"Database Ckecked."<<endl;
    char* input=NULL;
    size_t input_length=0;
    while(1)
    {
        getline(&input,&input_length,stdin);
        int ret=input_manager(input,trie,obj,k);
        if(ret==-1)
        cout<<"Invalid Input"<<endl;
        else if(ret==2)
        {
            delete input;
            break;
        }
        delete input;
        input_length=0;
    }
    delete obj;
    delete trie;
    return 1;
}

