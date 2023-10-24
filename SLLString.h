#ifndef SLLSTRING_H
#define SLLSTRING_H

#include <iostream>
#include <string>
#include "Node.h"

class SLLString
{
    public:
	SLLString();
	SLLString(const std::string& other); //convertor
	SLLString(const SLLString& other); //copy constr
	~SLLString();
    /**
     * thanks Nathaniel
     * Assignment:
     *  Base obj1(5); //calls Base class constructor
     *  Base obj2; //calls Base class default constructor
     *  obj2 = obj1; //calls assignment operator
     *
     *  Copy Constructor:
     *  Base obj1(5);
     *  Base obj2 = obj1; //calls copy constructor
     *
     * @param other
     * @return
     */
	SLLString& operator=(const SLLString& other) { //returns an adress
        if (this == &other)
            return *this;
        clear();//this is the distinguishing line.
        size = other.size;
        Node* otherHead = other.m_pHead;
        m_pHead = new Node(otherHead->getData()); //creating first node.
        m_pHead->setNext(otherHead->getNext()); //this is the head, mess with this and lose everything
        m_pTail = otherHead;
        //copy remaining nodes
        //Node* new_mpHead = new Node(); // temp pointer
        otherHead = otherHead->getNext(); // advancing pointer..
        while (otherHead != nullptr) {
            // get next item from original chain
            char ch = otherHead->getData();

            // create a new node containing the next item
            Node *newNodePtr = new Node(ch);

            // link new node to end of new chain
            m_pTail->setNext(newNodePtr);

            // Advance ptrs
            m_pTail = m_pTail->getNext();
            otherHead = otherHead->getNext();
        }
        return *this;

    }
    /**
     * string concat
     * get to the end, stick it on.
     * @param other
     * @return
     */
	SLLString& operator+= (const SLLString& other) { //modifying current list
        this->size += other.size;
        Node* otherHead = other.m_pHead;
        while(otherHead != nullptr) {
            //new Node(otherHead->getData());
            this->m_pTail->setNext(new Node(otherHead->getData())); //new node returns a node ptr, set next tkes a node ptr

            this->m_pTail = m_pTail->getNext();
            otherHead = otherHead->getNext();

        }
        return *this;
    }
	friend std::ostream& operator<<(std::ostream& os, const SLLString& other) {
        int index = 0;
        Node* temp = other.m_pHead;
        while (temp != 0) {
            os << index << "\t" << temp->getData() << std::endl;
            temp = temp->getNext();
            index++;
        }
        return os;
    };

	// Get character at index n
	char& operator[](const int n);



	// Get the length of this string
	int length() { return size; };

	// Find the index of the first occurrence of substring in the current string.
	// Returns - 1 if not found
	int findSubstring(const std::string substring);

	// Erase all occurrences of character c from the current string
    // iterate, erase
	void erase(char c);

    Node* copy();
    void clear();




private:
	Node* m_pHead;
	Node* m_pTail;
    int size = 0;
};

#endif