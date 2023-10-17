#include <iostream>
#include <string>
#include "SLLString.h"

SLLString::SLLString(){
    m_pHead = NULL;
    m_pTail = NULL;
}
/**
 * Copy Constructor
 * @param other
 */
SLLString::SLLString(const std::string& other) {
    size = other.length();
}
/**
 *
 * @param other
 */
SLLString::SLLString(const SLLString& other){
    this->m_pHead = other.m_pHead;
    this->m_pTail = other.m_pTail
}
~SLLString();

    /*
    SLLString(const std::string& other);
    SLLString(const SLLString& other);
    ~SLLString();

    SLLString& operator=(const SLLString& other);
    SLLString& operator+= (const SLLString& other);
    friend std::ostream& operator<<(std::ostream& os, const SLLString& other);

    // Get character at index n
    char& operator[](const int n);

    // Get the length of this string
    int length();

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