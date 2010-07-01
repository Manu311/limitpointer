#include <X11/Xlib.h>                            
#include <X11/extensions/XTest.h>
#include <iostream>

#define screen_width 800

int main ()
{
	Display *dsp = XOpenDisplay( NULL );
	if( !dsp ){ return 1; }
	XSelectInput(dsp, RootWindow(dsp, DefaultScreen(dsp)), PointerMotionMask);

	
	int screenNumber = DefaultScreen(dsp);

	XEvent event;

	while (true)
	{
		XNextEvent(dsp, &event);
		XQueryPointer(dsp, RootWindow(dsp, DefaultScreen(dsp)), &event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
		if (event.xbutton.x >= screen_width)
			XTestFakeMotionEvent(dsp, DefaultScreen(dsp), screen_width, event.xbutton.y, 0); 

		//printf("Mouse Coordinates: %d %d\n", event.xbutton.x, event.xbutton.y);
		//std::cout << "Mouse Coordinates: " << event.xbutton.x << " " << event.xbutton.y << " " << event.xbutton.window << std::endl;
	}

	XCloseDisplay( dsp );
	return 0;
}