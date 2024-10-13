#ifndef SCAN_H
#define SCAN_H

typedef struct scan{
    int (*integer)(char*);
    char* (*string)(char*);
} scan;

extern scan Scan;

#endif // SCAN_H