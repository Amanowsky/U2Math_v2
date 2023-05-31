#include <iostream>
#include "TC.h"

int main()
{
    TC_test::setAutoTest();

    vector<uint8_t> a = {0b00000101};
    vector<uint8_t> b = {0b00000100};
    vector<uint8_t> c = {0b00001001};

    TC TCa(a, -1);
    TC TCb(b, -1);
    TC TCc(c, -1);


    TC_test::manualTest(TCa,TCb,'+',TCc);



    return 0;
}
