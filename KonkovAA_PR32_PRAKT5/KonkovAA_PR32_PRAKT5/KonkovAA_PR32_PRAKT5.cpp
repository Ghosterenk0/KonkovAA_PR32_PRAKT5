#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {

    Node* head = nullptr;
    Node* tail = nullptr;
    

public:

    void Push_front(int value) {
        Node* nodeNew = new Node(value);
        if (head != nullptr) {
            nodeNew->next = head;
            nodeNew->prev = nodeNew;
            head = nodeNew;
        }
    }
    void Push_back(int value) {
        Node* nodeNew = new Node(value);
        if (tail != nullptr) {
            nodeNew->prev = tail;
            nodeNew->next = nodeNew;
            tail = nodeNew;
        }
    }
    void Pop_front() {
        
    }
    void Pop_back() {

    }
    void Sort() {

    }
    void Remove_duplicates() {

    }
    void Display() {

    }
};
    
void Menu() {
    cout << "1. Добавить элемент в начало";
    cout << "2. Добавить элемент в конец";
    cout << "3. Удалить элемент с начало";
    cout << "4. Удалить элемент с конца";
    cout << "5. Отобразить список";
    cout << "6. Сортировать список";
    cout << "7. Удалить дубликаты";
    cout << "8. Выйти";
}

int main()
{
    bool f = true;
    while (f != false) {
        system("cls");
        Menu();
        int user;
        cin >> user;
        switch (user)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            f = false;
            break;
        default:
             cout << "Некорректно выбранное действие";
             break;
        }   
    }
}
