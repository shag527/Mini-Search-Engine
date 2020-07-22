#include<bits/stdc++.h>
#include "ranking.h"
#include "indexing.h"
#include "scorelist.h"
#include "maxheap.h"
#include<sys/ioctl.h>
#include<unistd.h>
using namespace std;

void search(char* token, Trie *trie, Map *obj,int k);
void df(Trie *trie);
int tf(char* token, Trie *trie);
