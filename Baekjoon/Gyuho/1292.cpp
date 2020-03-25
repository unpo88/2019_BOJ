#include <iostream>
using namespace std;

int N[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int A, B;

    cin >> A >> B;

    int num = 1;
    int cnt = 1;
    for (int i = 1; cnt <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            N[cnt++] = num;
            if (cnt == 1001)
                break;
        }
        num++;
    }

    int sum = 0;
    for (int i = A; i <= B; i++)
    {
        sum += N[i];
    }

    cout << sum << "\n";

    return 0;
}