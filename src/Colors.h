#ifndef COLORS_H
#define COLORS_H

class Colors
{
public:
	Colors()
	{
		red = 255;
		blue = 255;
		green = 255;
	}
	Colors(int r, int g, int b)
	{
		red = r;
		green = g;
		blue = b;
	}


	int red;
	int green;
	int blue;
};



#endif