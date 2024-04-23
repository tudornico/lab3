#pragma once
#include <vector>
using namespace std;

//DO NOT CHANGE THIS PART
#if DEFINITION == 1
typedef pair<int, int> TElem;
#define NULL_TELEM make_pair(-11111 , -11111)
#else
typedef int TElem;
#define NULL_TELEM (-11111)
#endif



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
