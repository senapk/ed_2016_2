#include <iostream>

using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

//lista simples sem cabeca
struct SList{
    Node * head;
    SList(){
        head = nullptr;
    }

    void push_front (int value){
        Node * node = new Node(value, head);
        head = node;
    }

    void print(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    SList lista;
    for(int i = 0; i < 10; i += 2)
        lista.push_front(i);
    lista.print();
    return 0;
}












