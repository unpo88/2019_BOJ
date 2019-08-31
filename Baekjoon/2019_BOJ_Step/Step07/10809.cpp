#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    string str;
    cin >> str;

    int result[26];
    bool check[26];

    fill_n(result, 26, -1);
    fill_n(check, 26, false);

    for(int i = 0; i < str.size(); ++i){
        if(!check[str[i] - 97]){
            result[str[i] - 97] = i;
            check[str[i] - 97] = true;
        }
    }

    for(int i = 0; i < 26; ++i){
        cout << result[i];
        if(i != 25){
            cout << " ";
        }
    }

    return 0;
}