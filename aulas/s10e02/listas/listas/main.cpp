#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};



//clone e equals

struct SList{
    Node * head {nullptr};
    SList(){
    }

    SList(SList &other){
        //copiar(stringstream(other.serialize()));
        //head = clonar(other.head);
        Node * nother = other.head;
        if(nother == nullptr)
            return;
        head = new Node(nother->value);
        auto node = head;
        while (nother->next != nullptr) {
            node->next = new Node(nother->next->value);
            node = node->next;
            nother = nother->next;
        }
    }
    Node * clonar(Node * other){
        if(other == nullptr)
            return nullptr;
        auto node = new Node(other->value);
        node->next = clonar(other->next);
        return node;
    }

    void clonar(Node ** casa, Node * other){
        if(other != nullptr){
            *casa = new Node(other->value);
            clonar(&(*casa)->next, other->next);
        }
    }

    bool requals(Node * node, Node * other){
        if(node == nullptr && other == nullptr)
            return true;
        if(node == nullptr && other != nullptr)
            return false;
        if(node != nullptr && other == nullptr)
            return false;
        if(node->value != other->value)
            return false;
        return requals(node->next, other->next);
    }

    bool equals(SList &other){
        return requals(head, other.head);
    }

    //alterar para
    //"[ 1 3 5 6 7 7 7 8 ]"
    SList(string serial){
        stringstream sstring(serial);
        copiar(sstring);
    }

    string copiar(stringstream &serial){
        string lixo;
        sstring >> lixo;
        int valor;
        while(sstring >> valor){
            insert_rec(valor);
        }
    }

    //gerar [ 1 3 5 6 7 7 7 8 ]
    string serialize(){
        stringstream serial;
        show(serial);
        return serial.str();
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

    void rshow(Node * node, ostream &saida = cout){
        if(node == nullptr){
            return;
        }
        saida << node->value << " ";
        rshow(node->next, saida);
    }

    //[ 1 2 3 5 3 5 7 6 ]
    void show(ostream &saida = cout){
        saida << "[ ";
        rshow(this->head, saida);
        saida << "]";
    }
};

int main(){
    SList lista("[ 1 3 4 6 6 6 7 9 ]");
    cout << lista.serialize() << endl;
    return 0;
}





