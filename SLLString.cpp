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
 *
 * take the other pointers assign head and tail to other pointer
 * then set other pointer to null..
 * Traverse, loop and duplicate: looplicate. Dupli-Loop.;
 * @param other
 */
SLLString::SLLString(const SLLString& other){
    size = other.size;
    //Node* otherHead = other.m_pHead;
    if (other.m_pHead == nullptr)
        m_pHead = nullptr;
    else {
        Node* otherHead = other.m_pHead;
        m_pHead = m_pTail = otherHead; //creating first node.
        //m_pTail->setNext(otherHead->getNext()); //this is the head, mess with this and lose everything

        //copy remaining nodes
        m_pTail = new Node(otherHead->getData());
        otherHead = otherHead->getNext(); // advancing pointer..
        while (otherHead != nullptr) {
            // get next item from original chain
            // create a new node containing the next item
            Node* temp = new Node(otherHead->getData());

            // link new node to end of new chain
            m_pTail->setNext(temp);

            // Advance ptrs
            m_pTail = m_pTail->getNext();
            otherHead = otherHead->getNext();
        }//end loop
        //m_pTail->setNext(0);
    }


}
/**
 * iterate list, delete, set head & tail to null
 * Destructor
 */
SLLString::~SLLString() {
    clear();
}
/**
 *
 * @param substring
 * @return
 */
int findSubstring(const std::string substring){
    int index = 0;

    return -1;
}
//my fx's
void SLLString::clear() {
    if (size != 0) {
        Node *killer = m_pHead;
        while (killer->getNext() != 0) {
            m_pHead = m_pHead->getNext();
            delete killer;
            killer = m_pHead;
        }
    }
    size = 0;
    m_pHead = nullptr;
    m_pHead = nullptr;

}
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