#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;


Queue::Queue() {
	this->valueList = new TElem [5];
    this->nextList = new int[5];
    this->beforeList = new int[5];
    this->capacity = 5;
    this->length = 0;
    this->head = -1;
    this->tail = -1;
    this->nrOfplaces = 0;
}

// we always push at the end of the list
void Queue::push(TElem elem) {
    //check if tail is empty and head
    resizeUp();
    if(this->head == -1){
        this->valueList[0] = elem;
        this->nextList[0] = -1;
        this->beforeList[0] = -1;
        this->head = 0;
        this->firstEmptyIndex = 1;
        this->length++;
        this->nrOfplaces++;
        return;
    }
    //if tail is -1 we have to add into first empty
    if(this->tail == -1 ){
        //we add the element into first empty
        this->valueList[this->firstEmptyIndex] = elem;
        this->nextList[this->firstEmptyIndex] = -1;
        this->beforeList[this->firstEmptyIndex] = this->head;

        this->nextList[this->head] = this->firstEmptyIndex;
        this->tail = this->firstEmptyIndex;
        this->length++;
        this->firstEmptyIndex = this->searchFirstEmpty();
        this->nrOfplaces++;
        return;
    }


    this->valueList[this->firstEmptyIndex] = elem;
    this->nextList[this->firstEmptyIndex] = -1;
    this->beforeList[this->firstEmptyIndex] = this->tail;
    this->nextList[this->tail] = this->firstEmptyIndex;
    this->tail = this->firstEmptyIndex;

    this->length++;
    this->nrOfplaces++;

    this->firstEmptyIndex = this->searchFirstEmpty();
    //search for first empty
}

int Queue::searchFirstEmpty() {
    for(int parser = 0 ; parser< this->length ; parser++){
        if( this->valueList[parser] == NULL_TELEM){
            return parser;
        }
    }
    return this->length;
}
void Queue::resizeUp() {
    if(this->nrOfplaces >= this->capacity-2){
        this->capacity *=2;
        auto *auxValueList = new TElem [this->capacity];
        int *auxBeforeList = new int [this->capacity];
        int *auxNextList = new int[this->capacity];
        for(int parser = 0 ; parser<this->nrOfplaces; parser++)
        {
            auxValueList[parser] = this->valueList[parser];
            auxNextList[parser] = this->nextList[parser];
            auxBeforeList[parser] = this->beforeList[parser];
        }
        delete[] this->valueList;
        delete[] this->nextList;
        delete[] this->beforeList;
        this->valueList = auxValueList;
        this->nextList = auxNextList;
        this->beforeList = auxBeforeList;
    }


}

TElem Queue::top() const {
	if(this->head == -1){
        throw exception();
    }

    return this->valueList[this->head];
	return NULL_TELEM;
}
//we will pop from the head of the list
TElem Queue::pop() {
    if(this->head == -1){
        throw exception();
    }

    if(this->tail == -1){
        TElem  value = this->valueList[this->head];
        this->valueList[this->head] = NULL_TELEM;
        this->length--;
        this->head = -1;
        return value;
    }



    int nextIndex = this->nextList[this->head];
    TElem value = this->valueList[this->head];
    this->valueList[this->head] = NULL_TELEM;
    this->beforeList[nextIndex] = -1;
    this->head = nextIndex;
    this->length--;
    if(this->length == 1){
        this->tail = -1;
    }
	return value;
}

bool Queue::isEmpty() const {
	if(this->head == -1){
        return true;
    }
	return false;
}


Queue::~Queue() {
	delete[] this->valueList;
    delete[] this->nextList;
    delete[] this->beforeList;
}

