#include <bits/stdc++.h>
using namespace std;
// O(N)
int fact(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    int chotoFactorial = fact(n - 1);
    return chotoFactorial * n;
}
int main()
{
    int n;
    cin >> n;
    int ans = 1;
    // O(N)
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    cout << ans << endl;
    return 0;
}