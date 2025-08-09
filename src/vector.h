#ifndef __VECTOR_H__
#define __VECTOR_H__


typedef struct { float x, y, z; } vec3;

vec3 vec3_add(vec3* a, vec3* b);
vec3 vec3_sub(vec3* a, vec3* b);
vec3 vec3_scaled(vec3* v, float scale);
float vec3_magnitude(vec3* v);
void vec3_normalize(vec3* v);


#endif
