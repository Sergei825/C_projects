#include "figure.h"

class Cube : public Figure {
    public:

        virtual void draw()
        {
            glPushMatrix();     // сохраняем текущие координаты
            glTranslated(relX, relY, 0);  // сдвигаемся в точку (2,0,0)
            glColor3d(color[0], color[1], color[2]);
            glutWireCube(h);  // рисуем
            glPopMatrix();     // возвращаемся к старым координатам
        }

};
