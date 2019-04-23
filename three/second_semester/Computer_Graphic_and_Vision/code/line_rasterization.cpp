#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>
double xk,yk;
double x_1,y_1;
double x_2,y_2;

double f(double x11,double y11,double x12,double y12,double x,double y){
    return y11+((y12-y11)/(x12-x11))*(x-x11)-y;
}

void drawpoint(){
    printf("------please input x1 < x2------\n");
    printf("please input point 1:\n");
    
    scanf("%lf %lf",&x_1,&y_1);
    printf("please input point 2:\n");
    
    scanf("%lf %lf",&x_2,&y_2);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.1,0.4,0.2);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 1200.0, 0.0, 1150.0);
    glVertex2d(xk,yk);

    glBegin(GL_POINTS);
    int situation = 0;// 1: 1>k>0   2: k>1  3: k<-1 4: -1<k<0
    float k = (y_1-y_2)/(x_1-x_2);
    if(k>1)
        situation = 2;
    else
        if(k>0&&k<1)
            situation = 1;
        else
            if(k>-1&&k<0)
                situation = 4;
            else
                situation = 3;
    double pk ,pk1 ;
    xk = x_1;
    yk = y_1;
    if(situation == 1){// 1>k>0{
        for(int i = 0;i < (int)fabs(x_2-x_1)-1;i++){
            pk = f(x_1,y_1,x_2,y_2,xk+1,yk+0.5);
            if(pk >= 0){
                xk+=1;
                yk+=1;
            }
            else
                xk+=1;
            glVertex2d(xk,yk);
            printf("%lf,%lf\n",xk,yk);
        }
    }
    else
        if(situation == 2){
            for(int i = 0;i < (int)fabs(y_2-y_1)-1;i++){
                pk = f(x_1,y_1,x_2,y_2,xk+0.5,yk+1);
                if(pk >= 0)
                    yk+=1;
                else{
                    xk+=1;
                    yk+=1;
                }
                glVertex2d(xk,yk);
                printf("%lf,%lf\n",xk,yk);
            }
        }
        else
            if(situation == 3){
                for(int i = 0;i < (int)fabs(y_2-y_1)-1;i++){
                    pk = f(x_1,y_1,x_2,y_2,xk+0.5,yk-1);
                    if(pk >= 0){
                        xk+=1;
                        yk-=1;
                    }
                    else
                        yk-=1;
                    glVertex2d(xk,yk);
                    printf("%lf,%lf\n",xk,yk);
                }
            }
            else{
                for(int i = 0;i < (int)fabs(x_2-x_1)-1;i++){
                    pk = f(x_1,y_1,x_2,y_2,xk+1,yk-0.5);
                    if(pk >= 0)
                        xk+=1;
                    else{
                        xk+=1;
                        yk-=1;
                    }
                    glVertex2d(xk,yk);
                    printf("%lf,%lf\n",xk,yk);
                }
            }
    glEnd();
    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE |GLUT_RGB |GLUT_DEPTH);
    glutCreateWindow("line");
    glutInitWindowSize (1200,1150);
    glutInitWindowPosition (400,100);
    glutDisplayFunc(drawpoint);
    glutMainLoop();
}
