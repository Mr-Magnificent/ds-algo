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

void reverseDR(Node *&head, Node *tail, int ind, int &size)
{
    if (tail == nullptr)
    {
        return;
    }

    size++;
    reverseDR(head, tail->next, ind + 1, size);

    if (ind >= size / 2)
    {
        int data = head->data;
        head->data = tail->data;
        tail->data = data;
        head = head->next;
    }
}

bool isPalindrome(Node *&head, Node *tail, int indx, int &floor)
{
    if (tail == nullptr)
    {
        return true;
    }

    floor++;
    bool palindromeAhead = isPalindrome(head, tail->next, indx + 1, floor);

    if (palindromeAhead == false)
    {
        return false;
    }

    if (indx >= floor / 2)
    {
        if (head->data != tail->data)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

void fold(Node *&head, Node *node, Node *&tail, int indx, int &floor)
{
    if (node == nullptr)
    {
        return;
    }

    floor++;
    fold(head, node->next, tail, indx + 1, floor);

    if (indx > floor / 2)
    {
        node->next = head->next;
        head->next = node;
        head = node->next;
    }
    if (indx == floor / 2)
    {
        tail = head;
        head->next = nullptr;
    }
}

Node *getMiddle(Node *head)
{
    Node *end = head;
    Node *mid = head;

    while (end != nullptr)
    {
        if (end->next)
        {
            end = end->next->next;
        }
        else
        {
            end = end->next;
        }
        mid = mid->next;
    }
    return mid;
}

Node *getKFirstNode(Node *head, int k)
{
    for (int i = 0; i < k; i++)
    {
        head = head->next;
    }

    return head;
}

Node *getKLastNode(Node *head, int k)
{
    Node *end = getKFirstNode(head, k);
    Node *kNode = head;

    while (end != nullptr)
    {
        end = end->next;
        kNode = kNode->next;
    }

    return kNode;
}

Node *KRevHelp(Node *&head, int k)
{
    Node *prev = nullptr;
    Node *curr = head;
    int counter = 0;
    while (counter < k)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }

    head->next = curr;
    return prev;
}

void kReverse(Node *&head, Node *&tail, int k)
{
    int sz = size(head, tail);
    if (k > sz)
    {
        return;
    }

    Node *t1 = head;
    Node *t2 = KRevHelp(head, k);
    head = t2;

    int counter = k;

    while (sz - counter >= k)
    {
        Node *nt1 = t1->next;
        Node *nt2 = KRevHelp(nt1, k);
        t1->next = nt2;
        t1 = nt1;
        counter += k;
    }

    if (counter == sz)
    {
        tail = t1;
    }
}

void oddEven(Node *&head, Node *&tail)
{
    Node *oddHead = nullptr;
    Node *oddTail = nullptr;
    Node *evenHead = nullptr;
    Node *evenTail = nullptr;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data % 2 == 0)
        {
            if (evenTail == nullptr)
            {
                evenHead = evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else
        {
            if (oddTail == nullptr)
            {
                oddHead = oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        temp = temp->next;
    }

    if (oddTail != nullptr)
    {
        oddTail->next = evenHead;
        head = oddHead;
        tail = evenTail;
    }
    else
    {
        head = evenHead;
        tail = evenTail;
    }
}

void RemoveDuplicates(Node *&head, Node *&tail)
{
    Node *distinctHead = nullptr;
    Node *distinctTail = nullptr;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (!distinctTail)
        {
            distinctHead = distinctTail = temp;
        }
        else if (distinctTail && distinctTail->data != temp->data)
        {
            distinctTail->next = temp;
            distinctTail = temp;
        }
        else if (distinctTail && distinctTail->data == temp->data)
        {
            Node *t2 = temp;
            delete t2;
        }
        temp = temp->next;
    }
    head = distinctHead;
    tail = distinctTail;
}

Node *correctCycle(Node *&slow, Node *fast)
{
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = nullptr;
    return slow;
}

void DetectCycleAndCorrect(Node *head, Node *&tail)
{
    Node *slow = head;
    Node *fast = head;
    if (fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    else
    {
        cout << "No cycle\n";
        return;
    }

    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
        {
            break;
        }

        if (fast->next)
        {
            fast = fast->next->next;
        }
        slow = slow->next;
    }

    if (fast == nullptr || fast->next == nullptr)
    {
        cout << "No Cycle\n";
        return;
    }

    cout << "Cycle Detected\n";
    tail = correctCycle(slow, head);
}

void MergeSortedList(Node *l1, Node *l2, Node *&head, Node *&tail)
{
    Node *temp = nullptr;
    while (l1 || l2)
    {
        if (l1 && l2 && l1->data < l2->data)
        {
            if (temp)
            {
                temp->next = l1;
                temp = l1;
            }
            else
            {
                head = temp = l1;
            }
            l1 = l1->next;
        }
        else if (l1 && l2 && l1->data > l2->data)
        {
            if (temp)
            {
                temp->next = l2;
                temp = l2;
            }
            else
            {
                head = temp = l2;
            }
            l2 = l2->next;
        }
        else if (l1)
        {
            if (temp)
            {
                temp->next = l1;
                temp = l1;
            }
            else
            {
                head = temp = l1;
            }
            l1 = l1->next;
        }
        else if (l2)
        {
            if (temp)
            {
                temp->next = l2;
                temp = l2;
            }
            else
            {
                head = temp = l2;
            }
            l2 = l2->next;
        }
    }
    tail = temp;
    tail->next = nullptr;
    return;
}

Node *getMidNode(Node *&head, Node *&tail)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void mergesort(Node *&head, Node *&tail)
{
    if (head == tail) {
        // Node *nn = new Node(head->data, nullptr);
        // head = tail = nn;
        head->next = nullptr;
        return;
    }
    Node *mid = getMidNode(head, tail);
    Node *lh = head;
    Node *lt = mid;
    Node *rh = mid->next;
    Node *rt = tail;

    mergesort(lh, lt);
    mergesort(rh, rt);

    Node *fh = nullptr;
    Node *ft = nullptr;
    
    MergeSortedList(lh, rh, fh, ft);

    head = fh;
    tail = ft;
    return;
}

int main(int argc, char **argv)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    // AddFirst(head, tail, 10);
    // AddFirst(head, tail, 20);
    // AddFirst(head, tail, 30);
    // AddFirst(head, tail, 40);
    // AddFirst(head, tail, 45);
    // AddFirst(head, tail, 50);
    // AddFirst(head, tail, 60);
    // AddAt(head, tail, 600, 4);
    // AddAt(head, tail, 700, 0);
    // AddAt(head, tail, 800, 7);

    AddFirst(head, tail, 10);
    AddFirst(head, tail, 11);
    AddFirst(head, tail, 40);
    AddFirst(head, tail, 43);
    AddFirst(head, tail, 30);
    AddFirst(head, tail, 30);
    AddFirst(head, tail, 30);
    AddFirst(head, tail, 20);
    AddFirst(head, tail, 10);

    // Node *head1 = nullptr, *tail1 = nullptr;
    // Node *head2 = nullptr, *tail2 = nullptr;
    // AddFirst(head1, tail1, 50);
    // AddFirst(head1, tail1, 40);
    // AddFirst(head1, tail1, 30);
    // AddFirst(head1, tail1, 20);
    // AddFirst(head1, tail1, 20);
    // AddFirst(head1, tail1, 10);

    // AddFirst(head2, tail2, 55);
    // AddFirst(head2, tail2, 45);
    // AddFirst(head2, tail2, 35);
    // AddFirst(head2, tail2, 25);
    // AddFirst(head2, tail2, 25);
    // AddFirst(head2, tail2, 15);
    // Node *dups = getAt(head, tail, 3);
    // tail->next = dups;
    // removeFirst(head, tail);
    // removeLast(head, tail);

    // display(head, tail);

    // reverseList(head, tail);
    cout << "Original List:\t";
    // display(head, tail);

    // reverseList2(head, tail);

    // cout << "ReverseList:\t";
    // display(head, tail);

    // // displayReverseRecursive(head);

    // cout << "Reverse Recur:\t";
    // reverseRecursive(head, head, tail);
    // display(head, tail);

    // Node *temp = head;
    // cout << "Rev Data recur:\t";
    // reverseDataRecursive(temp, tail);
    // display(head, tail);

    // int data = 0;
    // display(head1, tail1);
    // a->b->c->d->e == a->e->b->d->c
    // display(head, tail);

    // cout << isPalindrome(temp, temp, 0, data);
    // cout << endl;

    // cout << "fold:\t";
    // fold(temp, temp, tail, 0, data);
    // AddLast(head, tail, 14);
    // display(head, tail);

    // cout << getMiddle(head)->data << endl;

    // cout << getKLastNode(head, 1)->data << endl;

    // kReverse(head, tail, 3);
    // oddEven(head, tail);
    // RemoveDuplicates(head, tail);
    // DetectCycleAndCorrect(temp, tail);

    // MergeSortedList(head1, head2, head, tail);
    Node *sh = head;
    Node *st = tail;
    mergesort(sh, st);
    display(sh, st);
    AddLast(sh, st, 300);
    display(head, tail);
}