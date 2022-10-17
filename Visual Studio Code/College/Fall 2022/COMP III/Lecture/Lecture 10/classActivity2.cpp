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
    LinkedList(ListNode *arr, int arrSize);
    ~LinkedList();

    void display();
    void preAppend(int);
    void deleteItem(int);

    ListNode* getlistHead(void) const;

private:
    ListNode *head;
};

int main (int argc, char * argv[]) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    LinkedList listFromArr(arr, sizeof(arr)/sizeof(int));
    listFromArr.display();
    //listFromArr.deleteItem(3);
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
    head = nullptr;

    for (int i = arrSize -1 ; i >= 0; i--) {
        /*
        ListNode* newNode;
        newNode = new ListNode(arr[i], head);
        head = newNode;
        */
        preAppend(arr[i]);
    }
}

void LinkedList::preAppend(int newVariable) {
    ListNode* newNode = new ListNode(newVariable, head);
    head = newNode;
}

void LinkedList::deleteItem(int position) {
    ListNode* tmp = nullptr;
    ListNode* tmp1 = nullptr;
    int length = 0;

    if (getlistHead() == nullptr) {
        cout << "Empty List!" << endl;
        return;
    }

    while (tmp != nullptr) {
        tmp = tmp->getlistNext();
        length++;
    }

    if (length < position) {
        cout << "Position out of range!" << endl;
        return;
    }

    tmp = getlistHead();

    if (position == 1) {
        LinkedList(tmp->getlistNext());
        delete tmp;
        return;
    }

    while (position-- > 1) {
        tmp1 = tmp;
        tmp = tmp->getlistNext();
    }

    tmp1->setlistNext(tmp->getlistNext());
    delete tmp;
}

void LinkedList::display() {
    ListNode* tmp = head;

    if (tmp == nullptr) {
        cout << "Empty List!" << endl;
        exit(1);
    }

    while (tmp != nullptr) {
        cout << tmp->getlistData() << "->";
        tmp = tmp->getlistNext();
    }
    cout << "NULL" << endl;
}

ListNode* LinkedList::getlistHead(void) const {
    return head;
}

LinkedList::LinkedList(ListNode *arr, int arrSize) {
    LinkedList newArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ListNode* tmp = head;
    ListNode* tmp1 = head;

    for (int i = 0; i < arrSize; i++) {
        tmp->getlistData();
        newArr[i] = tmp;
        tmp1->getlistNext();
        tmp = tmp1;
    }
}

LinkedList::~LinkedList() {
    ListNode *tmp = head;

    while (head != nullptr) {
        tmp = head;
        head = head->getlistNext();
        tmp->setlistNext(nullptr);
        delete tmp;
    }
}