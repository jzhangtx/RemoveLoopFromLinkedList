RemoveLoopFromLinkedList: RemoveLoopFromLinkedList.o
	g++ -g -o RemoveLoopFromLinkedList.exe RemoveLoopFromLinkedList.o -pthread    

RemoveLoopFromLinkedList.o: RemoveLoopFromLinkedList/RemoveLoopFromLinkedList.cpp
	g++ -g  -c -pthread RemoveLoopFromLinkedList/RemoveLoopFromLinkedList.cpp
