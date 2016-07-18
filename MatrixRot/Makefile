CXX=clang++
FLAGS=-std=c++11 -stdlib=libc++

all: submission

submission: submission.cpp CircularLinkedList.o Node.o
	$(CXX) $(FLAGS) Node.o CircularLinkedList.o submission.cpp -o submission

CircularLinkedList.o: CircularLinkedList.cpp Node.o
	$(CXX) $(FLAGS) -c CircularLinkedList.cpp

Node.o: Node.cpp
	$(CXX) $(FLAGS) -c Node.cpp