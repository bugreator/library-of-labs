#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>
#include <iostream>


double f(double x,double y){
    return 100-x*x-y;
}

void drawpoint(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.1,0.4,0.2);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (-120.0, 120.0, 0.0, 150.0);

    double xk = 0,yk = 100,pk = 0;
    glVertex2d(xk,yk);
    glBegin(GL_POINTS);
    for(int i = 0;i < 100;i++){
        
        pk = f(xk+0.5,yk-1);
        if(pk >= 0){
            xk+=1;
            yk-=1;
        }
        else
            yk-=1;
        glVertex2d(xk,yk);
        glVertex2d(-xk,yk);
        printf("%lf,%lf\n",xk,yk);
    }
    glEnd();
    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE |GLUT_RGB |GLUT_DEPTH);
    glutCreateWindow("paowuxian");
    glutInitWindowSize (240,150);
    glutInitWindowPosition (400,100);

    glutDisplayFunc(drawpoint);
    glutMainLoop();

}
