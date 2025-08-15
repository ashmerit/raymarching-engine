#ifndef __OBJECT_H__
#define __OBJECT_H__


#include "vector.h"

struct object {
    float (*distance_function)(vec3);

    unsigned char r, g, b;
};


#endif
