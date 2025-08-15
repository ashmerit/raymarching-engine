#include "engine.h"

#include <stddef.h>
#include <stdio.h>

#include "vector.h"

#define EPSILON 0.0000001f


void generate_render(const struct render_info* rinfo) {
	FILE* fp = fopen(rinfo->output_name, "wb");
	fprintf(fp, "P6\n");
	fprintf(fp, "%zu %zu\n", rinfo->width, rinfo->height);
	fprintf(fp, "255\n");

	for (size_t y = 0; y < rinfo->height; ++y) {
		for (size_t x = 0; x < rinfo->width; ++x) {
			unsigned char final_color[3] = {};
			final_color[0] = rinfo->background_color.r;
			final_color[1] = rinfo->background_color.g;
			final_color[2] = rinfo->background_color.b;

			vec3 ray_position = rinfo->camera_position;
			vec3 ray_direction = (vec3){
				2.0f * ((float)x / rinfo->width - 0.5f),
				2.0f * ((float)y / rinfo->height - 0.5f) * -1.0f,
				1.0f
			};
			vec3_normalize(&ray_direction);

			bool still_marching = true;
			for (int iteration = 0; (iteration < 200) && still_marching; ++iteration) {
				float min_distance = 100.0f;
				for (size_t n = 0; n < rinfo->num_objects; ++n) {
					float distance_to_obj_n = rinfo->objects[n].distance_function(ray_position);

					if (min_distance > distance_to_obj_n) {
						min_distance = distance_to_obj_n;
					}

					if (distance_to_obj_n < EPSILON) {
						final_color[0] = rinfo->objects[n].r;
						final_color[1] = rinfo->objects[n].g;
						final_color[2] = rinfo->objects[n].b;
						still_marching = false;
						break;
					}
				}

				vec3 scaled_direction = vec3_scaled(&ray_direction, min_distance);
				ray_position = vec3_add(&ray_position, &scaled_direction);
			}

			fwrite(final_color, 1, 3, fp);
		}
	}

	fclose(fp);
}
