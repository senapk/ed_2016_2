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

#include <sstream>

struct SList{
    Node * head {nullptr};
    SList(){
    }
    //"1 3 5 6 7 7 7 8"
    SList(string serial){
        stringstream sstring(serial);
        int valor;
        while(sstring >> valor){
            insert_rec(valor);
        }
    }

    //recursao com retorno de referencia.
    //insercao
    Node * rinsert(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        if(node->value > value)
            return new Node(value, node);
        node->next = rinsert(node->next, value);
        return node;
    }


    void insert_rec(int value){
        head = rinsert(head, value);
    }

    //recursao com retorno de referencia.
    //remocao
    Node * rremove_rr(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
           auto next = node->next;
           delete node;
           return next;
        }
        node->next = rremove_rr(node->next, value);
        return node;
    }

    void remove_rr(int value){
        head = rremove_rr(head, value);
    }

    //recursao com elo
    //insercao
    void rinsert_elo(Node ** casa, int value){
        auto node = *casa;
        if(node == nullptr)
            *casa = new Node(value);
        if(node->value > value)
            *casa = new Node(value, node);
        rinsert_elo(&node->next, value);
    }

    void insert_elo(int value){
        rinsert_elo(&head, value);
    }


    //insere o elemento na lista ordenada
    void insert_iterativo(int value){
        if(head == nullptr || (head->value > value)){
           head = new Node(value, head);
           return;
        }

        auto node = head;
        while(true){
            if(node->next == nullptr ||
                    (node->next->value > value)){
                node->next = new Node(value, node->next);
                break;
            }
            node = node->next;
        }


    }

    void rshow(Node * node){
        if(node == nullptr){
            return;
        }
        cout << node->value << " ";
        rshow(node->next);
    }

    //[ 1 2 3 5 3 5 7 6 ]
    void show(){
        cout << "[ ";
        rshow(this->head);
        cout << "]" << endl;
    }
};

int main(){
    SList lista("1 3 4 6 6 6 7 9");
    lista.show();
    return 0;
}





