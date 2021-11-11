#ifndef COLORS_H
#define COLORS_H

class Color
{
public:
	Color()
	{
		red = 255;
		blue = 255;
		green = 255;
	}
	Color(unsigned char r, unsigned char g, unsigned char b)
	{
		red = r;
		green = g;
		blue = b;
	}


	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

//namespace Colors
//{
//	//Color MakeRGB(unsigned char r, unsigned char g, unsigned char b)
//	//{
//	//	return (r << 16 | (g << 8) | b);
//	//}
//
//	Color White = Color(255u, 255u, 255u);
//	Color Black = Color(0u, 0u, 0u);
//	Color Gray = Color(100u, 100u, 100u);
//	Color Green = Color(0u, 255u, 0u);
//	Color Yellow = Color(255u, 255u, 0u);
//
//}

#endif