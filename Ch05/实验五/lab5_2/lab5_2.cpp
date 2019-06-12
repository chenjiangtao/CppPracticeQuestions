#include "client.cpp"
#include <iostream> 
using namespace std;

int main() {
    CLIENT a = CLIENT();
    cout << a.ServerName << endl;
    cout << CLIENT::ClientNum << endl;
    a.ChangeServerName('b');
    cout << a.ServerName << endl;
    return 0;
}