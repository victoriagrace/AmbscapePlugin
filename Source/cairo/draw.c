#include <stdio.h>
#include <cairo/cairo.h>
#include <math.h>

#define NUMFRAMES 64

#define WIDTH 195
#define HEIGHT 195

void draw(int framenumber) 
{
	char filename[255];
	cairo_surface_t *surface;
	cairo_t *cr;
	cairo_pattern_t *linpat, *radpat;

	surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT); 
	cr = cairo_create (surface);
	/* Examples are in 1.0 x 1.0 coordinate space */
	cairo_scale (cr, WIDTH, HEIGHT);

	/* Drawing code goes here */
	linpat = cairo_pattern_create_linear (0, 0, 1, 1);
	cairo_pattern_add_color_stop_rgb (linpat, 0, 0, 0.3, 0.8);
	cairo_pattern_add_color_stop_rgb (linpat, 1, 0, 0.8, 0.3);

	radpat = cairo_pattern_create_radial (0.5, 0.5, 0.05, 0.5, 0.5, 0.95);
	cairo_pattern_add_color_stop_rgba (radpat, 0, 0, 0, 0, 1);
	cairo_pattern_add_color_stop_rgba (radpat, 0.5, 0, 0, 0, 0);

	//cairo_set_source (cr, linpat);

	int framenumber_rev  = (NUMFRAMES - 1) - framenumber;
	float weight = (float)(framenumber_rev) / NUMFRAMES;

	float color2[4] = {
		0,
		(119.0/255.0), 
		1, 
		1.0
	};

	float color1[4] = {
		0.0,
		(196.0 / 255.0f),
		(102.0f / 255.0f),
		0.0
	};
	cairo_set_source_rgba(cr, 
		weight * color1[0] + (1 - weight) * color2[0],
		weight * color1[1] + (1 - weight) * color2[1],
		weight * color1[2] + (1 - weight) * color2[2],
		weight * color1[3] + (1 - weight) * color2[3]
	);
	//cairo_paint(cr);
	cairo_pattern_destroy (linpat);

	cairo_mask (cr, radpat);
	cairo_pattern_destroy (radpat);

	/* Write output and clean up */
	sprintf(filename, "../res/ball_%d.png", framenumber);
	cairo_surface_write_to_png (surface, filename);
	cairo_destroy (cr);
	cairo_surface_destroy (surface);

}

void draw_flutter(int framenumber) 
{
	char filename[255];
	cairo_surface_t *surface;
	cairo_t *cr;
	cairo_pattern_t *linpat, *radpat;

	int framenumber_rev  = (NUMFRAMES - 1) - framenumber;
	float weight = (float)(framenumber_rev) / NUMFRAMES;

	float color2[4] = {
		0,
		(119.0/255.0), 
		1, 
		1.0
	};

	float color1[4] = {
		1.0,
		(31.0f / 255.0f),
		(178.0f / 255.0f),
		1.0
	};

	float pos = ((2 * M_PI) / NUMFRAMES) * (framenumber * 2);
	float scale = (sin(pos) + 1) * 0.5;
	surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT); 
	cr = cairo_create (surface);
	/* Examples are in 1.0 x 1.0 coordinate space */
	cairo_scale (cr, WIDTH, HEIGHT);

	/* Drawing code goes here */
	linpat = cairo_pattern_create_linear (0, 0, 1, 1);
	cairo_pattern_add_color_stop_rgb (linpat, 0, 0, 0.3, 0.8);
	cairo_pattern_add_color_stop_rgb (linpat, 1, 0, 0.8, 0.3);

	radpat = cairo_pattern_create_radial (0.5, 0.5, 0.05, 0.5, 0.5, 0.6 + 0.35 * scale);
	cairo_pattern_add_color_stop_rgba (radpat, 0, 0, 0, 0, 1);
	cairo_pattern_add_color_stop_rgba (radpat, 0.5, 0, 0, 0, 0);

	cairo_set_source_rgba(cr, 
		weight * color1[0] + (1 - weight) * color2[0],
		weight * color1[1] + (1 - weight) * color2[1],
		weight * color1[2] + (1 - weight) * color2[2],
		weight * color1[3] + (1 - weight) * color2[3]
	);
		
	//cairo_paint(cr);
	cairo_pattern_destroy (linpat);

	cairo_mask (cr, radpat);
	cairo_pattern_destroy (radpat);

	/* Write output and clean up */
	sprintf(filename, "../res/ball_pull_%d.png", framenumber);
	cairo_surface_write_to_png (surface, filename);
	cairo_destroy (cr);
	cairo_surface_destroy (surface);

}

int main (int argc, char *argv[])
{
	int i;
	for(i = 0; i < NUMFRAMES; i++) {
		draw_flutter(i);
		draw(i);
	}
	return 0;
}
