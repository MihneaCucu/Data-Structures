#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion_sort(vector<double>& bucket)
{
    for (int i = 1; i < bucket.size(); ++i)
    {
        double key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucket_sort(vector<double>& v)
{   int n = v.size();
    vector<vector<double>> a(n);
    
    double max_val = *max_element(v.begin(), v.end());
    double min_val = *min_element(v.begin(), v.end());
    
    double range = max_val - min_val;
    
    for (int i = 0; i < n; ++i) 
    {
        a[i].reserve(n);
    }
    
    for (int i = 0; i < n; i++)
    {
        int k = (v[i] - min_val) / (range / (n - 1));
        a[k].push_back(v[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        insertion_sort(a[i]);
    }
             
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            v[index++] = a[i][j];
        }
    }
}

int main()
{   ifstream fin("test2.in");
    vector<double> v;
    double x;
    
    while(fin >> x)
    {
        v.push_back(x);
    }
        
    bucket_sort(v);
    
    for (int i = 0; i < v.size(); i++)
        cout << v[i] <<' ';
     
    return 0;
}

