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
    void partition(const T& splittingValue, List<T>*& lessThanList, List<T>*& greaterThanOrEqualList) 
    {
        if (head == nullptr)
        {

            lessThanList = new List<T>();
            greaterThanOrEqualList = new List<T>();
            return;
        }

        Node* current = head;
        Node* lessThanTail = nullptr;
        Node* greaterThanOrEqualTail = nullptr; 

        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            if (current->data < splittingValue) 
            {
                if (lessThanList == nullptr) {
                    lessThanList = new List<T>();
                    lessThanList->head = current;
                    lessThanList->tail = current;
                    lessThanList->size = 1;
                }
                else 
                {
                    current->prev = lessThanList->tail;
                    if (lessThanList->tail != nullptr)
                        lessThanList->tail->next = current;
                    lessThanList->tail = current;
                    lessThanList->size++;
                }
                if (lessThanTail == nullptr)
                    lessThanTail = current;
            }
            else 
            {
                if (greaterThanOrEqualList == nullptr) 
                {
                    greaterThanOrEqualList = new List<T>();
                    greaterThanOrEqualList->head = current;
                    greaterThanOrEqualList->tail = current;
                    greaterThanOrEqualList->size = 1;
                }
                else 
                {
                    current->prev = greaterThanOrEqualList->tail;
                    if (greaterThanOrEqualList->tail != nullptr)
                        greaterThanOrEqualList->tail->next = current;
                    greaterThanOrEqualList->tail = current;
                    greaterThanOrEqualList->size++;
                }
                if (greaterThanOrEqualTail == nullptr)
                    greaterThanOrEqualTail = current;
            }
            current = nextNode;
        }
        if (lessThanTail != nullptr)
            lessThanTail->next = nullptr;
        if (greaterThanOrEqualTail != nullptr)
            greaterThanOrEqualTail->next = nullptr;
        head = greaterThanOrEqualList->head;
        tail = greaterThanOrEqualList->tail;
    }
    static List<T>* combineLists(List<T>* lessThanList, const T& splittingValue, List<T>* greaterThanOrEqualList) 
    {
        List<T>* combinedList = new List<T>();
        if (lessThanList != nullptr) {
            Node* current = lessThanList->head;
            while (current != nullptr) {
                combinedList->push_back(current->data);
                current = current->next;
            }
            delete lessThanList;
        }
        combinedList->push_back(splittingValue);
        if (greaterThanOrEqualList != nullptr) {
            Node* current = greaterThanOrEqualList->head;
            while (current != nullptr) {
                combinedList->push_back(current->data);
                current = current->next;
            }
            delete greaterThanOrEqualList;
        }

        return combinedList;
    }
    static List<T>* quicksort(List<T>* list) 
    {
        if (list == nullptr || list->getSize() <= 1) 
        {
            return list;
        }

        T pivot = list->front();
        List<T>* lessThanList = nullptr;
        List<T>* greaterThanOrEqualList = nullptr;

        list->partition(pivot, lessThanList, greaterThanOrEqualList);
        List<T>* sortedLessThan = quicksort(lessThanList);
        List<T>* sortedGreaterThanOrEqual = quicksort(greaterThanOrEqualList);
        List<T>* sortedList = combineLists(sortedLessThan, pivot, sortedGreaterThanOrEqual);

        return sortedList;
    }
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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

