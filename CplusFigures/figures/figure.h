#ifndef FIGURE
#define FIGURE

#include <iostream>

class Figure {
    public:

        Figure() {
            relX = 0;
            relY = 0;
            h = 2;
            color[0] = 0;
            color[1] = 1;
            color[2] = 0;
        }

        virtual void draw()
        {
            std::cout << "ERROR OCCURED. No draw mathod";
        }

        void setData(double height, double x, double y, double colors[3]) {
            relX = x;
            relY = y;
            h = height;
            color[0] = colors[0];
            color[1] = colors[1];
            color[2] = colors[2];
        }

    protected:
        double relX;
        double relY;
        double h;
        double color[3];
};

#endif