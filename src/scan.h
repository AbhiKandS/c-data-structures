#ifndef SCAN_H
#define SCAN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct scan{
    int (*integer)(char*);
    char* (*string)(char*);
} scan;

extern scan Scan;

#endif // SCAN_H