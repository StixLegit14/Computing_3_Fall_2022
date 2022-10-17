//
//  Lecture_15_LinkedListClass.cpp
//  Overload = operator for LinkedList
//

#include <iostream>
using namespace std;

class ListNode{
public:
    ListNode();
    ListNode(int initData, ListNode *initNext);
    ~ListNode();
    
    int getData(void) const;
    ListNode * getNext(void) const;
    void setData(int newData);
    void setNext(ListNode * newNext);
    
    friend ostream& operator<<(ostream& out, const ListNode &aNode);
    
private:
    int data;
    ListNode *next;
};
ostream& operator<<(ostream& out, const ListNode& aNode)
{
    out << aNode.data;
    return out;
}

class LinkedList
{
public:
    LinkedList();
    LinkedList(ListNode *initHead);
    LinkedList(const LinkedList &l); //Copy constructor
    ~LinkedList();//destructor
    
    //other public member functions
    void preAppend(int nv); //insert a new node as the head, whose node value is nv
    //void print() const;
    void setHead(int newData);
    friend ostream& operator<<(ostream& out, const LinkedList &aList);
        
private:
    ListNode *head;
};

ostream& operator<<(ostream& out, const LinkedList &aList);
LinkedList& operator=(const LinkedList& obj1, LinkedList& obj2);
{
    if (aList.head == nullptr) {
        cout << "Empty List" << endl;
    } else {
        ListNode *temp = aList.head;
        cout << "< ";
        while (temp != nullptr) {
            cout << temp->getData();
            temp = temp->getNext();
            if (temp != nullptr) cout << ", ";
        }
        cout << ">";
    }
    return out;
}

int main(int argc, const char * argv[])
{
    ListNode node1(1, nullptr);
    ListNode node2;
    node2 = node1;
    
    cout << "node1: " << node1 << endl;
    cout << "node2: " << node2 << endl;
    
    
    LinkedList list1, listCopy;
    
    list1.preAppend(5);
    list1.preAppend(8);
    cout << "list1 is: " << list1 << endl;
    listCopy = list1;
    listCopy = listCopy;
    
    list1.setHead(66);
    cout << "list1 is: " << list1 << endl;
    cout << "listCopy is: " << listCopy << endl;
    
    return 0;
}

///////////////////  Class ListNode ////////////////////
ListNode::ListNode():data(0), next(nullptr){}

ListNode::ListNode(int initData, ListNode *initNext):data(initData), next(initNext){}

ListNode::~ListNode() {
    next = nullptr;
}

int ListNode::getData(void) const
{
    return data;
}

ListNode* ListNode::getNext(void) const
{
    return next;
}

void ListNode::setData(int newData)
{
    data = newData;
}

void ListNode::setNext(ListNode * newNext)
{
    next = newNext;
}


/////////////////// Class LinkedList //////////////////
LinkedList::LinkedList():head(nullptr){}

LinkedList::LinkedList(ListNode *initHead):head(initHead){}

LinkedList::LinkedList(const LinkedList &l)
{
    head = nullptr;
    ListNode *cursor = nullptr;
    ListNode *lCursor = l.head;
    while (lCursor != nullptr)
    {
        ListNode *newNode = new ListNode(lCursor->getData(), nullptr);
        if (head == nullptr) {
            cursor = newNode;
            head = cursor;
        } else {
            cursor->setNext(newNode);
            cursor = newNode;
        }
        lCursor = lCursor->getNext();
    }
}


LinkedList::~LinkedList()
{
    //cout << "\nIn LinkedList destructor" << endl;
    ListNode *cursor;
    
    for (cursor = head; cursor != nullptr;)
    {
        cursor = head->getNext();
        //cout << "remove " << head->getData() << endl;
        delete head;
        head = cursor;
    }
}


void LinkedList::preAppend(int nv)
{
    ListNode *newNode = new ListNode(nv, head);
    head = newNode;
}


void LinkedList::setHead(int newData)
{
    head->setData(newData);
};










/*
 //1:
 ListNode *cursor;
 
 for (cursor = head; cursor != nullptr;)
 {
     cursor = head->getNext();
     //cout << "remove " << head->getData() << endl;
     head->setNext(nullptr);
     delete head;
     head = cursor;
 }
 
 //2:
 head = nullptr;
 cursor = nullptr;
 ListNode *lCursor = rList.head;
 while (lCursor != nullptr)
 {
     ListNode *newNode = new ListNode(lCursor->getData(), nullptr);
     if (head == nullptr) {
         cursor = newNode;
         head = cursor;
     } else {
         cursor->setNext(newNode);
         cursor = newNode;
     }
     lCursor = lCursor->getNext();
 }
 
 return *this;
 */