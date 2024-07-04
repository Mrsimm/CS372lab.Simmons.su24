#include <iostream>
#include <memory>
using namespace std;
template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        unique_ptr<Node> prev;
        unique_ptr<Node> next;

        Node(const T& newData) : data(newData), prev(nullptr), next(nullptr) {}
    };

    unique_ptr<Node> head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    List(const T& newData) : head(nullptr), tail(nullptr), size(0) 
    {
        setupList(newData);
    }

    List(const List& rhs) 
    {
        copyList(rhs);
    }

    ~List() 
    {
        deleteListContents();
    }

    void setupList(const T& newData) 
    {
        head = make_unique<Node>(newData);
        tail = head.get();
        size = 1;
    }

    void copyList(const List& rhs) {
        deleteListContents();
        Node* rhsCurrent = rhs.head.get();
        Node* prevNode = nullptr;
        while (rhsCurrent != nullptr) {
            auto newNode = make_unique<Node>(rhsCurrent->data);
            if (!head) {
                head = move(newNode);
                prevNode = head.get();
            }
            else {
                prevNode->next = move(newNode);
                prevNode->next->prev = prevNode;
                prevNode = prevNode->next.get();
            }
            if (rhs.tail == rhsCurrent)
                tail = prevNode;
            rhsCurrent = rhsCurrent->next.get();
            size++;
        }
    }

    void deleteListContents() {
        while (head) {
            head = move(head->next);
        }
        tail = nullptr;
        size = 0;
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void push_front(const T& data) {
        auto newNode = make_unique<Node>(data);
        newNode->next = move(head);
        if (head)
            head->prev = newNode.get();
        else
            tail = newNode.get();
        head = move(newNode);
        size++;
    }

    void push_back(const T& data) {
        auto newNode = make_unique<Node>(data);
        newNode->prev = tail;
        if (tail)
            tail->next = move(newNode);
        else
            head = move(newNode);
        tail = newNode.get();
        size++;
    }

    T front() const {
        if (!head) 
        {
            cout << "List is empty";
        }
        return head->data;
    }

    T back() const 
    {
        if (!tail) 
        {
            cout << "List is empty";
        }
        return tail->data;
    }

    void pop_back() 
    {
        if (!tail)
            return;
        if (tail->prev) 
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else 
        {
            head = nullptr;
            tail = nullptr;
        }
        size--;
    }

    void pop_front() 
    {
        if (!head)
            return;
        if (head->next) 
        {
            head = move(head->next);
            head->prev = nullptr;
        }
        else 
        {
            head = nullptr;
            tail = nullptr;
        }
        size--;
    }

    void traverse(void (*doIt)(const T& data)) const 
    {
        Node* currentNode = head.get();
        while (currentNode != nullptr) 
        {
            doIt(currentNode->data);
            currentNode = currentNode->next.get();
        }
    }

    void printTheList() const 
    {
        Node* current = head.get();
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next.get();
        }
        cout << std::endl;
    }
};




