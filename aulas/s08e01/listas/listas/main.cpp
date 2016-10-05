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

struct Iter{
    Node * node;

    Iter(Node * head){
        this->node = head;
    }

    int &get_value(){
        return node->value;
    }

    //retorne true se conseguiu ir pro proximo
    void go_next(){
        node = node->next;
    }

    bool is_end(){
        return (node == nullptr);
    }
};


//lista simples sem cabeca
struct SList{
    Node * head;
    SList(){
        head = nullptr;
    }

    Iter begin(){
        return Iter(head);
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

    void push_back(int value){
        auto node = head;
        if(node == nullptr){
            push_front(value);
            return;
        }
        while(node->next != nullptr){
            node = node->next;
        }
        node->next = new Node(value, nullptr);
    }


    //delete não altera as referencias
    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr){
            node = node->next;
        }
        delete node->next;
        node->next = nullptr;
    }

    //retorna o node ou null
    Node * find(int value){
        auto node = head;
        if(node == nullptr)
            return nullptr;
        while(node != nullptr){
            if(node->value == value)
                return node;
            node = node->next;
        }
        return nullptr;
    }

    //remove esse nó da lista
    bool erase(int value){
        auto node = head;
        if(node == nullptr)
            return false;
        //se ele for o primeiro da lista
        if(head->value == value){
            auto vai_morrer = head;
            head = head->next;
            delete vai_morrer;
            return true;
        }
        while(node->next != nullptr){
            if(node->next->value == value){
                auto vai_morrer = node->next;
                node->next = node->next->next;
                delete vai_morrer;
                return true;
            }
            node = node->next;
        }
        return false;
    }

    //remove esse nó da lista
    bool erase(Iter * node){
        (void) node;
        return false;
    }

    //insere o elemento depois desse no
    bool insert(Node * node, int value){
        (void) node;
        (void) value;
        return false;
    }

};

int main()
{
    SList lista;

    for(int i = 0; i < 4; i++)
        lista.push_front(i);

    Iter it = lista.begin();
    for(int i = 0; i < 10; i++){
        cout << it.get_value() << " ";
        it.go_next();
    }

    return 0;
}












