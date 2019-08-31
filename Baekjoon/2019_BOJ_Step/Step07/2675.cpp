#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        int R;
        cin >> R;

        string str;
        cin >> str;

        vector<char> v;
        for(int i = 0; i < str.size(); ++i){
            for(int j = 0; j < R; ++j){
                v.push_back(str[i]);
            }
        }

        for(int i = 0; i < v.size(); ++i){
            cout << v[i];
        }
        cout << "\n";
    }

    return 0;
}