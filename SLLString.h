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

	SLLString& operator=(const SLLString& other) { //return and adress
        if (this != &other) {
            delete this;
            Node* temp = new Node();
            temp = m_pHead;


        }
        delete this;


    } //shallow copy
	SLLString& operator+= (const SLLString& other);
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

    //copy?




private:
	Node* m_pHead;
	Node* m_pTail;
    int size = 0;
};

#endif