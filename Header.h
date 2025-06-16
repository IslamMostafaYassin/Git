#pragma once
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// learning git

// Classes:

enum LEVEL
{
    error,
    warning,
    info
};

class Log
{
private:
    LEVEL mohammed = info;

public:
    void setlevel(LEVEL level)
    {
        mohammed = level;
    }
    void Error(string sentence)
    {
        cout << "[Error]: " << sentence << endl;
    }
    void Warning(string sentence)
    {
        if (mohammed >= 1)
            cout << "[Warning]: " << sentence << endl;
    }
    void Info(string sentence)
    {
        if (mohammed == 2)
            cout << "[Info]: " << sentence << endl;
    }
};

class Node
{
public:
    int element;
    Node *next;
    Node(int num)
    {
        element = num;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head = nullptr;

public:
    void LeftInsert(int num)
    {
        Node *temp = new Node(num);
        temp->next = head;
        head = temp;
    }
    void InsertAt(int index, int num)
    {
        if (index == 0)
            (*this).LeftInsert(num);
        else if (index <= GetSize() && index > 0)
        {
            Node *temp = new Node(num);
            Node *prev = FindAt(index - 1);
            temp->next = prev->next;
            prev->next = temp;
        }
    }

    void RightInsert(int num)
    {
        InsertAt(GetSize(), num);
    }

    void LeftDelete()
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }

    void DeleteAt(int index)
    {
        if (index == 0)
            LeftDelete();
        else if (index < GetSize() && index > 0)
        {
            Node *prev = FindAt(index - 1);
            Node *temp = prev->next;
            prev->next = temp->next;
            delete temp;
        }
    }

    void RightDelete()
    {
        DeleteAt(GetSize() - 1);
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *upcoming = current->next;
            current->next = prev;
            prev = current;
            current = upcoming;
        }
        head = prev;
    }

    void RecursionReverse(Node *prev = nullptr, Node *current = nullptr, Node *upcoming = nullptr)
    {
        if (prev == nullptr && current == nullptr && upcoming == nullptr)
        {
            current = head;
            upcoming = head->next;
        }
        if (upcoming == nullptr && current != nullptr)
        {
            current->next = prev;
            head = current;
            return;
        }
        current->next = prev;
        RecursionReverse(current, upcoming, upcoming->next);
    }

    void RecursionReverse1(Node *temp)
    {
        if (temp->next == nullptr)
        {
            head = temp;
            return;
        }
        RecursionReverse1(temp->next);
        temp->next->next = temp;
        temp->next = nullptr;
    }

    Node *FindAt(int num)
    {
        Node *temp = nullptr;
        if (num >= 0 && num < GetSize())
        {
            temp = head;
            for (int i = 0; i < num; i++)
            {
                temp = temp->next;
            }
        }
        return temp;
    }

    void print()

    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->element;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void RecursionPrint(Node *temp = nullptr)
    {
        if (temp == nullptr)
            temp = head;
        cout << temp->element;
        if (temp->next != nullptr)
            cout << " -> ";
        else
            return;
        RecursionPrint(temp->next);
    }

    void RecursionReversePrint(Node *temp = nullptr)
    {
        if (temp == nullptr)
            temp = head;
        if (temp->next != nullptr)
        {
            RecursionReversePrint(temp->next);
        }
        cout << temp->element;
        if (head != temp)
        {
            cout << " -> ";
        }
    }

    int GetSize()
    {
        Node *temp = head;
        int counter = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *temp1 = temp->next;
            delete temp;
            temp = temp1;
        }
        head = nullptr;
    }
};

class DoublyNode
{
public:
    int element;
    DoublyNode *prev;
    DoublyNode *next;
    DoublyNode(int num)
    {
        element = num;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DoublyNode *head = nullptr;
    DoublyNode *tail = nullptr;

public:
    void LeftInsert(int num)
    {
        DoublyNode *temp = new DoublyNode(num);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            temp->prev = nullptr;
            head = temp;
        }
    }
    void RightInsert(int num)
    {
        DoublyNode *temp = new DoublyNode(num);
        if (tail == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            temp->next = nullptr;
            tail = temp;
        }
    }
    void print()
    {
        DoublyNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->element;
            if (temp->next != nullptr)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void ReversePrint()
    {
        DoublyNode *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->element;
            if (temp->prev != nullptr)
                cout << " -> ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

class Stack
{
private:
    int size = 0;
    int capacity = 100;
    int *arr = new int[capacity];

private:
    void grow()
    {
        capacity = capacity * 2;
        int *NewArr = new int[capacity];
        for (int i = 0; i < getsize(); i++)
        {
            NewArr[i] = arr[i];
        }
        delete[] arr;
        arr = NewArr;
    }

public:
    bool IsEmpty()
    {
        return getsize() < 1;
    }
    int getsize()
    {
        return size;
    }
    void push(int num)
    {
        if (size >= capacity)
            grow();
        size++;
        arr[size - 1] = num;
    }
    void pop()
    {
        if (IsEmpty())
            cout << "\"ERROR\": Stack is empty.";
        else
            size--;
    }
    int top()
    {
        if (IsEmpty())
        {
            cout << "\"ERROR\": Stack is empty.";
            return 0;
        }
        return arr[size - 1];
    }
};

class Node1 // same as Node
{
public:
    Node1 *next;
    int data;
    Node1(int num)
    {
        data = num;
        next = nullptr;
    }
};

class Stack1
{
private:
    Node1 *head = nullptr;

public:
    void push(int num)
    {
        Node1 *temp = new Node1(num);
        temp->next = head;
        head = temp;
    }
    void pop()
    {
        Node1 *temp = head;
        head = head->next;
        delete temp;
    }

    int top()
    {
        return head->data;
    }
};

class CircularQueue
{
    int m_array[3];
    int head, tail;
    bool empty = true;
    bool full = false;

public:
    void enqueue(int num)
    {
        if (full)
        {
            cout << "ERROR: queue is full";
            return;
        }
        if (empty)
        {
            head = 0;
            tail = 0;
            m_array[tail] = num;
            empty = false;
        }
        else
        {
            tail = (tail + 1) % 3;
            m_array[tail] = num;
        }
        if ((tail + 1) % 3 == head)
            full = true;
    }
    void dequeue()
    {
        full = false;
        if (empty)
        {
            cout << "ERROR: queue is empty";
            return;
        }
        head = (head + 1) % 3;
        if ((tail + 1) % 3 == head)
            empty = true;
    }
    int front()
    {
        if (empty)
        {
            cout << "ERROR: queue is empty";
            return 0;
        }
        return m_array[head];
    }
};

class Queue
{
    Node1 *head = nullptr, *tail = nullptr;

public:
    void enqueue(int num)
    {
        Node1 *temp = new Node1(num);
        if (head == nullptr)
            head = temp;
        if (tail != nullptr)
            tail->next = temp;
        temp->next = nullptr;
        tail = temp;
    }
    void dequeue()
    {
        if (head == nullptr)
        {
            cout << "ERROR:queue is empty";
            return;
        }
        head = head->next;
    }
    int front()
    {
        if (head == nullptr)
        {
            cout << "ERROR:queue is empty ";
            return 0;
        }
        return head->data;
    }
};

class Node2
{
public:
    int data;
    Node2 *left, *right;
    Node2(int num) : data(num), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    Node2 *root = nullptr;

    void insert(int num)
    {
        root = insert(root, num);
    }
    Node2 *insert(Node2 *temp, int num)
    {
        if (!temp)
            return new Node2(num);
        if (num <= temp->data)
            temp->left = insert(temp->left, num);
        else
            temp->right = insert(temp->right, num);
        return temp;
    }
    void erase(int num)
    {
        root = erase(root, num);
    }
    Node2 *erase(Node2 *temp, int num)
    {
        if (!temp)
            return nullptr;
        if (temp->data > num)
            temp->left = erase(temp->left, num);
        else if (temp->data < num)
            temp->right = erase(temp->right, num);
        else
        {
            if (!temp->left)
            {
                Node2 *next = temp->right;
                delete temp;
                return next;
            }
            else if (!temp->right)
            {
                Node2 *next = temp->left;
                delete temp;
                return next;
            }
            else
            {
                Node2 *smallestRight = findMin(temp->right);
                temp->data = smallestRight->data;
                temp->right = erase(temp->right, smallestRight->data);
            }
        }
        return temp;
    }
    Node2 *find(int num)
    {
        return find(root, num);
    }
    Node2 *find(Node2 *temp, int num)
    {
        if (!temp)
            return nullptr;
        if (temp->data == num)
            return temp;
        if (num < temp->data)
            return find(temp->left, num);
        else
            return find(temp->right, num);
    }

    Node2 *findMin(Node2 *temp)
    {
        if (!temp)
            return nullptr;
        if (!temp->left)
            return temp;
        return findMin(temp->left);
    }

    void print()
    {
        print(root);
    }
    void print(Node2 *temp)
    {
        if (!temp)
            return;
        print(temp->left);
        cout << temp->data << " ";
        print(temp->right);
    }
};

class DynamicArray
{
private:
    int size, capacity;
    int *arr;

public:
    DynamicArray()
    {
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }
    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        arr = new int[this->capacity];
    }
    int getsize()
    {
        return size;
    }
    int getcapacity()
    {
        return capacity;
    }
    int at(int num)
    {
        return arr[num];
    }
    void add(int num)
    {
        if (size >= capacity)
        {
            grow();
        }
        arr[size] = num;
        size++;
    }
    void grow()
    {
        capacity = capacity * 2;
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    ~DynamicArray()
    {
        delete[] arr;
    }
};

class SmartPointer
{
    int *m_Ptr;

public:
    SmartPointer(int *ptr) : m_Ptr(ptr) {}
    ~SmartPointer()
    {
        delete m_Ptr;
    }
};

class UnionFind
{
    vector<int> parent;
    vector<int> size;

public:
    UnionFind() : parent(9), size(9, 1)
    {
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    void unite(int num1, int num2)
    {
        int parent1 = find(num1);
        int parent2 = find(num2);
        if (parent1 == parent2)
            return;
        if (size[parent1] >= size[parent2])
        {
            parent[parent2] = parent1;
            size[parent1] += size[parent2];
            return;
        }
        parent[parent1] = parent2;
        size[parent2] += size[parent1];
    }
    int find(int num)
    {
        int temp = num;
        while (num != parent[num])
            num = parent[num];
        while (num != temp)
        {
            int firstParent = parent[temp];
            parent[temp] = num;
            temp = firstParent;
        }
        return num;
    }
};

// Functions:

string infix_to_postfix(string infix)
{
    stack<char> operators;
    string postfix = "";
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix.at(i) == '(')
        {
            operators.push(infix.at(i));
        }
        else if (infix.at(i) == '*' || infix.at(i) == '/')
            if (operators.empty() || operators.top() == '+' || operators.top() == '-' || operators.top() == '(')
            {
                operators.push(infix.at(i));
                postfix += ' ';
            }
            else
            {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
                i--;
            }
        else if (infix.at(i) == '+' || infix.at(i) == '-')
            if (operators.empty() || operators.top() == '(')
            {
                operators.push(infix.at(i));
                postfix += ' ';
            }
            else
            {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
                i--;
            }
        else if (infix.at(i) == ')')
        {
            while (operators.top() != '(')
            {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            postfix += infix.at(i);
        }
    }
    while (!operators.empty())
    {
        postfix += ' ';
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}
