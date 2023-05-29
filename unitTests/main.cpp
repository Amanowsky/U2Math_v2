#include <iostream>
#include "TC.h"

int main()
{

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
