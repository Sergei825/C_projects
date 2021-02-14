#include <GL/gl.h>
#include <GL/glut.h>

#include "figure.h"

class Circle : public Figure {
    public:

        virtual void draw()
        {
            glPushMatrix();     // сохраняем текущие координаты
            glTranslated(relX, relY, 0);  // сдвигаемся в точку (2,0,0)
            glColor3d(color[0], color[1], color[2]);
            glutSolidSphere(h, 50, 50);  // рисуем
            glPopMatrix();     // возвращаемся к старым координатам
        }

};