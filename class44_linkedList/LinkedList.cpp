#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

int size(Node *head, Node *tail)
{
    int size = 0;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

Node *getFirst(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        cout << "Invalid index\n";
        return nullptr;
    }

    return head;
}

Node *getlast(Node *&head, Node *&tail)
{
    if (tail == nullptr)
    {
        cout << "Invalid index\n";
        return nullptr;
    }

    return tail;
}

Node *getAt(Node *&head, Node *&tail, int ind)
{
    int sz = size(head, tail);
    if (ind < 0 || ind > sz - 1)
    {
        cout << "Invalid Index\n";
    }

    Node *temp = head;
    for (int i = 0; i < ind; i++)
    {
        temp = temp->next;
    }

    return temp;
}

void AddFirst(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data, nullptr);
        return;
    }

    Node *temp = new Node(data, head);
    head = temp;
}

void AddLast(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data, nullptr);
        return;
    }

    Node *temp = new Node(data, nullptr);
    tail->next = temp;
    tail = temp;
}

void AddAt(Node *&head, Node *&tail, int data, int idx)
{
    int sz = size(head, tail);
    if (idx < 0 || idx > sz)
    {
        cout << "Invaid position\n";
        return;
    }

    if (idx == 0)
    {
        AddFirst(head, tail, data);
    }

    else if (idx == sz)
    {
        AddLast(head, tail, data);
    }

    else
    {
        Node *temp = head;
        int currIdx = 0;
        while ((idx - 1) != currIdx)
        {
            currIdx++;
            temp = temp->next;
        }

        temp->next = new Node(data, temp->next);
    }
}

void removeFirst(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        cout << "Invalid list already empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void removeLast(Node *&head, Node *&tail)
{
    if (tail == nullptr)
    {
        cout << "Invalid: list already empty\n";
        return;
    }

    Node *temp = head;
    int sz = size(head, tail);

    for (int i = 0; i < sz - 1; i++)
    {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void display(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void AddAt(Node *&head, Node *&tail, int idx)
{
    int sz = size(head, tail);
    if (idx < 0 || idx >= sz)
    {
        cout << "Invaid position\n";
        return;
    }

    if (idx == 0)
    {
        removeFirst(head, tail);
    }

    else if (idx == sz - 1)
    {
        removeLast(head, tail);
    }

    else
    {
        Node *temp = head;
        int currIdx = 0;
        while ((idx - 1) != currIdx)
        {
            currIdx++;
            temp = temp->next;
        }

        Node *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
    }
}

void reverseList(Node *&head, Node *&tail)
{
    int sz = size(head, tail);
    sz--;

    int idxLst = sz;

    Node *temp = head;

    for (int i = 0; i < sz / 2; i++)
    {
        Node *temp2 = getAt(head, tail, idxLst);
        int temp3 = temp->data;
        temp->data = temp2->data;
        temp2->data = temp3;

        temp = temp->next;
        idxLst--;
    }
}

void reverseList2(Node *&head, Node *&tail)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *temp = head;
    head = tail;
    tail = temp;
}

void displayReverseRecursive(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    displayReverseRecursive(head->next);
    cout << head->data << " ";
}

Node *reverseRecursive(Node *&head, Node *node, Node *&tail)
{
    if (node->next == nullptr)
    {
        head = node;
        return node;
    }

    Node *temp = reverseRecursive(head, node->next, tail);
    temp->next = node;
    node->next = nullptr;
    tail = node;
    return node;
}

void reverseDataRecursive(Node *&head, Node *tail)
{
    if (tail == nullptr)
    {
        return;
    }

    reverseDataRecursive(head, tail->next);
    int data = head->data;
    head->data = tail->data;
    tail->data = data;

    head = head->next;
}

int main(int argc, char **argv)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    AddFirst(head, tail, 10);
    AddFirst(head, tail, 20);
    AddFirst(head, tail, 30);
    AddFirst(head, tail, 40);
    AddFirst(head, tail, 45);
    AddFirst(head, tail, 50);
    AddFirst(head, tail, 60);
    AddAt(head, tail, 600, 4);
    AddAt(head, tail, 700, 0);
    AddAt(head, tail, 800, 7);
    // removeFirst(head, tail);
    // removeLast(head, tail);

    // display(head, tail);

    // reverseList(head, tail);
    cout << "Original List:\t";
    display(head, tail);

    reverseList2(head, tail);

    cout << "ReverseList:\t";
    display(head, tail);

    // displayReverseRecursive(head);

    cout << "Reverse Recur:\t";
    reverseRecursive(head, head, tail);
    display(head, tail);

    Node *temp = head;
    cout << "Rev Data recur:\t";
    reverseDataRecursive(temp, tail);
    display(head, tail);

}