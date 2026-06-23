#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion{
public:
    double w; 
    double i; 
    double j; 
    double k;
    Quaternion(double w, double i, double j, double k): w (w), i (i), j (j), k (k) {}
};

#endif