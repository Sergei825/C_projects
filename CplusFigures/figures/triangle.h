#include <GL/gl.h>

#include "figure.h"

class Triangle : public Figure {
    public:

        virtual void draw()
        {
            glBegin(GL_TRIANGLES); //Begin triangle coordinates
	        //Triangle
            glColor3d(color[0], color[1], color[2]);
	        glVertex3f(-0.5f * h / 2 + relX, 0.5f * h / 2 + relY, -5.0f);
	        glVertex3f(-1.0f * h / 2 + relX, 1.5f * h / 2 + relY, -5.0f);
	        glVertex3f(-1.5f * h / 2 + relX, 0.5f * h / 2 + relY, -5.0f);
	        glEnd(); //End triangle coordinates
        }

};
