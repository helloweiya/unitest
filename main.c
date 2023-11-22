#include "testunit.h"

int main(int argc, char* argv[])
{
    struct test_unit tu;
    // recv from gvm

    initMyStruct(&tu, "gpio", "gpiochip0", "11","thigh");
    int ret = execute_test_unit(&tu);

    //response to gvm
    if (ret == 0) {

    }else{
        
    }


}