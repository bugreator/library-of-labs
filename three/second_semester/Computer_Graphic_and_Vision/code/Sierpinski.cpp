#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>


GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},
    {0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,0.0},
    {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

//GLfloat v[4][3]={
//    {1.0, 0.0, -0.5},
//    {-0.5,0.86602540, -0.5},
//    {-0.5,-0.86602540, -0.5},
//    {0.0,0.0,0.5}
//};
GLfloat v[4][3]={
    {0.0, 0.0, 1.0},
    {0.0, 0.942809, -0.33333}, {-0.816497, -0.471405, -0.333333},
    {0.816497, -0.471405, -0.333333}
};


int triangle_num=0;

void triangle( GLfloat *va, GLfloat *vb, GLfloat *vc){
    
    glBegin(GL_TRIANGLES);
    glVertex3fv(va);
    glVertex3fv(vb);
    glVertex3fv(vc);
    glEnd();
}
void tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
    
    glColor3fv(colors[1]);
    triangle(a,b,c);
    glColor3fv(colors[2]);
    triangle(a,c,d);
    glColor3fv(colors[3]);
    triangle(a,d,b);
    glColor3fv(colors[4]);
    triangle(b,d,c);
}

void Sierpinski(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m){
    GLfloat mid[6][3];
    int j;
    if(m>0){
        for(j=0; j<3; j++) mid[0][j]=(a[j]+b[j])/2;
        for(j=0; j<3; j++) mid[1][j]=(a[j]+c[j])/2;
        for(j=0; j<3; j++) mid[2][j]=(a[j]+d[j])/2;
        for(j=0; j<3; j++) mid[3][j]=(b[j]+c[j])/2;
        for(j=0; j<3; j++) mid[4][j]=(c[j]+d[j])/2;
        for(j=0; j<3; j++) mid[5][j]=(b[j]+d[j])/2;
        
        Sierpinski(a,mid[0],mid[1],mid[2], m-1);  //a顶点
        Sierpinski(mid[0],b,mid[3],mid[5], m-1);  //b顶点
        Sierpinski(mid[1],mid[3],c,mid[4], m-1);  //c顶点
        Sierpinski(mid[2],mid[5],mid[4],d, m-1);  //d顶点
    }
    else
        tetra(a,b,c,d); /* draw tetrahedron at end of recursion */
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){
    triangle_num = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -1.0);
    glTranslatef(0.0, 0.0, -2.0);   //平移
    glRotatef(29.0,65.0,20.0,1.0);  //旋转
    glScalef(1.0,1.1,1.0);          //缩放
    //    glMultMatrixd(current_rotate_matrix);
    Sierpinski(v[0],v[1],v[2],v[3],3);
    glFlush();
}

int main(int argc, char *argv[])
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    return 0;
}

