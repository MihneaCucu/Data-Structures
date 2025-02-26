#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
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
    double max_val = 0.0;
    double min_val = 0.0;
    vector<vector<double>> a(n);
    if (!v.empty())
    {
        max_val = *max_element(v.begin(), v.end());
        min_val = *min_element(v.begin(), v.end());
    }

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
{
ifstream fin("Input Test");
   if (!fin) 
   {
       cerr << "Nu s-a putut deschide fisierul";
       return 1;
   }

   int num_tests;
   fin >> num_tests;

   for (int test = 0; test < num_tests; ++test) 
   {
       int num_elements;
       double max_value;

       fin >> num_elements >> max_value;
       vector<double> v;
       double x;

       
       for (int i = 0; i < num_elements; ++i) 
       {
           fin >> x;
           v.push_back(x);
       }

       auto start = high_resolution_clock::now();

       bucket_sort(v);
       auto stop = high_resolution_clock::now();
       auto duration = duration_cast<milliseconds>(stop - start);

       
       for (int i = 0; i < v.size(); i++)
           cout << v[i] << ' ';
       cout << endl;

       cout << "Timp de executie: " << duration.count() << " milisecunde" << endl;
   }

   return 0;
}

