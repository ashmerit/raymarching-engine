#include <math.h>
#include "vector.h"

vec3 vec3_add(vec3* a, vec3* b) {
	return (vec3){
		a->x + b->x,
		a->y + b->y,
		a->z + b->z
	};
}

vec3 vec3_sub(vec3* a, vec3* b) {
	return (vec3){
		a->x - b->x,
		a->y - b->y,
		a->z - b->z
	};
}

vec3 vec3_scaled(vec3* v, float scale) {
	return (vec3){
		v->x * scale,
		v->y * scale,
		v->z * scale
	};
}

float vec3_magnitude(vec3* v) {
	return sqrtf(
		v->x * v->x +
		v->y * v->y +
		v->z * v->z
	);
}

void vec3_normalize(vec3* v) {
	float magnitude = vec3_magnitude(v);

	v->x = v->x / magnitude;
	v->y = v->y / magnitude;
	v->z = v->z / magnitude;
}
