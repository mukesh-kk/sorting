#include <vector>

#ifndef SORT_H
#define SORT_H
using namespace std;
vector<int> bubble_sort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}
void bubble_sort_byref(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    // return arr;
}
void bubble_sort_bypointer(vector<int> *arr)
{
    for (int i = 0; i < arr->size(); i++)
    {

        for (int j = 0; j < arr->size() - i - 1; j++)
        {
            if ((*arr)[j] > (*arr)[j + 1])
            {
                swap((*arr)[j], (*arr)[j + 1]);
            }
        }
    }
}
void bubble_sort_withiterator(vector<int>::iterator begin, vector<int>::iterator end)
{
    for (auto i = begin; i != end; ++i)
    {
        for (auto j = begin; j != end - 1; ++j)
        {
            if (*j > *(j + 1))
            {
                swap(*j, *(j + 1));
            }
        }
    }
}
#endif