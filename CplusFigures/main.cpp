#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "figures/cube.h"
#include "figures/triangle.h"
#include "figures/circle.h"
#include "stdlib.h"
#include <iostream>

double  h = 2;
double relX = 0;
double relY = 0;
double figureNum = 1;
double color[3] = {0, 1, 0};
Figure* savedObjs[10];
int length = -1;
Figure* figure = new Cube();

void Key_PLUS(void) {
	h = h + 0.4;
}
void Key_MINUS(void) {
	h = h - 0.4;
}
void Key_LEFT(void) {
	relX = relX - 0.4;
}
void Key_RIGHT(void) {
	relX = relX + 0.4;
}
void Key_UP(void) {
	relY = relY + 0.4;
}
void Key_DOWN(void) {
	relY = relY - 0.4;
}

void saveObj(void) {
    if (length < 10) {
        length++;
        savedObjs[length] = figure;
        figure = new Cube();
    } else {
        std::cout << "ERROR OCCURED. Too many figures!!!";
    }
}

void processNormalKeys(unsigned char key, int x, int y) {
    // TRANSLATE FIGURE
    if (key == 119) // w
		Key_UP();
    if (key == 115) // s
        Key_DOWN();
    if (key == 97) // a
		Key_LEFT();
    if (key == 100) // d
        Key_RIGHT();
    // SCALE FIGURE
    if (key == 61) // +
		Key_PLUS();
    if (key == 45) // -
        Key_MINUS();
    if (key == 114) { // r
        color[0] = 1;
        color[1] = 0;
        color[2] = 0;
    }
    if (key == 103) { // g
        color[0] = 0;
        color[1] = 1;
        color[2] = 0;
    }
    if (key == 98) { // b
        color[0] = 0;
        color[1] = 0;
        color[2] = 1;
    }
    // CHANGE FIGURE
    if (key == 49) { // 1
        delete figure; 
        figure = new Cube();
    }
    if (key == 50) { // 2
        delete figure;
        figure = new Triangle();
    }
    if (key == 51) { // 3
        delete figure;
        figure = new Circle();
    }
    // SAVE FIGURE
    if (key == 112) // p    paste figure and create next
        saveObj();
}

void resize(int width,int height) {
    glViewport(0,0,width,height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(-5,5, -5,5, 2,12);   
    gluLookAt( 0,0,5, 0,0,0, 0,1,0 );
    glMatrixMode( GL_MODELVIEW );
}   

void display(void) {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if (relX>0) {
        figure->setData(h, relX, relY, color);
    }
    figure->setData(h, relX, relY, color);
    figure->draw();
    Figure* obj;
    for (int i = 0; i <= length; i++) {
        obj = savedObjs[i];
        obj -> draw();
    }
    
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    float pos[4] = {3,3,3,1};
    float dir[3] = {-1,-1,-1};

    GLfloat mat_specular[] = {1,1,1,1};

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2.1. GLUT app.");

    // callbacks for main window
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
    glutIdleFunc(display);


	glutKeyboardFunc(processNormalKeys);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);

    glutMainLoop();
    return 0;
}