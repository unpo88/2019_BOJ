#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    string str;
    cin >> str;

    int result = 0;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 'c' && str[i+1] == '='){
            result++;
            i += 1;
        }else if(str[i] == 'c' && str[i+1] == '-'){
            result++;
            i += 1;
        }else if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '='){
            result++;
            i += 2;
        }else if(str[i] == 'd' && str[i+1] == '-'){
            result++;
            i += 1;
        }else if(str[i] == 'l' && str[i+1] == 'j'){
            result++;
            i += 1;
        }else if(str[i] == 'n' && str[i+1] == 'j'){
            result++;
            i += 1;
        }else if(str[i] == 's' && str[i+1] == '='){
            result++;
            i += 1;
        }else if(str[i] == 'z' && str[i+1] == '='){
            result++;
            i += 1;
        }else{
            result++;
        }
    }

    cout << result;
    return 0;
}