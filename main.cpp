//
// main.cpp
// 2023-07-31
// Ivan Konishchev
//

#include <iostream>
#include "ArraySumm.h"
#include <chrono>

int main(int argc, const char *argv[])
{
    unsigned long long int sizeArray = 100000000;
    int threadCount = 4;

    ArraySumm arrSumm(sizeArray, threadCount);
 
    auto thread_start = std::chrono::system_clock::now();
    std::cout << "Result with multi thread: " << (arrSumm.summUsingMultiThread()) << "\n";
    auto thread_stop = std::chrono::system_clock::now();
    long time = std::chrono::duration_cast<std::chrono::milliseconds>(thread_stop - thread_start).count();
    std::cout << "Summ using thread count: " << threadCount << " it lasted ms: " << time << "\n\n";


    thread_start = std::chrono::system_clock::now();
    std::cout << "Result on one thread: " << (arrSumm.summWithoutMultiThread()) << "\n"; 
    thread_stop = std::chrono::system_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(thread_stop - thread_start).count();
    std::cout << "Summ using one thread " << " it lasted ms: " << time << "\n\n";
    return 0;
}