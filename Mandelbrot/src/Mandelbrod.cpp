#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "gobjects.h"

using namespace std;

//Creating a class complex number.
//Class which has the following properties: the imaginary(double im) and the real(double re) value of the number.
class ComplexNumber
{
public:
    double re;
    double im;
    //The class constructor
    ComplexNumber(double are = 0.0,double aim = 0.0){
        re = are;
        im = aim;
    }
    //Overloading the + operator for Class ComplexNumbers
    ComplexNumber operator+(const ComplexNumber &v){
        return ComplexNumber(ComplexNumber::re + v.re , ComplexNumber::im + v.im);    }


};
//The function of the squaring of the object class ComplexNumbers
ComplexNumber sqr(const ComplexNumber &v ){
    return ComplexNumber(v.re * v.re - v.im * v.im, 2*v.re * v.im);
}
//Finding the distance to the origin coordinate axis
double abs(const ComplexNumber &v){
    return sqrt(v.re*v.re + v.im*v.im);
}

//The function of drawing the Mandelbrot set.
/*
 * The function creates an object GWindow graphicsWindow and object GCompound comp.
 * In a double loop function passes through all the points of the window and draws
 *  only those that are not included in the set in which: abs(z) < 2.
*/
void display(){
GWindow graphicsWindow(300,300);
graphicsWindow.setColor("BLACK");
GCompound* comp = new GCompound();

    for(int y = 0; y < 300; ++y){
        for(int x = 0; x < 300;++x){
            ComplexNumber z(0,0);
            int i = 0;
            while(i<1000 && abs(z) < 2){
                z = sqr(z) + ComplexNumber(1.0*(x-150)/105, 1.0*(y-150)/105);
                ++i;
            }
            if(abs(z) >= 2){
                GOval* oval = new GOval(x,y,((50.0 - i)/50.0),((50.0 - i)/50.0));
                      oval->setFilled(true);
                      oval->setColor("BLACK");
                      comp->add(oval);

            }
        }
    }
    graphicsWindow.add(comp);

}

int main()
{
display();
    return 0;
}



























