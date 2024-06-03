#pragma once
#include "SimmonsASG3P1.h"
template <typename T>
class CircularList {
private:
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
public:
    void push_front2(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = head;
        size++;
    }
    void pop_back2()
    {
        Node* lastNode = tail;
        if (tail != nullptr)
        {


            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            head = tail;
        }
        else
        {
            head = nullptr;
            tail = head;
            delete lastNode;

        }
        size--;
    }
    void pop_front2()
    {
        Node* firstNode = head;
        if (head != nullptr)
        {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            tail = head;
        }
        else
        {
            tail = nullptr;
            head = tail;
            delete firstNode;

        }
        size--;
    }
    void push_back2(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        head = tail;
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        size++;
    }
    void circle()
    {
        Node* currentNode = head;
        while (currentNode != tail)
        {
            doIt(currentNode->data);
            currentNode = currentNode->next;
            cout << currentNode;
        }
    }





};
