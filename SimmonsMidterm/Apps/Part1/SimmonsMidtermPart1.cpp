#include <iostream>
using namespace std;
template <typename T>
class List {
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
    class Selfajustinglist //This is the brand new class.
    {
    public:
        T* find(T itemToFind)
        {
            T items;
        }
        void Locate(T itemToFind)
        {
            cout << "Test";
            Node* currentNode = head;
            while (currentNode != itemToFind)
            {
                doIt(currentNode->data);
                currentNode = currentNode->next;

                if (currentNode == nullptr)
                {
                    cout << "Item Not Found!" << endl;
                }
                if (currentNode == itemToFind)
                {
                    T tempitem;
                    tempitem = head;
                    head = itemToFind;
                    currentNode = tempitem;
                    return head;
                }
            }

        }
    };

    void setupList()
    {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    List()
    {
        setupList();
    }
    List(T newData)
    {
        setupList();
        head->data = newData;
    }
    List(List& rhs)
    {
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~List()
    {
        deleteListContents();
    }
    void deleteListContents()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr)
        {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

    int getSize() const
    {
        return size;
    }

    bool empty() const
    {
        cout << size;
        return size == 0;
    }

    void push_front(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        cout << head << endl;
        if (tail == nullptr)
            tail = newNode;
        size++;
    }
    void push_back(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        if (head == nullptr)
        {
            head = newNode;
        }
        size++;
    }
    T front()
    {
        return (head->data);
    }
    T back()
    {
        return (tail->data);
    }
    void pop_back()
    {
        if (tail != nullptr)
        {

            Node* lastNode = tail;
            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;
            delete lastNode;

        }
        size--;
    }
    void pop_front()
    {
        if (head != nullptr)
        {
            Node* firstNode = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete firstNode;

        }
        size--;
    }
    void traverse(void (*doIt)(T data))
    {
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            doIt(currentNode->data);
            currentNode = currentNode->next;
            
        }
    }
    void printTheList()
    {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void findIT (T item)
    {
        Selfajustinglist find(item);
        cout << head;
    }
};

int main()
{
    List<int> LST;
    LST.push_front(10);
    LST.push_front(20);
    LST.push_front(30);
    LST.push_front(40);
    LST.push_front(50);
    LST.findIT(40);
    return 0;
}