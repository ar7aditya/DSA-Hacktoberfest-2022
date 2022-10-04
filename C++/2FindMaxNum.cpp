#include <iostream>
using namespace std;

typedef struct minmax
{
    int min;
    int max;
} Mm;

struct minmax getMinMax(int a[], int n)
{
    struct minmax pair;

    if (n == 1)
    {
        pair.min = a[0];
        pair.max = a[0];
        return pair;
    }

    pair.min = a[0];
    pair.max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < pair.min)
        {
            pair.min = a[i];
        }

        if(a[i] > pair.max){
            pair.max = a[i];
        }
    }

    return pair;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 20, 10, 200, 2, 13, 43, 5, 26, 7};

    int n = sizeof(a) / sizeof(a[0]);

    struct minmax structure = getMinMax(a, n);

    cout<<"min is "<<structure.min<<endl;
    cout<<"max is "<<structure.max<<endl;

    return 0;
}


/*
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1, 20, 10, 200, 2, 13, 43, 5, 26, 7};
    int n = sizeof(a)/sizeof(a[0]);

    int min, max;

    min = max = a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i] < min ){
            min = a[i];
        }

        if (a[i] > max){
            max = a[i];
        }
    }

    cout<<"min is "<< min<<endl;
    cout<<"max is "<<max<<endl;
    return 0;
}
*/