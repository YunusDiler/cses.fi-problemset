#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

using namespace std;

int main()
{
    need_for_speed;
    int t;
    cin >> t;
    while (t--)
    {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double m = (y2 - y1) / (x2 - x1);
        double b = y2 - (m * x2);
        double f = (m * x3) + b;

        if (f == y3)
            cout << "TOUCH" << endl;
        else if (m > 0)
        {
            if (f < y3)
            {
                if (x1 < x2)
                    cout << "RIGHT" << endl;
                else
                    cout << "LEFT" << endl;
            }
            else
            {
                if (x1 < x2)
                    cout << "LEFT" << endl;
                else
                    cout << "RIGHT" << endl;
            }
        }
        else
        {
            if (f < y3)
            {
                if (x1 < x2)
                    cout << "LEFT" << endl;
                else
                    cout << "RIGHT" << endl;
            }
            else
            {
                if (x1 < x2)
                    cout << "RIGHT" << endl;
                else
                    cout << "LEFT" << endl;
            }
        }
    }

    return 0;
}