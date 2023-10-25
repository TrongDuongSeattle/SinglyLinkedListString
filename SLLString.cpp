#include <iostream>
#include <string>
#include "SLLString.h"

SLLString::SLLString(){
    m_pHead = nullptr;
    m_pTail = nullptr;
}
/**
 * Constructs an SLLString from a string literal to SLLString
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
 * Constructs a new SLLString object from other SLLString object
 * @param other
 */
SLLString::SLLString(const SLLString& other){
    size = other.size;
    if (other.m_pHead == nullptr)
        SLLString();
    else {
        Node* otherHead = other.m_pHead;
        m_pHead = m_pTail = otherHead;
        m_pTail = new Node(otherHead->getData());
        otherHead = otherHead->getNext();
        while (otherHead != nullptr) {
            Node* temp = new Node(otherHead->getData());
            m_pTail->setNext(temp);
            m_pTail = m_pTail->getNext();
            otherHead = otherHead->getNext();
        }
    }


}
/**
 * Destructor
 */
SLLString::~SLLString() {
    clear();
}
/**
 * Copies contents of other SLLString to this SLLString.
 * @param other
 * @return
 */
SLLString& SLLString::operator=(const SLLString& other) {
    if (this == &other)
        return *this;
    clear();
    size = other.size;
    Node* otherHead = other.m_pHead;
    m_pHead = new Node(otherHead->getData());
    m_pHead->setNext(otherHead->getNext());
    m_pTail = m_pHead;

    otherHead = otherHead->getNext();
    while (otherHead != nullptr) {
        char ch = otherHead->getData();
        Node *newNodePtr = new Node(ch);
        m_pTail->setNext(newNodePtr);
        m_pTail = m_pTail->getNext();
        otherHead = otherHead->getNext();
    }
    return *this;
}
/**
 * Appends given SLLString to the end of this SLLString.
 * @param other
 * @return Address this SLLString
 */
SLLString& SLLString::operator+= (const SLLString& other) {
    this->size += other.size;
    Node* otherHead = other.m_pHead;
    while(otherHead != nullptr) {
        this->m_pTail->setNext(new Node(otherHead->getData()));
        this->m_pTail = m_pTail->getNext();
        otherHead = otherHead->getNext();
    }
    return *this;
}
/**
 * Allows us to print with << instead of calling a print function.
 */
 std::ostream& operator<<(std::ostream& os, const SLLString& other) {
    int index = 0;
    Node* temp = other.m_pHead;
    while (temp != 0) {
        os <<  temp->getData();
        temp = temp->getNext();
        index++;
    }
    return os;
};
/**
 * Get character at index n
 * @param substring
 * @return Address of character
 */
char& SLLString::operator[](const int n){
    Node* temp = m_pHead;
    for (int i = 0; n; i++) {
        if (i == n) {
            return temp->getData();
        }
        temp = temp->getNext();
    }

}
/**
 * Finds the index of the first occurrence of substring in the current string.
 * @param substring
 * @return Index of first letter in substring. Returns -1 if not found.
 */
int SLLString::findSubstring(const std::string substring){
    int index = 0;
    int count = 0;
    Node* thisNode = m_pHead;
    bool found = false;
   while (!found && thisNode != nullptr) {
       if (thisNode->getData() == substring[index]) {
           index++;
           if (index == substring.length())
               found = true;
       }
       count++;
       thisNode = thisNode->getNext();
   }
   if (found)
       return count - index;
    return -1;
}
/**
 * Erase all occurrences of character c from the current string
 * @param c
 */
void SLLString::erase(char c) {
    Node* curr = m_pHead;
    while (curr->getNext()->getNext() != nullptr) {
        if (m_pHead->getData() == c) {
            m_pHead = m_pHead->getNext();
        }
        if (curr->getNext()->getData() == c) {
            curr->setNext(curr->getNext()->getNext());
        }
        curr = curr->getNext();
   }
    if (m_pTail->getData() == c) {
        m_pTail = curr;
        m_pTail->setNext(nullptr);
        return;
    }
}
/**
 * Deletes entire SLLString.
 */
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