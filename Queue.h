#pragma once
#include <vector>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

class Queue
{
private:
	TElem *valueList;
    int *nextList;
    int *beforeList;
    int firstEmptyIndex;
    int capacity;
    int length;
    int head;
    int tail;
    int nrOfplaces;
public:
	Queue();

	//pushes an element to the end of the queue
	void push(TElem e);
    void resizeUp();

    void resizeDown();
	//returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem top() const;

    int searchFirstEmpty();
	//removes and returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem pop();

	//checks if the queue is empty
	bool isEmpty() const;

	// destructor
	~Queue();
};
