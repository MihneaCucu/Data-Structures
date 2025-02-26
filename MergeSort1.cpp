#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge (vector<double>& v, int a, int b, int c)
{   int i,j,k;
    int n1 = b - a + 1;
    int n2 = c - b;
    
    vector<double> v1(n1), v2(n2);
    
    for (i = 0; i < n1; i++)
        v1[i] = v[a + i];
    
    for (j = 0; j < n2; j++)
        v2[j] = v[j + b + 1];
    
    i = j = 0;
    k = a;
    
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            v[k] = v1[i];
            i++;
        }
        else
        {
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        v[k] = v1[i];
        i++;
        k++;
    }
    
    while(j < n2)
    {
        v[k] = v2[j];
        j++;
        k++;
    }
}

void merge_sort(vector<double>& v, int st, int dr)
{
    if (st < dr)
    {
        int m = st + (dr - st) / 2;
        merge_sort(v, st, m);
        merge_sort(v, m + 1, dr);
        merge(v, st, m, dr);
    }
    
}

int main()
{   ifstream fin("test2.in");
    int n=0;
    vector<double> v;
    double x;
    
    while(fin>>x)
    {
        v.push_back(x);
        n++;
    }
    
    merge_sort(v, 0, n-1);
    
    /*double suma = 0;
    int contor = 0;
    int iterations = 100000000;
    
    while(iterations)
    {   contor++;
        auto start = high_resolution_clock::now();
    
        merge_sort(v, 0, n-1);
    
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        suma += duration.count();
        cout << suma/contor << endl;
        iterations--;
    }*/
    
    for (int i = 0; i < n; i++)
        cout << v[i] <<' ';
    
    
    return 0;
}


