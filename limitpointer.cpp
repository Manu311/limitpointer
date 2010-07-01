#include <X11/Xlib.h>                            
#include <X11/extensions/XTest.h>
#include <iostream>

#define screen_width 800

int main ()
{
	Display *dsp = XOpenDisplay( NULL );
	if( !dsp ){ return 1; }
	Window focusWin = RootWindow(dsp, DefaultScreen(dsp));
	XSelectInput(dsp, focusWin, PointerMotionMask);

	
	int screenNumber = DefaultScreen(dsp);

	XEvent event;

	while (true)
	{
		XNextEvent(dsp, &event);
		XQueryPointer(dsp, focusWin, &event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
		if (event.xbutton.x >= screen_width)
			XTestFakeMotionEvent(dsp, DefaultScreen(dsp), screen_width, event.xbutton.y, 0);
	}

	XCloseDisplay( dsp );
	return 0;
}