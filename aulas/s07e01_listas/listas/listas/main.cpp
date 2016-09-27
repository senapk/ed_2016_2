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

    int size(){
        int count = 0;
        auto node = head;
        while(node != nullptr){
            node = node->next;
            count++;
        }
        return count;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        auto aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value);

    void pop_back();

    //retorna o node ou null
    Node * find(int value);

    //remove esse nó da lista
    bool erase(Node * node);

    //insere o elemento antes desse no
    bool insert(Node * node, int value);

};

int main()
{
    SList lista;
    for(int i = 0; i < 10; i += 2)
        lista.push_front(i);
    lista.print();
    return 0;
}












