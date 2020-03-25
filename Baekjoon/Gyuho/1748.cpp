#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    long long sum = 0;
    int ten = 10;
    int cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        if (i == ten)
        {
            ten *= 10;
            cnt += 1;
        }
        sum += cnt;
    }

    cout << sum << "\n";

    return 0;
}