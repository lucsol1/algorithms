#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
struct Node {
    T elem;
    Node* next;
    Node(const T& e, Node* n=nullptr): elem(e), next(n) {} 
};

template<typename T>
class LinkedList {
    Node<T>* head = nullptr;
    size_t n = 0;

    public:
        bool empty() const { return head == nullptr; }
        size_t size() const { return n; }
        void add(const T& e ) { 
            Node<T>* newItem = new Node<T>(e);

            if (empty())
            {
                head = newItem;
            } else {
                Node<T>* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newItem;
            }
            ++n;
        }
        void remove() {
            if(empty()) throw std::runtime_error("List is empty");
            auto tmp = head;
            head = head->next;
            delete tmp;
            --n;
        } 
        const T& first() const { if(empty()) throw std::runtime_error(""); return head->elem; }
        void print() const {
            Node<T>* current = head;

            while (current != nullptr) {
                std::cout << current->elem;
                if (current->next != nullptr)
                    std::cout << " -> ";
                current = current->next;
            }
            std::cout << " -> nullptr\n";
        }

        ~LinkedList() {
        while (!empty()) {
            remove();
        }
    }
};

int main() {
    LinkedList<int> list;

    list.add(10);
    list.add(20);
    list.add(30);

    list.print();
}
