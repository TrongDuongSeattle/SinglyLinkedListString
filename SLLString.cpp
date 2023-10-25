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
 * once you have the data sorted, searching becomes trivial;
 * @param substring
 * @return
 */
int SLLString::findSubstring(const std::string substring){
    int index = 0;
    int count = 0;
    Node* thisNode = m_pHead;
    bool found = false;

   while (!found && thisNode != nullptr) {
       if (thisNode->getData() == substring[index]) {
           index++;
           if (index == substring.length()) {
               found = true;
           }
       }
       count++;
       thisNode = thisNode->getNext();
   }
   if (found)
       return count - index;
    return -1;
}
// Erase all occurrences of character c from the current string
// iterate, erase
void SLLString::erase(char c) {

    Node* next = m_pHead;
    Node* curr = m_pHead;

    while (curr->getNext()->getNext() != nullptr) {
        if (m_pHead->getData() == c) {
            std::cout << "bogey at the start" << std::endl;
            m_pHead = m_pHead->getNext();
        }
        if (curr->getNext()->getData() == c) {

            std::cout << "I have eyes on target..." << std::endl;
            std::cout << "Fox 2 away." << std::endl;

            //Node* temp = curr->getNext();   //memory leak?
            curr->setNext(curr->getNext()->getNext());
            std::cout << "Splash down" << std::endl;
        }
        curr = curr->getNext();
        //next = next->getNext();


   }
    if (m_pTail->getData() == c) {
        std::cout << "bogey at the end" << std::endl;
        m_pTail = curr;
        m_pTail->setNext(nullptr);
        return;
    }
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