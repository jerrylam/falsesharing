//
//  main.cpp
//  falsesharing
//
//  Created by Jerry Lam on 2016-07-15.
//  Copyright © 2016 Jerry Lam. All rights reserved.
//

#include <iostream>
#include <thread>
#include <vector>
#include <ctime>

using namespace std;

const long WORKLOAD = 2000000000;
const int FALSE_SHARING_SIZE = 1;
const int NO_SHARING_SIZE = 16;

void work(int* ptr, int parallelism)
{
    auto n = (WORKLOAD / parallelism);
    for (int i = 0; i < n; ++i)
    {
        (*ptr)++;
    }
}

void benchmark(int cache[], int parallelism, int padding) {
    vector<thread> threads;
    for (int i = 0; i < parallelism; ++i)
    {
        threads.push_back(thread(work, &(cache[i * padding]), parallelism));
    }
    for (auto& th : threads)
    {
        th.join();
    }
}

int main(int argc, const char * argv[]) {
    
    unsigned cores = thread::hardware_concurrency();
    int pads[2] = {NO_SHARING_SIZE, FALSE_SHARING_SIZE};
    
    for(const auto& pad: pads) {
        for(int i =1; i <=cores; ++i) {
            alignas(64) unique_ptr<int[]> arr(new int[i * pad]);
            auto start = std::chrono::high_resolution_clock::now();
            benchmark(arr.get(), i, pad);
            auto end = chrono::high_resolution_clock::now();
            auto nano = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            cout << "=============================" << endl;
            cout << "Parallelism: " << i << ", pad size:" << pad << endl;
            cout << "Duration (milliseconds): " << nano << endl;
        }
    }
    return 0;
}