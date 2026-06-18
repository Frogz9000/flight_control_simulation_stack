#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion{
public:
    double a; 
    double b; 
    double c; 
    double d;
    Quaternion(double a, double b, double c, double d): a (a), b (b), c (c), d (d) {}
};

#endif