#include <iostream>
#include <vector>

using namespace std;

struct Pilha{

    int * _data;
    int _size {0};
    int _max;

    Pilha(int max){
        _max = max;
        _data = new int[_max];
    }

    ~Pilha(){
        delete [] _data;
    }

    int &top(){
        static int dummy = 0;
        if(_size == 0){
            return dummy;
        }
        return _data[_size - 1];
    }

    int size(){
        return _size;
    }

    void push(int value){
        if(_size == _max){
            cout << "Pilha cheia, realocando" << endl;
            int * aux = _data;
            _max = 2 * _max;
            _data = new int[_max];
            for(int i = 0; i < _size; i++){
                _data[i] = aux[i];
            }
            delete [] aux;

            cout << "Pilha cheia" << endl;
        }

        _data[_size] = value;
        _size++;;
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

int main(){
    Pilha pilha(3);
    pilha.push(1);
    pilha.push(2);
    pilha.push(4);

    pilha.push(9);
    pilha.push(9);

    return 0;
}













