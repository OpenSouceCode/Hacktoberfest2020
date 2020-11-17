#include <iostream>

using namespace std;

int main()
{
    int t, n, num, i, j, sum;
    cin >> t;
    for(i = 0; i < t; i++)
    {
        cin >> n;
        for(j = 0, sum = 0; j < n; j++)
        {
            cin >> num;
            sum += num;
        }
        if(sum < 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
