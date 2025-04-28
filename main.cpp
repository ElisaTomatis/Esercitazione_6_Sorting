#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cstdlib> // per rand, srand

#include "SortingAlgorithm.hpp"

using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    ostringstream toString;
    toString << "[ ";
    for (const T& e : v)
        toString << e << " ";
    toString << "]";
    return toString.str();
}

int main(int argc, char *argv[])
{
    cout << "argc: " << argc << endl;
    for(int a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;

    size_t m = 1000;
    if(argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "use value: "  << m << endl;
    }
    else
        cerr << "use default value: "  << m << endl;

    vector<int> v1(m);
    iota(v1.begin(), v1.end(), -4); // crescente

    srand(2);
    vector<double> v2(m);
    for(size_t i = 0; i < m; i++)
        v2[i] = rand() / ((double)RAND_MAX); // random [0,1]

    vector<int> v3(m, 0); // parzialmente ordinato
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;
    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());

    unsigned int num_experiment = 100;

    // BUBBLE SORT
    double time_bubble_v1 = 0;
	double time_bubble_v2 = 0; 
	double time_bubble_v3 = 0;
	
    for (unsigned int t = 0; t < num_experiment; ++t)
    {
        auto v = v1;
        auto start = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v1 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v1 /= num_experiment;

    for (unsigned int t = 0; t < num_experiment; ++t)
    {
        auto v = v2;
        auto start = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v2 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v2 /= num_experiment;

    for (unsigned int t = 0; t < num_experiment; ++t)
    {
        auto v = v3;
        auto start = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v3 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v3 /= num_experiment;

    // HEAP SORT
    double time_heap_v1 = 0;
	double time_heap_v2 = 0;
	double time_heap_v3 = 0;
	
    for (unsigned int t = 0; t < num_experiment; ++t)
    {
        auto v = v1;
        auto start = chrono::steady_clock::now();
        SortLibrary::HeapSort(v);
        auto end = chrono::steady_clock::now();
        time_heap_v1 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v1 /= num_experiment;

    for (unsigned int t = 0; t < num_experiment; ++t)
    {
        auto v = v2;
        auto start = chrono::steady_clock::now();
        SortLibrary::HeapSort(v);
        auto end = chrono::steady_clock::now();
        time_heap_v2 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v2 /= num_experiment;

    for (unsigned int t = 0; t < num_experiment; ++t)
    {
        auto v = v3;
        auto start = chrono::steady_clock::now();
        SortLibrary::HeapSort(v);
        auto end = chrono::steady_clock::now();
        time_heap_v3 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v3 /= num_experiment;

    // RISULTATI
    cout << "\n--- RISULTATI ---" << endl;
    cout << "BubbleSort v1 (ordinato):          " << time_bubble_v1 << " µs" << endl;
    cout << "BubbleSort v2 (random double):     " << time_bubble_v2 << " µs" << endl;
    cout << "BubbleSort v3 (mezzo ordinato):    " << time_bubble_v3 << " µs" << endl;

    cout << "HeapSort v1 (ordinato):            " << time_heap_v1 << " µs" << endl;
    cout << "HeapSort v2 (random double):       " << time_heap_v2 << " µs" << endl;
    cout << "HeapSort v3 (mezzo ordinato):      " << time_heap_v3 << " µs" << endl;

    return 0;
}
