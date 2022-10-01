#include <iostream>
using namespace std;

int fibonacci(int x)
{
    if (x <= 1)
        return x;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
    // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
    cout << fibonacci(6) << endl;
}
