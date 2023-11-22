#include "testunit.h"
#include "testhandle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*test_unit_handle)(const char*, const char*, const char*);

struct handle_map{
    const char* category;
    test_unit_handle handle;
};

const struct handle_map test_unit_map[] = {
    {"gpio", gpio_handle},
    {NULL, NULL}
};


static test_unit_handle get_handle(const char* category){
    for (const handle_map* item = test_unit_map; item->category != NULL; item++) {
        if (strcmp(category, item->category) == 0){
            return item->handle;
        }
    }
    return NULL;
}

int init_test_unit(struct test_unit* tu, VirtioData* data)
{
    
    tu->data = data;
    tu->handle = get_handle(data->category);
    return 0;
}


int execute_test_unit(struct test_unit* tu)
{
    if (tu->handle == NULL) {
        return -1;
    }
    return tu->handle(tu->data->obj, tu->data->value, tu->data->func);
}