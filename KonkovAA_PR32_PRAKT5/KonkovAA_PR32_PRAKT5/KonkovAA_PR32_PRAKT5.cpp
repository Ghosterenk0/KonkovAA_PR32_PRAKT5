#include <iostream>
#include <cstdlib>
class DoublyLinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int Data) : data(Data), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int count = 0;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value) {
        Node* node = new Node(value);
        if (head != nullptr) {
            node->next = head;
            head->prev = node;
            head = node;
        }
        else {
            head = node;
        }
        count++;
    }
    void push_back(int value) {
        Node* node = new Node(value);
        if (tail != nullptr) {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        else {
            head = tail = node;
        }
        count++;
    }

    void pop_front() {
        Node* node;
        node = head->next;
        delete head;
        node->prev = nullptr;
        head = node;
    }
    void pop_back() {
        Node* node;
        node = tail->prev;
        delete tail;
        node->next = nullptr;
        tail = node;
    }
    void display() {
        Node* node = head;
        while (node != nullptr) {
            std::cout << node->data << " ";
            node = node->next;
        };
        std::cout << std::endl;
    }
    void sort() 
    {

    }
    void remove_duplicate() {
        Node* node = head;
        Node* node2 = head->next;
        while (node != nullptr) {
            while (node2->next != nullptr) {
                if (node2->next != nullptr && node->data == node2->data)
                {
                    node->next = node2;
                    node->next->prev = node;
                    delete node2;
                }
                else if(node->data == node2->data) {
                    node->next = nullptr;
                    node2->data = 0;
                    delete node2;
                }
                node2 = node2->next;
            }
            node = node->next;
        }
    }
};

void Menu()
{
    std::cout << "1. Добавить элемент в начало" << std::endl;
    std::cout << "2. Добавить элемент в конец" << std::endl;
    std::cout << "3. Удалить элемент с начало" << std::endl;
    std::cout << "4. Удалить элемент с конца" << std::endl;
    std::cout << "5. Отобразить список" << std::endl;
    std::cout << "6. Сортировать список" << std::endl;
    std::cout << "7. Удалить дубликаты" << std::endl;
    std::cout << "8. Выйти" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    bool f = true;
    DoublyLinkedList list;
    while (f != false) {
        Menu();
        int user;
        int c;
        std::cin >> user;
        switch (user)
        {
        case 1:
            std::cout << "Введите число: " << std::endl;
            std::cin >> c;
            list.push_front(c);
            break;
        case 2:
            std::cout << "Введите число: " << std::endl;
            std::cin >> c;
            list.push_back(c);
            break;
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            list.display();
            break;
        case 6:
            list.sort();
            std::cout << "Отсортирован" << std::endl;
            break;
        case 7:
            list.remove_duplicate();
            break;
        case 8:
            f = false;
            break;
        default:
            std::cout << "Некорректно выбранное действие" << std::endl;
            break;
        }
    }
}
