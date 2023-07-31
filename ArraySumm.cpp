//
// ArraySumm.cpp
// 2023-07-31
// Ivan Konishchev
//

#include "ArraySumm.h"

ArraySumm::ArraySumm(unsigned long long int size, int threadCount) : _size(size), _threadCount(threadCount)

{
    std::random_device rd;                       // non-deterministic generator
    std::mt19937 gen(rd());                      // to seed mersenne twister.
    std::uniform_int_distribution<> dist(1, 20); // distribute results between 1 and 6 inclusive.

    for (int i = 0; i < _size; i++)
    {
        _array.push_back(dist(gen));
    }
}

void ArraySumm::summPart(int begin, int end)
{
    int sum{0};
    for (auto it = _array.begin() + begin; it != _array.begin() + end; it++)
    {
        sum += (*it);
    }
    _result += sum;
}

int ArraySumm::summUsingMultiThread()
{
    size_t part = _threadCount;

    size_t length = _array.size() / part;
    size_t remain = _array.size() % part;

    size_t begin = 0;
    size_t end = 0;

    for (size_t i = 0; i < std::min(part, _array.size()); ++i)
    {
        end += (remain > 0) ? (length + !!(remain--)) : length;

        std::thread thread(&ArraySumm::summPart, this, begin, end);
        _threads.push_back(std::move(thread));
        begin = end;
    }

    for (auto it = _threads.begin(); it != _threads.end(); it++)
    {
        if ((*it).joinable())
        {
            (*it).join();
        }
    }
    return _result;
}

int ArraySumm::summWithoutMultiThread()
{
    unsigned long long int result = 0;
    for (auto it = _array.begin(); it != _array.end(); it++)
    {
        result += (*it);
    }
    return result;
}