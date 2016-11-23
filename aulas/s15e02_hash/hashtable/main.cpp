#include <iostream>
using namespace std;
const int VAZIO = -1;
const int APAGADO = -2;

struct Item{
    int key;
    int value;

    Item(int key = VAZIO, int value = 0){
        this->key = key;
        this->value = value;
    }

};

struct HashTable{
    int max;
    int size;
    Item * data;

    HashTable(int max){
        this->max = max;
        this->data = new Item[max];
    }

    ~HashTable(){
        delete [] data;
    }

    void show(){
        cout << "|";
        for(int i = 0; i < max; i++)
            cout << i << "," << data[i].key << "," << data[i].value << "|";
        cout << endl;
    }

    //retorna o endereco do elemento ou null
    Item * find(int key){
        int pos = key % this->max;
        while(true){//continue buscando
            if(data[pos].key == VAZIO)
                return nullptr;
            if(data[pos].key == key)
                return &data[pos];
            pos = (pos + 1) % this->max;
        }
        return nullptr;
    }

    bool remove(int key){
        auto encontrado = find(key);
        if(encontrado != nullptr){
            encontrado->key = APAGADO;
            size--;
            return true;
        }
        return false;
    }

    bool insert(int key, int value){
        int pos = key % this->max;

        while (true) {
            if((data[pos].key == VAZIO || data[pos].key == APAGADO)){
                data[pos].key = key;
                data[pos].value = value;
                this->size++;
                return true;
            }
            if(data[pos].key == key)
                break;
            pos = (pos + 1) % this->max;
        }
        return false;
    }
 };

#include <vector>
#include <map>//TreeMap
#include <unordered_map>//Hash_Map
#include <set>//TreeSet
#include <unordered_set>//HashSet

int main()
{   
    HashTable ht(10);
    ht.show();
    return 0;
}

















