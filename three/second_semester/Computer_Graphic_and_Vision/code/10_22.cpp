#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>

GLint winWidth = 600, winHeight = 600; // Initial display-window size.
GLfloat x_0 = 100.0, y_0 = 50.0, z_0 = 50.0; // Viewing-coordinate origin.
GLfloat xref = 50.0, yref = 50.0, zref = 0.0; // Look-at point.
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.
/* Set coordinate limits for the clipping window: */
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;
/* Set positions for near and far clipping planes: */
GLfloat dnear = 25.0, dfar = 125.0;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    
    gluLookAt(x_0, y_0, z_0, xref, yref, zref, Vx, -Vy, Vz);
    //    gluLookAt(x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
    glMatrixMode(GL_PROJECTION);
    glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}
void displayFcn(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    /* Set parameters for a square fill area. */
    glColor3f(0.0, 1.0, 0.0); // Set fill color to green.
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE); // Wire-frame back face.
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(0.0, 100.0, 0.0);
    glEnd();
    glFlush();
}
void reshapeFcn(GLint newWidth, GLint newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
    winWidth = newWidth;
    winHeight = newHeight;
}

void keyboard(unsigned char key, int x, int y)
{ // 按下Q、q或ESC键时，终止程序
    if(key == 'w'){
        xwMin+=10;
        if(xwMin > xwMax)
            xwMin = xwMax;
//        printf("%f\n",xwMax);
//        printf("%f\n",xwMin);
    }
    else
        if(key == 's'){
            xwMin-=10;
//            printf("%f\n",xwMax);
//            printf("%f\n",xwMin);
        }
    else
        if(key == 'e'){
            xwMax+=10;
//            printf("%f\n",xwMax);
//            printf("%f\n",xwMin);
        }
        else
            if(key == 'd'){
                xwMax-=10;
                if(xwMin > xwMax)
                    xwMax = xwMin;
//                printf("%f\n",xwMax);
//                printf("%f\n",xwMin);
            }
            else
                if(key == 'r'){
                    ywMin+=10;
                    if(ywMin > ywMax)
                        ywMin = ywMax;
//                    printf("%f\n",ywMax);
//                    printf("%f\n",ywMin);
                }
                else
                    if(key == 'f'){
                        ywMin-=10;
//                        printf("%f\n",ywMax);
//                        printf("%f\n",ywMin);
                    }
                    else
                        if(key == 't'){
                            ywMax+=10;
//                            printf("%f\n",ywMax);
//                            printf("%f\n",ywMin);
                        }
                        else
                            if(key == 'g'){
                                ywMax-=10;
                                if(ywMin > ywMax)
                                    ywMax = ywMin;
//                                printf("%f\n",ywMax);
//                                printf("%f\n",ywMin);
                            }
    glLoadIdentity();
    
    glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
    displayFcn();
}
//void mymenu(int value) {
//    if(value==1)
//        glClear(GL_COLOR_BUFFER_BIT);
//    if(value==2)
//        exit(0);
//}

int main(int argc, char** argv)
{
    printf("use 'w' and 's' control xwMin up and down\n");
    printf("use 'e' and 'd' control xwMax up and down\n");
    printf("use 'r' and 'f' control ywMin up and down\n");
    printf("use 't' and 'g' control ywMax up and down\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Perspective View of A Square");
    init();
    glutDisplayFunc(displayFcn);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshapeFcn);
//    gluPerspective(45, (GLfloat)2,0.1f, 300.0f);                           // 设置透视图// 透视角设置为 45 度,在Y方向上以角度为单位的视野// 窗口的宽与高比// 视野透视深度:近点1.0f// 视野透视深度:始点0.1f远点1000.0f
    
    glutMainLoop();
    return 0;
}
