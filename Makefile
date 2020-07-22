CC = g++
default: search_engine clean
search_engine: search_engine.o crawler.o indexing.o ranking.o trie_list.o search.o scorelist.o maxheap.o
	$(CC) -o search_engine search_engine.o crawler.o indexing.o ranking.o trie_list.o search.o  scorelist.o maxheap.o
maxheap.o: maxheap.cpp maxheap.h 
	$(CC) -c maxheap.cpp
scorelist.o: scorelist.cpp scorelist.h 
	$(CC) -c scorelist.cpp
search.o: search.cpp search.h 
	$(CC) -c search.cpp
trie_list.o: trie_list.cpp trie_list.h 
	$(CC) -c trie_list.cpp	
ranking.o: ranking.cpp ranking.h 
	$(CC) -c ranking.cpp
indexing.o: indexing.cpp indexing.h 
	$(CC) -c indexing.cpp
crawler.o: crawler.cpp crawler.h 
	$(CC) -c crawler.cpp
search_engine.o: search_engine.cpp search_engine.h 
	$(CC) -c search_engine.cpp
clean:
	rm *.o
