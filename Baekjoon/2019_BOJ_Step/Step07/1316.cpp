#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;
    cin >> N;

    int result = 0;

    while(N--){
        string str;
        cin >> str;

        bool check[26];
        fill_n(check, 26, false);

        bool flag = false;
        int answer = 1;
        for(int i = 0; i < str.size(); ++i){
            if(!flag && check[str[i] - 97]){
                answer = 0;
                break;
            }
            
            if(!check[str[i] - 97] && !flag){
                check[str[i] - 97] = true;
                flag = true;
            }

            if(str[i] != str[i+1]){
                flag = false;
            }
        }
        result += answer;
    }

    cout << result << "\n";
    return 0;
}