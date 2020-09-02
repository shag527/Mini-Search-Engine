# Mini-Search-Engine
The process of searching is fundamental in computer science and its fields. Computer systems are often used to store large amounts of data from which individual
records must be retrieved according to some search criterion. Thus the efficient storage of data to facilitate fast searching is an important issue, in terms of 
both time as well as memory. For this various data structures are developed and implemented. This report proposes the implementation of an efficient searching 
algorithm that is capable of finding information among a database of several entries. The project makes use of the Wikipedia data set, which has been pre-processed
using Python. The searching and sorting is implemented using the trie, max heap and various linked lists in C++. The project has been developed on Ubuntu and 
it uses the make utility in order to automate the mundane aspects of building executable from source code.

## Dataset Used
Data collection is a very crucial part of any project. For this search engine, we have used the Wikipedia Summary Dataset. It contains all titles and summaries
(or introductions) of English Wikipedia articles, extracted in September of 2017. The size of the data set is around 0.7 GB. The processing of this is further 
done using a python script. The dataset has been taken from the given [link](https://github.com/tscheepers/Wikipedia-Summary-Dataset).

## Data Structures Used
+ Map
+ Trie
+ Linkedlist
+ Maxheap
+ Array

<p align="center">
  <img align="center" src="https://github.com/shag527/Mini-Search-Engine/blob/master/trie.gif">
  </p>
  <p align="center">
  Word Stored in Trie
  </p>

## Different search functionalities 
This project provides three different functionalities for search, each of which is explained in this section.

#### Overall Search:
The function search() gives the the most relevant documents from all the documents in the dataset. 

#### Term Frequency:
The function tf() gives us the term frequency of a word in a particular document, i.e. it tells us how many times a particular word occurs in the given document.

#### Document Frequency:
The function df() prints the document frequency of a word in the dataset, i.e. it tells how many times a particular word appeared in the dataset. 

## Run Code
To run the code, we have to open terminal and go to the code folder where all the code files are present. Then, make command is executed to use the make utility
for compiling all the project files. Now, the project is ready for execution and can be run using the following command:

```
./search\_engine -d name of dataset -k N
```
where name of dataset represents the dataset text file name and top N documents are returned as a result by the search engine.

Now, our project supports three modes for checking, each of which can be run using the following commands:
#### Overall Search Mode: 
As already explained, this mode gives the topmost relevant documents from the dataset. The same can be implemented using the command: 
```
/search word
```
It gives the top N documents relevant to given word. A phrase can also be checked using the same functionality.

#### Term Frequency Mode: 
This mode gives the total count of a word in a document. The command used is:
```
/tf doc id word
```
where doc id is the id of the document in which we want to search the word and word is the name of the word.

#### Document Frequency Mode: 
This mode gives the total word count in an document. It can be used with the help of following command:
```
/df
```
It requires no parameters.

To exit the search engine, /exit command is used.
