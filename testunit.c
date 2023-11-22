#include "testunit.h"
#include "gpio.h"

typedef int (*test_unit_handle)(const char*, const char*, const char*);

struct handle_map{
    const char* category,
    test_unit_handle handle;
}

const handle_map map[] = {
    {"gpio", gpio_handle},
    {NULL, NULL}
};


static test_unit_handle get_handle(const char* category){
    for (const handle_map* item = map; item->category != NULL; item++) {
        if (strcmp(category, item->name) == 0){
            return item->handle;
        }
    }
    return NULL;
}

int init_test_unit(struct test_unit* tu, const char* category, const char* obj, const char* value, const char* func)
{
    tu->handle = get_handle(category);
    strncpy(tu->category, category, sizeof(category)-1);
    strncpy(tu->obj, obj, sizeof(obj)-1);
    strncpy(tu->value, cfunc, sizeof(value)-1);
    strncpy(tu->func, func, sizeof(func)-1);
    return 0;
}



int execute_test_unit(struct test_unit* tu)
{
    return tu->handle(tu->obj, tu->value, tu->func);
}