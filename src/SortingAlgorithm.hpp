#pragma once

#include <iostream>
#include <vector>
#include <concepts>
#include <utility> // for std::swap

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

// BubbleSort
template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for (unsigned int i = 0; i < n - 1; i++)
    {
        for (unsigned int j = i + 1 ; j < n ; j++)
        {
            if (v[j] < v[i])
            {
                std::swap(v[j], v[i]);
            }
        }
    }
}

// HeapSort
template<Sortable T>
void Heapify(std::vector<T>& v, unsigned int n, unsigned int i)
{
    unsigned int largest = i;
    unsigned int l = 2 * i + 1;
    unsigned int r = 2 * i + 2;

    if (l < n && v[largest] < v[l])
        largest = l;
    if (r < n && v[largest] < v[r])
        largest = r;
    if (largest != i)
    {
        std::swap(v[i], v[largest]);
        Heapify(v, n, largest);
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        Heapify(v, n, i);

    for (int i = n - 1; i > 0; --i)
    {
        std::swap(v[0], v[i]);
        Heapify(v, i, 0);
    }
}

}

