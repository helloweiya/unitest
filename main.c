#include "testunit.h"

int main(int argc, char* argv[])
{
    struct test_unit tu;
    
    // recv from gvm
    struct VirtioData data;

    initMyStruct(&tu, &data);
    int ret = execute_test_unit(&tu);

    //response to gvm
    if (ret == 0) {

    }else{

    }


}