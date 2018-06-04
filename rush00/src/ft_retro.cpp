#include "ft_retro.hpp"
#include <sys/time.h>
#include <unistd.h>

Screen	screen;

int		main(void)
{
	struct timeval	start, end, prev;
	size_t			max, diff;

	//	time between each draw
	if (!FPS)
		return (1);
	max = 1000000 / FPS;
	while (true)
	{
		gettimeofday(&start, NULL);
		//	draw fps
		diff = (start.tv_sec - prev.tv_sec) * 1000000 + (start.tv_usec - prev.tv_usec);
		if (diff)
			log << 1000000 / diff << " fps" << std::endl;
		else
			log << "unlimited fps (>=^w^=<)" << std::endl;
		prev = start;
		if (!screen.getDamageScreen())
		{
			//	manage input events
			manage_inputs(&screen);
			//	manage elements
			if (!screen.getGameOver())
				manage_elements(&screen);
			//	draw elements
			draw_elements(&screen);
		}
		else
		{
			screen.setDamageScreen(screen.getDamageScreen() - 1);
			draw_damage_screen(screen.getGame());
		}
		//	sleep if needed
		gettimeofday(&end, NULL);
		diff = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
		if (diff < max)
			usleep(max - diff);
	}
	return (0);
}
