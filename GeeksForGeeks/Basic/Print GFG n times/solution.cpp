#include <iostream>
using namespace std;
void rec(int n){
    if(n==1){
        cout<<"GFG"<<" ";
        return;
    }
    rec(n-1);
    cout<<"GFG"<<" ";
    
}

int main() {
    int n;
    cin >> n;

    // code here
    rec(n);

    return 0;
}
