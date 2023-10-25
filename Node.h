//
// Created by T D  on 10/16/23.
//

#ifndef SINGLYLINKEDLISTSTRING_NODE_H
#define SINGLYLINKEDLISTSTRING_NODE_H


class Node {
public:

public:
    Node(){m_data = 0; m_next = nullptr;}
    Node(char data) { m_data = data; m_next = nullptr; }
    void setData(char data){  m_data = data; }
    char& getData() { return m_data; }
    void setNext(Node* next) { m_next = next; }
    Node* getNext() { return m_next; } //
    //friend class SLLString;

private:
    char m_data;
    Node* m_next;
};


#endif //SINGLYLINKEDLISTSTRING_NODE_H
