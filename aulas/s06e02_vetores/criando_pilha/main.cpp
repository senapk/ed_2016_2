#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    vector<int> vet{4, 3, 2, 6, 7, 1, 1, 1};

    auto it = std::find(vet.begin(), vet.end(), 2);
    vet.insert(it, 1);
    it = std::find(vet.begin(), vet.end(), 3);
    vet.erase(it);

    it = vet.begin();
    while(it =! vet.end()){
        it = std::remove(it, vet.end(), 1);
    }

    return 0;
}













