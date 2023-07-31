//
// ArraySumm.h
// 2023-07-31
// Ivan Konishchev
//

#pragma once
#include <vector>
#include <random>
#include <thread>
#include <iostream>

class ArraySumm
{

    unsigned long long int _size;
    int _threadCount;
    std::vector<int> _array;
    std::vector<std::thread> _threads;
    std::vector<std::vector<int>> _partArray;
    unsigned long long int _result{0};
    void summPart(int begin, int end);

public:
    ArraySumm(unsigned long long int size, int threadCount);
    int summUsingMultiThread();
    int summWithoutMultiThread();
};