#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include "common.h"

enum AnchorDir
{
	START,
	END
};

struct UIRect
{
	// Actual screen position and size (pixels)
	uint16_t x, y, width, height;

	struct UIRect *container;

	// Position and size relative to container (0-1)
	unsigned float h_rel_offset, v_rel_offset, width_rel, height_rel;

	// Pixel offset added to calculated relative position (pixels)
	int32_t h_abs_offset, v_abs_offset;

	// Absolute pixel margins
	uint16_t margin_left, margin_right, margin_top, margin_bottom;

	// Anchor from start (left/top) or end (right/bottom)
	enum AnchorDir h_anchor, v_anchor;
};

struct UIElement
{
	struct UIRect rect;

	char *fragment_shader;

	
};

GLFWwindow* get_window(uint16_t width, uint16_t height, char *title);

#endif