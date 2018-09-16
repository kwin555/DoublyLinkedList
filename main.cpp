//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Kevin Nguyen on 9/13/18.
//  Copyright © 2018 Kevin Nguyen. All rights reserved.
//

#include <iostream>


template <class T>
struct node {
    T data;
    node<T> *next;
    node<T> *prev;
};


template <class T>
class list {
private:
    node<T> *head;
    node<T> *tail;
public:
    list();
    void addBeginning(T input);
    void addEnd(T input);
    bool isEmpty();
    bool deleteContent(T input);
    int length();
    bool isPalindrome();
    void createList(T input);
    void print();
    void printReverse();
};

int main(int argc, const char * argv[]) {
    std::string input;
    list<char> myList;
    std::cout << "Enter a word:" << std::endl;
    std::cin >> input;
    for (int i = 0; i < input.length(); i++) {
        myList.addBeginning(input.at(i));
    }
    std::cout << "Input is palindrome: (true/false) " << std::boolalpha << myList.isPalindrome() << "\n";
}

template <class T>
bool list<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void list<T>::print() {
    node<T> *current = head;
    while(current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

template <class T>
void list<T>::printReverse() {
    node<T> *current = tail;
    while(current != nullptr) {
        
        std::cout << std::boolalpha << current->data << " ";
        current = current->prev;
    }
}

template<class T>
void list<T>::createList(T input) {
    node<T> *current, *temp;
    temp = new node<T>;
    temp->data = input;
    temp->next = nullptr;
    if(head == nullptr) {
        temp->prev = nullptr;
        head = temp;
        tail = temp;
    } else {
        current = head;
        while(current->next != nullptr) {
            current = current->next;
            current->next = temp;
            temp->prev = current;
            tail = temp;
        }
    }
}

template <class T>
bool list<T>::isPalindrome() {
    node<T> *left = head;
    // if the linked list is empty
    if(left == nullptr) {
        return true;
    }
    //move set up the right side of the linked list
    node<T> *right = new node<T>;
    right = left;
    //moving the right node to the last node the left side
    while (right->next != nullptr) {
        right = right->next;
    }
    // making sure the left and right nodes does not cross
    while (left != right) {
        //checking to see if the left and right sides  equal
        if (left->data != right->data) {
            return false;
        }
        //moving the nodes along
        left = left->next;
        right = right->prev;
    }
    return true;
}

template <class T>
list<T>::list() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
int list<T>::length() {
    node<T> *current = head;
    int length = 0;
    while(current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

template<class T>
bool list<T>::deleteContent(T input) {
    node<T> temp = new node<T>;
    node<T> current = head;
    if (head == nullptr)
        return false;
    
    while(current != nullptr && current->data != input) {
        current = current->next;
        if (current == nullptr) { // could not find the input value
            return false;
        } else {       // found the input value
            temp = current;
            current->prev->next = temp->next;
            current->next->prev = temp->previous;
            delete temp;
            return true;

        }
    }
    
}

template<class T>
void list<T>::addEnd(T input) {
    node<T> *tempNode = new node<T>;
    node<T> * current = head;
    while (current->next == nullptr) {
        current = current->next;
    }
    tempNode->data = input;
    current->next = tempNode;
    tempNode->next = nullptr;
    tempNode->prev = current;
    tail = tempNode;
}

template <class T>
void list<T>::addBeginning(T input) {
    node<T> *tempNode = new node<T>;
    tempNode->data = input;
    if(isEmpty()) {
        head = tempNode;
        tail = tempNode;
    } else {
        head->prev = tempNode;
        tempNode->next = head;
        head = tempNode;
    }
}
