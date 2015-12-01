#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include "console.h"
#include<iostream>
#include "gwindow.h"
#include "gobjects.h"

using namespace std;

//Options window
const double WINDOW_WIDTH = 1200;
const double WINDOW_HEIGHT = 800;

//Setting the length of the initial element. Set recursion depth.
const double LENGHT = WINDOW_HEIGHT/6;
const int RECURSION_DEPTH = 15;

//Installation of basic angles to build the tree
const double RIGHT_ANGLE = 90;
const double THETA = 45;

//conversion of the angle from degrees to radians
#define PI 3.14159
const double THETA_RADIAN = (THETA * PI)/180;



//The function takes the following parameters:
//pointer to the object window GWindow &gw,
//GPoint endPoint1 and endPoint2 takes the end point of the lines,
//double length takes a length of element of the privious order,
//double theta takes the angle of the privious order,
//int recursion_depth takes a value of recursion depth.

void drawPythagoreanTree(GWindow &gw, GPoint endPoint1, GPoint endPoint2, double length, double theta, int recursion_depth);

//building a basic element, and then calls for the creation of other elements in accordance with the recursion depth
int main() {
    GWindow gw(WINDOW_WIDTH, WINDOW_HEIGHT);
    gw.setColor("Black");
    gw.fillRect(0, 0, gw.getWidth(), gw.getHeight());
    gw.setColor("GREEN");
    gw.drawLine(gw.getWidth()/2 - LENGHT/2, gw.getHeight(), gw.getWidth()/2 + LENGHT/2, gw.getHeight());
    GPoint start1(gw.getWidth()/2 - LENGHT/2, gw.getHeight());
    GPoint endPoint1 = gw.drawPolarLine(start1, LENGHT, RIGHT_ANGLE);
    GPoint start2(gw.getWidth()/2 + LENGHT/2, gw.getHeight());
    GPoint endPoint2 = gw.drawPolarLine(start2, LENGHT, RIGHT_ANGLE);
    gw.drawLine(endPoint1, endPoint2);
    drawPythagoreanTree(gw, endPoint1, endPoint2, LENGHT, RIGHT_ANGLE, RECURSION_DEPTH);
    return 0;
}


//builds two lines from each of two gotten vertex and calls itself recursively until the depth of recursion becomes zero
void drawPythagoreanTree(GWindow &gw, GPoint endPoint1, GPoint endPoint2, double input_length, double theta, int recursion_depth){
        double theta_one = theta - THETA;
        double theta_two = theta + THETA;

        double length = input_length * cos(THETA_RADIAN);

        GPoint branch1_1 = gw.drawPolarLine(endPoint1, length*2, theta_one);
        GPoint branch1_2 = gw.drawPolarLine(endPoint2, length, theta_one);
        gw.setColor("YELLOW");
        gw.drawLine(branch1_1, branch1_2);
        GPoint branch2_1 = gw.drawPolarLine(endPoint1, length, theta_two);
        GPoint branch2_2 = gw.drawPolarLine(endPoint2, length*2, theta_two);
        gw.setColor("GREEN");
        gw.drawLine(branch2_1, branch2_2);

        recursion_depth--;

        if(recursion_depth == 0){
            return;
        }
        drawPythagoreanTree(gw, branch1_1, branch1_2, length, theta_one, recursion_depth);
        drawPythagoreanTree(gw, branch2_1, branch2_2, length, theta_two, recursion_depth);

}






























