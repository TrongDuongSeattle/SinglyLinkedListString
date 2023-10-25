#ifndef SLLSTRING_H
#define SLLSTRING_H

#include <iostream>
#include <string>
#include "Node.h"

class SLLString
{
    public:
	SLLString();
	SLLString(const std::string& other);
	SLLString(const SLLString& other);
	~SLLString();
	SLLString& operator=(const SLLString& other);
	SLLString& operator+= (const SLLString& other);
	friend std::ostream& operator<<(std::ostream& os, const SLLString& other);
    char& operator[](const int n);
	int length() { return size; };
	int findSubstring(const std::string substring);
    void erase(char c);
    void clear();
private:
	Node* m_pHead;
	Node* m_pTail;
    int size = 0;
};

#endif