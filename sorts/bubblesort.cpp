#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

int main()
{
    vector<int> vec = {1, 5, 10, 99, 3493, 34302, 1, -1, 35, 15};

    bubble_sort_withiterator(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}