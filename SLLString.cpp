#include <iostream>
#include <string>
#include "SLLString.h"

SLLString::SLLString(){
    m_pHead = nullptr;
    m_pTail = nullptr;
}
/**
 * Copy Constructor
 * @param other
 */
 //
SLLString::SLLString(const std::string& other){
    size = other.length();
    Node* temp = new Node(other[0]);

    m_pHead = m_pTail = temp;
    for (int i = 1; i < size; i++) {
        temp = new Node(other[i]);
        m_pTail->setNext(temp);
        m_pTail = m_pTail->getNext();
    }
}

/**
 *Heavily inspired by textbook
 * Traverse, loop and duplicate: looplicate. Dupli-Loop.;
 * @param other
 */
SLLString::SLLString(const SLLString& other){
    size = other.size;
    Node* otherHead = other.m_pHead;
    if (otherHead == 0)
        m_pHead = 0;
    else {
        //copying first node...
        m_pHead = new Node();
        m_pHead->setNext(otherHead->getNext());

        //copy remaining nodes
        Node* new_m_pHead = m_pHead; // last node pointer
        otherHead = otherHead->getNext(); // advancing pointer..
        while (otherHead != 0) {
            // get next item from original chain
            char ch = otherHead->getData();

            // create a new node containing the next item
            Node *newNodePtr = new Node(ch);

            // linke new node to end of new chain
            new_m_pHead->setNext(newNodePtr);

            // Advance ptrs
            new_m_pHead = new_m_pHead->getNext();
            otherHead = otherHead->getNext();
        }//end loop
        new_m_pHead->setNext(0);
        }
}

SLLString& SLLString::copy(SLLString &other) {
    size = other.size;
    Node* otherHead = other.m_pHead;
    if (otherHead == 0)
        m_pHead = 0;
    else {
        //copying first node...
        m_pHead = new Node();
        m_pHead->setNext(otherHead->getNext());

        //copy remaining nodes
        Node* new_m_pHead = m_pHead; // last node pointer
        otherHead = otherHead->getNext(); // advancing pointer..
        while (otherHead != 0) {
            // get next item from original chain
            char ch = otherHead->getData();

            // create a new node containing the next item
            Node *newNodePtr = new Node(ch);

            // linke new node to end of new chain
            new_m_pHead->setNext(newNodePtr);

            // Advance ptrs
            new_m_pHead = new_m_pHead->getNext();
            otherHead = otherHead->getNext();
        }//end loop
        new_m_pHead->setNext(0);
    }
}


/**
 * iterate list, delete, set head & tail to null
 * Destructor
 */
SLLString::~SLLString() {
    Node* killer = m_pHead;
    while (killer->getNext() != 0) {
        m_pHead = m_pHead->getNext();
        delete killer;
        killer = m_pHead;
    }
    size = 0;
}
/*
SLLString& operator=(const SLLString& other) {
    //return *this;
}*/


    /*




    SLLString& operator+= (const SLLString& other);


    // Get character at index n
    char& operator[](const int n);

    // Find the index of the first occurrence of substring in the current string.
    // Returns - 1 if not found
    int findSubstring(const std::string substring);

    // Erase all occurrences of character c from the current string
    void erase(char c);

private:
    Node* m_pHead;
    Node* m_pTail;
};

#endif
*/