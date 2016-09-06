#include <iostream>
#include <vector>

using namespace std;

const int max_size = 5;

struct Pilha{

    int _data[max_size];
    int _size {0};


    int top(){
        if(_size == 0){
            return 0;
        }
        return _data[_size - 1];
    }

    int size(){
        return _size;
    }

    bool push(int value){
        if(_size == max_size){
            return false;
        }

        _data[_size] = value;
        _size++;
        return true;
    }

    bool pop(){
        if(_size > 0){
            _size--;
            _data[_size] = 0;
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    //crie um vetor de 5 inteiros com ponteiro
    int * vet = new int[5];

    delete [] vet;


    return 0;
}















