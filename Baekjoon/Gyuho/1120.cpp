#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B;

    int answer = 51;
    for (int i = 0; i <= B.length() - A.length(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < A.length(); j++)
        {
            if (A[j] != B[j + i])
            {
                cnt++;
            }
        }
        answer = min(answer, cnt);
    }

    cout << answer << "\n";

    return 0;
}