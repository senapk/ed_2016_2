#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    vector<string> vthings = {"uva", "ovo", "avo", "vovo"};

    vthings.push_back("ivo");
    vthings.pop_back();

    for(auto &vt : vthings)
        cout << vt << " ";
    cout << "\n";
    for(int i = 0; i < (int) vthings.size(); i++){
        cout << vthings[i] << " ";
    }
    cout << "\n";

    list<string> amores = {"choco", "feij", "avent", "fam"};
    for(auto &x : amores){
        cout << x << " ";
    }

    cout << "\n";
    for(auto it = amores.begin(); it != amores.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    stack<string> alunos;
    queue<string> gambi_master;

    vector<string> gambi {"vovo", "ovo", "avo", "ivo", "uva", "eva"};

    for(auto x : gambi){
        alunos.push(x);
        gambi_master.push(x);
    }

    while(!alunos.empty()){
        cout << alunos.top() << " ";
        alunos.pop();
    }
    cout << "\n";

    while(!gambi_master.empty()){
        cout << gambi_master.front() << " ";
        gambi_master.pop();
    }
    cout << "\n";

    return 0;
}













