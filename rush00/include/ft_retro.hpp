#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# include "Screen.hpp"
# include "Log.hpp"

# define FPS	60

int		rand(int min, int max);

void	manage_inputs(Screen *screen);
void	manage_elements(Screen *screen);
void	draw_elements(Screen *screen);
void	collision_test(Screen *screen, Element *element);
void	draw_damage_screen(Window *window);

#endif
