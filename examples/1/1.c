#include "engine.h"
#include "vector.h"
#include "object.h"


static float sphere(vec3 point) {
	return vec3_magnitude(&point) - 1.0f;
}

static float plane(vec3 point) {
	return point.y;
}

int main() {
	struct object sphere_obj = {
		.distance_function = sphere,
		.r = 255,
		.g = 0,
		.b = 0
	};

	struct object plane_obj = {
		.distance_function = plane,
		.r = 255,
		.g = 255,
		.b = 255
	};

	struct render_info rinfo = {
		.output_name = "examples/1/1.ppm",
		.width = 1200,
		.height = 1200,
		.camera_position = { .x = 0, .y = 1.0f, .z = -5.0f },

		.objects = (struct object[]){ sphere_obj, plane_obj },
		.num_objects = 2,

		.background_color = { .r = 0, .g = 0, .b = 0 }
	};

	generate_render(&rinfo);

	return 0;
}
