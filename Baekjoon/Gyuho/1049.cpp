#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int min_package_charge = 1000;
    int min_single_charge = 1000;
    for (int i = 0; i < M; i++)
    {
        int package_charge, single_charge;
        cin >> package_charge >> single_charge;

        min_package_charge = min(min_package_charge, package_charge);
        min_single_charge = min(min_single_charge, single_charge);
    }

    int answer = 0;
    if (min_package_charge < min_single_charge * 6)
    {
        answer += min_package_charge * (N / 6);
    }
    else
    {
        answer += (N / 6) * 6 * min_single_charge;
    }

    N %= 6;

    if (min_package_charge < N * min_single_charge)
    {
        answer += min_package_charge;
    }
    else
    {
        answer += N * min_single_charge;
    }

    cout << answer << "\n";
    return 0;
}