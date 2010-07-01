#include <X11/Xlib.h>                            
#include <X11/extensions/XTest.h>

int main ()
{
	Display *dsp = XOpenDisplay( NULL );
	if( !dsp ){ return 1; }

	int screen_width = DisplayWidth(dsp, DefaultScreen(dsp)) / 2;
	
	Window focusWin = RootWindow(dsp, DefaultScreen(dsp));

	XEvent event;

	//XSelectInput(dsp, focusWin, PointerMotionMask);

	while (true)
	{
		//XNextEvent(dsp, &event);
		XQueryPointer(dsp, focusWin, &event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
		if (event.xbutton.x >= screen_width)
			XTestFakeMotionEvent(dsp, DefaultScreen(dsp), screen_width - 1, event.xbutton.y, 0);
		usleep(500); //0.5 ms
	}

	XCloseDisplay( dsp );
	return 0;
}