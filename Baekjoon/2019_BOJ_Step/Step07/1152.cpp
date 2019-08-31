#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    string str;
    getline(cin, str);

    int result = 1;

    if(str[0] == ' '){
        result = 0;
    }

    for(int i = 0; i < str.size(); ++i){
        if(str[i] == ' '){
            result++;
        }
    }

    if(str[str.size() - 1] == ' '){
        result --;
    }

    cout << result << "\n";

    return 0;
}