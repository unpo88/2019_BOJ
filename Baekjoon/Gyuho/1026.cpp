#include <iostream>
#include <algorithm>
using namespace std;

int A[51];
int B[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    sort(A, A + N);

    sort(B, B + N);
    reverse(B, B + N);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += (A[i] * B[i]);
    }

    cout << sum << "\n";

    return 0;
}