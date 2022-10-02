// Contributed by lucy2512 (https://github.com/lucy2512)

#include <iostream>
using namespace std;



double SqrtNumber(double num)
{
        double lower_bound = 0;
        double upper_bound = num;
        double temp = 0;

        int nCount = 50;

        while (nCount != 0)
        {
                temp = (lower_bound + upper_bound) / 2;
                if (temp * temp == num)
                {
                        return temp;
                }
                else if (temp * temp > num)
                {
                        upper_bound = temp;
                }
                else
                {
                        lower_bound = temp;
                }
                nCount--;
        }
        return temp;
}

int main()
{
        double num;
        cout << "Enter the number: ";
        cin >> num;

        cout << "Square root is:" << SqrtNumber(num);
        return 0;
}