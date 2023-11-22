#ifndef TESTUNIT_H
#define TESTUNIT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 50

struct test_unit {
    char category[STR_LEN];
    char obj[STR_LEN];
    char value[STR_LEN];
    char func[STR_LEN];
    test_unit_handle handle;
};



int init_test_unit(struct test_unit*, const char*, const char*,const char*,const char*);
int execute_test_unit(struct test_unit*);
#endif