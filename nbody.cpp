#include <iostream>
#include <vector>
#include <GL/freeglut.h> 
#include <chrono> 
#include <thread> 

#include "vec3.hpp"
#include "body.hpp"

const int HEIGHT = 1080;
const int WIDTH = 1920;
const int NB_BODY = 10;

std::vector<Body> body_list;

void idle()
{                      
    for(auto& body: body_list) {
        body.compute_force();
    }
    for(auto& body: body_list) {
        body.move(10e-3);
    }
    glutPostRedisplay();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    
}


void draw_update(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
    glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0xff,0xff,0xff); 	

    for(auto& body: body_list) {
        body.update_draw();
    }

	glEnd();

	glFlush();	
}


int main(int argc,char** argv)
{
    //srand(time(NULL));
    srand(0);
    for(int i=0; i<NB_BODY; i++) {
        float mass = 1000000000000000.0;
        float x = ((float)rand() / (float) RAND_MAX) * (float) WIDTH;
        float y = ((float)rand() / (float) RAND_MAX) * (float) HEIGHT;
        float z = 0.0;
        vec3 pos(x,y,z);
        vec3 vel(0.0,0.0,0.0);
        Body b(pos, vel, mass);
        b.set_bodies(&body_list);
        body_list.push_back(b);
    }

    float mass = 1000000000000000.0 * 10;
    vec3 pos(WIDTH/2,HEIGHT/2,0.0);
    vec3 vel(0.0,0.0,0.0);
    Body sun(pos, vel, mass);
    body_list.push_back(sun);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Nbody simulation");
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw_update);
	glutIdleFunc(idle);
	glutMainLoop();
	
	return 0;
}
