#ifndef TESTUNIT_H
#define TESTUNIT_H


#define STR_LEN 50

#pragma pack(1)
struct VirtioData {
    char category[STR_LEN];
    char obj[STR_LEN];
    char value[STR_LEN];
    char func[STR_LEN];
};
#pragma pack()

struct test_unit {
    test_unit_handle handle;
    VirtioData* data;
};

int init_test_unit(struct test_unit*,VirtioData* );
int execute_test_unit(struct test_unit*);
#endif