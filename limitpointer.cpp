#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

bool active = true;

void playpause ( int sig )
{
	active = active ? false : true;
}

int main(int argc, char* argv[])
{
	signal(28, playpause); //killall -s 28 limitpointer will execute this function

	Display *dsp = XOpenDisplay( NULL );
	if( !dsp ){ return 1; }

	int screen_width;
	if (argc == 2)
		screen_width = atoi(argv[1]);
	else
		screen_width = DisplayWidth(dsp, DefaultScreen(dsp)) / 2;
	
	Window focusWin = RootWindow(dsp, DefaultScreen(dsp));

	XEvent event;

	while (true)
	{
		while (active)
		{
			XQueryPointer(dsp, focusWin, &event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
			if (event.xbutton.x >= screen_width)
				XTestFakeMotionEvent(dsp, DefaultScreen(dsp), screen_width - 1, event.xbutton.y, 0);

			usleep(500); //0.5 ms
		}
		sleep (1); // 1 s
	}

	XCloseDisplay( dsp );
	return 0;
}