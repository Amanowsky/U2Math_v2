#include <iostream>
#include "TC.h"
#include <vector>
#include <cstdlib>
#include <chrono>
// zrobic do mnożenia jak w dzieleniu czyli przesunac liczbe zeby byla bez przecinka
// wyniki od razu wypisywac
int main()
{

    // do projektu generowanie

    srand(time(NULL));
    std::vector<uint8_t> vec;
    unsigned int sizeKb;
    std::cin >> sizeKb;

    for (int i = 0; i < sizeKb * 1024; i += 8)
    {
        vec.push_back((rand() % 255) + 1);
    }
    std::cout << vec.size() << std::endl;

    TC testVector(vec,0);

    /*for (uint8_t a : vec)
        std::cout << (int) a << std::endl;*/

    TC::add(testVector,testVector);
    auto start = std::chrono::steady_clock::now();
    for(int i=0;i<vec.size();i++){
        vec[i] = vec[i]+vec[i];
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;


    // Unit Tests
    TC_test::setAutoTest();

    vector<uint8_t> a = {0b00000101};
    vector<uint8_t> b = {0b00000100};
    vector<uint8_t> c = {0b00000001};

    TC TCa(a, 0);
    TC TCb(b, 0);
    TC TCc(c, 0);

    TC_test::manualTest(TCa, TCb, '-', TCc);

    return 0;
}
