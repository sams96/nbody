#include "defs.h"

void* register_functions(void* data) {
	scm_c_define_gsubr("draw-square", 8, 0, 0, &draw_square);
	scm_c_define_gsubr("clear-screen", 0, 0, 0, &clear_screen);
	scm_c_define_gsubr("draw-circle", 7, 0, 0, &scm_draw_circle);
	return NULL;
}

SCM clear_screen() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	return SCM_UNSPECIFIED;
}

SCM draw_square(int x, int y, int w, int h, int r, int g, int b, int a) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	
	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer);

	return SCM_UNSPECIFIED;
}

SCM scm_draw_circle(int x, int y, int rad, int r, int g, int b, int a) {
	draw_circle(renderer, x, y, rad, r, g, b, a);
	return SCM_UNSPECIFIED;
}
