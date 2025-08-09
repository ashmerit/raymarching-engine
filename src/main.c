#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "vector.h"


const unsigned int IMAGE_WIDTH = 800;
const unsigned int IMAGE_HEIGHT = 800;

int main(void) {
	FILE* fp = fopen("raymarch.ppm", "wb");
	fprintf(fp, "P6\n");
	fprintf(fp, "%d %d\n", IMAGE_WIDTH, IMAGE_HEIGHT);
	fprintf(fp, "255\n");

	for (unsigned int y = 0; y < IMAGE_HEIGHT; ++y) {
		for (unsigned int x = 0; x < IMAGE_WIDTH; ++x) {
			unsigned char final_color[3] = {};
			unsigned char colors[2][2][3] = {
				{ { 135, 200, 235 }, { 135, 200, 235 } },
				{ { 135, 200, 235 }, { 135, 200, 235 } }
			};

			for (unsigned int sub_x = 0; sub_x < 2; ++sub_x) {
				for (unsigned int sub_y = 0; sub_y < 2; ++sub_y) {
					vec3 ray_position = (vec3){ 0.0f, 0.0f, -4.0f };
					vec3 ray_direction = (vec3){
						(((float)(x) + ((float)(sub_x) / 2)) / (float)IMAGE_WIDTH - 0.5f) * 2.0f,
						(((float)(y) + ((float)(sub_y) / 2)) / (float)IMAGE_HEIGHT - 0.5f) * -2.0f,
						1.0f
					};
					vec3_normalize(&ray_direction);

					for (int iteration = 0; iteration < 200; ++iteration) {
						struct {
							float sphere;
							float floor;
						} distances;
						distances.sphere = vec3_magnitude(&ray_position) - 1.0f;
						distances.floor = ray_position.y + 2.0f;

						if (distances.sphere < 0.000001f) {
							colors[sub_x][sub_y][0] = 255;
							colors[sub_x][sub_y][1] = 0;
							colors[sub_x][sub_y][2] = 0;
							break;
						} else if (distances.floor < 0.000001f) {
							if (sinf(ray_position.x) * sinf(ray_position.z) > 0) {
								colors[sub_x][sub_y][0] = 255;
								colors[sub_x][sub_y][1] = 255;
								colors[sub_x][sub_y][2] = 255;
							} else {
								colors[sub_x][sub_y][0] = 0;
								colors[sub_x][sub_y][1] = 0;
								colors[sub_x][sub_y][2] = 0;
							}
							break;
						} else {
							vec3 scaled_direction = vec3_scaled(&ray_direction, fminf(distances.sphere, distances.floor));
							ray_position = vec3_add(&ray_position, &scaled_direction);
						}
					}
				}
			}

			final_color[0] = (colors[0][0][0] + colors[0][1][0] + colors[1][0][0] + colors[1][1][0]) / 4;
			final_color[1] = (colors[0][0][1] + colors[0][1][1] + colors[1][0][1] + colors[1][1][1]) / 4;
			final_color[2] = (colors[0][0][2] + colors[0][1][2] + colors[1][0][2] + colors[1][1][2]) / 4;
			fwrite(final_color, 1, 3, fp);
		}
	}

	fclose(fp);
	return EXIT_SUCCESS;
}
