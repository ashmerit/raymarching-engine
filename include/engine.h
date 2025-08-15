#ifndef __ENGINE_H__
#define __ENGINE_H__


#include <stddef.h>

#include "vector.h"
#include "object.h"

struct render_info {
	const char* output_name;

	size_t width, height;

	vec3 camera_position;

	struct object* objects;
	size_t num_objects;

	struct {
		unsigned char r, g, b;
	} background_color;
};

void generate_render(const struct render_info*);


#endif
