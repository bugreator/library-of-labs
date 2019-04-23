#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>

#define left 0x000001
#define right 0x000010
#define top 0x000100
#define below 0x001000
#define front 0x010000
#define back 0x100000
#define xh 100
#define xl -100
#define yh 100
#define yl -100
#define zh 100
#define zl -100

void init(){
//    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-200, 200, -200, 200,200, -200);

}



void line(double x1,double y1,double z1,double x2,double y2,double z2){
    glColor3d(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3d(x1,y1,z1);
        glVertex3d(x2,y2,z2);
    glEnd();
//    printf("-------%lf,%lf,%lf,%lf,%lf,%lf\n",x1, y1, z1, x2, y2, z2);
}

int judge(double x,double y,double z){
    int code = 0x000000;
    if(x<xl)
        code |= left;
    if(x>xh)
        code |= right;
    if(y<yl)
        code |= below;
    if(y>yh)
        code |= top;
    if(z<zl)
        code |= back;
    if(z>zh)
        code |= front;
    return code;
}
//
void split(double x1,double y1,double z1,double x2,double y2,double z2){
    int judge1,judge2;
    judge1 = judge(x1,y1,z1);
    judge2 = judge(x2,y2,z2);
    printf("%6x,%6x\n",judge1,judge2);
    if(judge1 == 0 && judge2 == 0)
        line(x1, y1, z1, x2, y2, z2);
    if((judge1 & judge2)!= 0)
        exit(0);
    double x = 0,y = 0,z = 0;
    //left->right->top->below->front->back
    while(judge1 != 0||judge2 != 0){
        //judge every time after change coordinate

        if((judge1 & judge2)!= 0)
            exit(0);
        if(judge1 != 0){
            if(judge1&left){
                y1 = y1+(xl-x1)*((y2-y1)/(x2-x1));
                z1 = z1+(xl-x1)*((z2-z1)/(x2-x1));
                x1 = xl;
            }else
                if(judge1&right){
                    y1 = y1+(xh-x1)*((y2-y1)/(x2-x1));
                    z1 = z1+(xh-x1)*((z2-z1)/(x2-x1));
                    x1 = xh;
                }
            else
                if(judge1&below){
                    x1 = x1+(yl-y1)*((x2-x1)/(y2-y1));
                    z1 = z1+(yl-y1)*((z2-z1)/(y2-y1));
                    y1 = yl;
                }
            else
                if(judge1&top){
                    x1 = x1+(yh-y1)*((x2-x1)/(y2-y1));
                    z1 = z1+(yh-y1)*((z2-z1)/(y2-y1));
                    y1 = yh;
                }
            else
                if(judge1&back){
                    y1 = y1+(zl-z1)*((y2-y1)/(z2-z1));
                    x1 = x1+(zl-z1)*((x2-x1)/(z2-z1));
                    z1 = zl;
                }
            else
                if(judge1&front){
                    y1 = y1+(zh-z1)*((y2-y1)/(z2-z1));
                    x1 = x1+(zh-z1)*((x2-x1)/(z2-z1));
                    z1 = zh;
                }
        }else
        if(judge2 != 0){
            if(judge2&left){
                y2 = y2+(xl-x2)*((y2-y1)/(x2-x1));
                z2 = z2+(xl-x2)*((z2-z1)/(x2-x1));
                x2 = xl;
            }else
                if(judge2&right){
                    y2 = y2+(xh-x2)*((y2-y1)/(x2-x1));
                    z2 = z2+(xh-x2)*((z2-z1)/(x2-x1));
                    x2 = xh;
                }
            else
                if(judge2&below){
                x2 = x2+(yl-y2)*((x2-x1)/(y2-y1));
                z2 = z2+(yl-y2)*((z2-z1)/(y2-y1));
                y2 = yl;
                }
            else
                if(judge2&top){
                    x2 = x2+(yh-y1)*((x2-x1)/(y2-y1));
                    z2 = z2+(yh-y1)*((z2-z1)/(y2-y1));
                    y2 = yh;
                }
            else
                if(judge2&back){
                    y2 = y2+(zl-z2)*((y2-y1)/(z2-z1));
                    x2 = x2+(zl-z2)*((x2-x1)/(z2-z1));
                    z2 = zl;
                }
            else
                if(judge2&front){
                    y2 = y2+(zh-z2)*((y2-y1)/(z2-z1));
                    x2 = x2+(zh-z2)*((x2-x1)/(z2-z1));
                    z2 = zh;
                }
        }
        judge1 = judge(x1,y1,z1);
        judge2 = judge(x2,y2,z2);
        printf("%lf,%lf,%lf,%lf,%lf,%lf\n",x1, y1, z1, x2, y2, z2);
        printf("%x,%x\n",judge1,judge2);
    }
    line(x1, y1, z1, x2, y2, z2);
}

void display(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1,1,1);
//    glMatrixMode (GL_PROJECTION);


    split(-200,-200,-200,100,100,200);
    line(xl, yl,1, xl, yh,1);
    line(xl, yl,1, xh, yl,1);
    line(xl, yh,1, xh, yh,1);
    line(xh, yl,1, xh, yh,1);
//    glClearColor(1.0,0.0,0.0,0.0);
//    glBegin(GL_LINE);
//    glVertex3f(100,800,100);
//    glVertex3f(50,100,000);
//    glEnd();
    glFlush();
}


int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE |GLUT_RGB );
    glutInitWindowSize (600,600);
    glutInitWindowPosition (50,50);
    glutCreateWindow("line");
//    glMatrixMode(GL_PROJECTION);
//    glOrtho(-500, 500, -500, 500, -500, 500);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
