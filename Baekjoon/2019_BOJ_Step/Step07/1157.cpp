#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    string str;
    cin >> str;

    int result[26];
    fill_n(result, 26, 0);

    int index;
    int max = 0;

    for(int i = 0; i < str.size(); ++i){
        if(int(str[i]) >= 65 && int(str[i]) <= 90){
            result[str[i] - 65]++;
            if(max < result[str[i] - 65]){
                max = result[str[i] - 65];
            } 
        }else{
            result[str[i] - 97]++;
            if(max < result[str[i] - 97]){
                max = result[str[i] - 97];
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < 26; ++i){
        if(max == result[i]){
            cnt++;
            index = i;
        }
    }

    if(cnt == 1){
        cout << char(index + 65) << "\n";
    }else{
        cout << "?" << "\n";
    }

    
    return 0;
}