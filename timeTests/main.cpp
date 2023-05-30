#include <iostream>
#include "TC.h"

#define RESEARCH 1

int main()
{


    srand(time(NULL));
    std::vector<uint8_t> vec;
    std::vector<uint8_t> vec2;
    std::vector<uint8_t> vec3;

    unsigned int sizeKb;
    std::cin >> sizeKb;

    for (int i = 0; i < sizeKb * 1024 ;i += 8)
    {
        vec.push_back((rand() % 255) + 1);
    }

    for (int i = 0; i < 1024; i += 8)
    {
        vec2.push_back((rand() % 255) + 1);
    }

    for (int i = 0; i < 10 * 1024; i += 8)
    {
        vec3.push_back((rand() % 255) + 1);
    }

    TC testVector(vec, 0);
    TC testVector2(vec2, 0);
    TC testVector3(vec3, 0);

    for (int i = 0; i < RESEARCH; i++)
    {
        TC::div(testVector,testVector3);
    }




    return 0;
}
