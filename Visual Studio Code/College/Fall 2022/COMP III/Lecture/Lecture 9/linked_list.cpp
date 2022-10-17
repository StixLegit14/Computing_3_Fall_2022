/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 09/24/22
Name: Matthew Flores
*/
/***********************************************
Author: Matthew Flores
Date: 09/19/22
Purpose: Implement Linked Lists :(
Sources of Help: None
Time Spent: 30 min
***********************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

class ListNode {

public:
    ListNode();
    ListNode(int iData, ListNode *iNext);

    int getlistData(void) const;
    ListNode* getlistNext(void) const;

    void setlistNode(int newData);
    void setlistNext(ListNode *newNext);

private:
    int data;
    ListNode *next;
};

class LinkedList {

public:
    LinkedList();
    LinkedList(ListNode *iHead);
    LinkedList(const int *arr, int arrSize);

    void display();
    void preAppend(ListNode* iHead);
    void deleteItem(int);

    ListNode* getlistHead(void) const;

private:
    ListNode *head;
};

int main (int argc, char * argv[]) {

    /*
    //create 3 basic nodes
    ListNode *head = nullptr;
    ListNode *one = nullptr;
    ListNode *two = nullptr;
    ListNode *three = nullptr;

    //allocate 3 nodes
    one = new ListNode();
    two = new ListNode();
    three = new ListNode();

    //assign values
    one->setlistNext(two);
    two->setlistNext(three);
    three->setlistNext(nullptr);

    //get node values and print it out
    head = one;
    while (head != nullptr) {
        cout << head->getlistData() << "->";
        head = head->getlistNext();
    }
    cout << "NULL" << endl;

    //give node data actual values
    one->setlistNode(1);
    two->setlistNode(2);
    three->setlistNode(3);

    //print out nodes with values
    head = one;
    while (head != nullptr) {
        cout << head->getlistData() << "->";
        head = head->getlistNext();
    }
    cout << "NULL" << endl;
    */
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    LinkedList listFromArr(arr, sizeof(arr)/sizeof(int));
    listFromArr.display();
    listFromArr.deleteItem(3);
    listFromArr.display();

    LinkedList copyList(listFromArr);
    copyList.display();

    return 0;
}

ListNode::ListNode() {
    data = 0;
    next = nullptr;
}

ListNode::ListNode(int iData, ListNode *iNext) {
    data = iData;
    next = iNext;
}

int ListNode::getlistData(void) const {
    return data;
}

ListNode* ListNode::getlistNext(void) const {
    return next;
}

void ListNode::setlistNode(int newData) {
    data = newData;
}

void ListNode::setlistNext(ListNode *newNext) {
    next = newNext;
    //cout << "Hello!" << endl;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(ListNode *iHead) {
    head = iHead;
}

LinkedList::LinkedList(const int *arr, int arrSize) {
    ListNode* tmp = new ListNode;
    ListNode* head = new ListNode;
    ListNode* n = new ListNode;

    if (getlistHead() == nullptr) {
        head->setlistNode(arr[0]);
        (LinkedList(head));
    }

    tmp = getlistHead();

    for (int i = 1; i < arrSize; i++) {
        //cout << i << endl;
        //cout << arr[i] << endl;
        n->setlistNode(arr[i]);
        //cout << "Hello" << endl;
        tmp->setlistNext(n);
        cout << "Made it!" << endl;
        tmp = n;
    }
}

void LinkedList::preAppend(ListNode* iHead) {
    //ListNode* newNode = new ListNode(nv, head);
    //head = newNode;
    ListNode* tmp = getlistHead();
    (LinkedList(iHead));
    iHead->setlistNext(tmp);
}

void LinkedList::deleteItem(int position) {
    ListNode* tmp = nullptr;
    ListNode* tmp2 = nullptr;
    int length = 0;

    if (getlistHead() == nullptr) {
        cout << "Empty List!" << endl;
        exit(1);
    }

    while (tmp != nullptr) {
        tmp = tmp->getlistNext();
        length++;
    }

    if (length < position) {
        cout << "No element in desired range!" << endl;
        exit(1);
    }

    tmp = getlistHead();

    if (position == 1) {
        LinkedList(tmp->getlistNext());
        delete tmp;
        exit(1);
    }

    while (position-- > 1) {
        tmp2 = tmp;
        tmp = tmp->getlistNext();
    }
    tmp2->setlistNext(tmp->getlistNext());
    delete tmp;
}

void LinkedList::display() {
    ListNode* tmp = head;

    if (tmp == nullptr) {
        cout << "Empty List!" << endl;
        exit(1);
    }

    while (tmp != nullptr) {
        cout << tmp->getlistData() << " ";
        tmp = tmp->getlistNext();
    }
}

ListNode* LinkedList::getlistHead(void) const {
    return head;
}