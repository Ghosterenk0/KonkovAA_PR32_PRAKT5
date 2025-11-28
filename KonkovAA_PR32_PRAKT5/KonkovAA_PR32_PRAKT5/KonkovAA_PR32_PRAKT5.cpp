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
        while (node != nullptr){
            std::cout << node->data << " ";
            node = node->next;
        };
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
        std::cin >> user;
        switch (user)
        {
        case 1:
            list.push_front(1);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            list.display();
            break;
        case 6:
            break;
        case 7:
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

