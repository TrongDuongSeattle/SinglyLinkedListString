//
// Created by T D  on 10/16/23.
//

#ifndef SINGLYLINKEDLISTSTRING_NODE_H
#define SINGLYLINKEDLISTSTRING_NODE_H


class Node {
public:

public:
    Node(){}
    Node(char data) { m_data = data; }
    void setData(char data){  m_data = data; }
    char getData() { return m_data; }
    void setNext(Node* next) { m_next = next; }
    Node* getNext() { return m_next; } //

private:
    char m_data;
    Node* m_next;
};


#endif //SINGLYLINKEDLISTSTRING_NODE_H
