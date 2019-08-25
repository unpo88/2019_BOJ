#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int A;
    cin >> A;

    if(A >= 90 && A <= 100){
        cout << "A";
    }else if(A >= 80 && A <= 89){
        cout << "B";
    }else if(A >= 70 && A <= 79){
        cout << "C";
    }else if(A >= 60 && A <= 69){
        cout << "D";
    }else{
        cout << "F";
    }
    return 0;
}