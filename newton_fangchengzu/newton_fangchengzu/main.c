#include <stdio.h>
#include <math.h>
double f1(double x,double y){
    return x*x+y*y-1;
}
double f2(double x,double y){
    return x*x*x-y;
}
double f3(double x){
    return 2*x;
}

double f4(double y){
    return 2*y;
}

double f5(double x){
    return 3*x*x*x;
}

double bigger(double x,double y){
    return (x>y)?x:y;
}

int main() {
    double x = 0.8;
    double y = 0.6;
    double delta_x = -(f1(x,y)+f2(x,y)*f4(y))/(f3(x)+f4(y)*f5(x));
    double delta_y = f5(x)*delta_x+f2(x,y);
    int cnt = 0;
    while(fabs(bigger(delta_x,delta_y))>1e-3){
        x+=delta_x;
        y+=delta_y;
        delta_x = -(f1(x,y)+f2(x,y)*f4(y))/(f3(x)+f4(y)*f5(x));
        delta_y = f5(x)*delta_x+f2(x,y);
        cnt++;
    }
    printf("delta_x = %.10e , delta_y = %.10e\n",delta_x,delta_y);
    printf("x = %.10e , y = %.10e\n\n",x,y);
    
    printf("%.10e   ,%.10e  ,%d\n",f1(x,y),f2(x,y),cnt);
    
    return 0;
}
