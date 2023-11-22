#ifndef TESTHANDLE_H
#define TESTHANDLE_H

int gpio_handle(const char*, const char*, const char*);
int pmic_handle(const char*, const char*, const char*);
int clk_handle(const char*, const char*, const char*);
int regulator_handle(const char*, const char*, const char*);
#endif