#include <iostream>

using namespace std;

int main()
{
    int T;

    cin >> T;

    int* M = new int[T];
    int* N = new int[T];
    int* x = new int[T];
    int* y = new int[T];


    int k;
    for (int i = 0; i < T; i++)
    {
        cin >> M[i] >> N[i] >> x[i] >> y[i];
    }

    int interval;
    int count;
    int temp;
    for (int i = 0; i < T; i++)
    {
        interval = M[i] - N[i];
        count = 0;
        temp = x[i];
        while (temp != y[i]) 
        {
            temp += interval;
            if (temp <= 0) 
            {
                temp += N[i];
            }
            if (temp > N[i]) 
            {
                temp -= N[i];
            }
            count += 1;
            // 존재하지 않을 때
            if (temp == x[i]) 
            {
                count = -1;
                break;
            }
        }
        if (count == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            k = count * M[i] + x[i];
            cout << k << endl;
        }
    }

    delete[] M;
    delete[] N;
    delete[] x;
    delete[] y;

    return 0;
}
