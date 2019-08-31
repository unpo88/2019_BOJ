#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    
    int A, B;

    A = (str1[0] - 48) * 100 + (str1[1] - 48) * 10 + (str1[2] - 48);
    B = (str2[0] - 48) * 100 + (str2[1] - 48) * 10 + (str2[2] - 48);

    cout << max(A,B);
    return 0;
}