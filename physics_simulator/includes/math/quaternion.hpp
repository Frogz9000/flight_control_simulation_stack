#ifndef QUATERNION_H
#define QUATERNION_H
#include <cmath>
#include <math.h>
/**
    Consider making fields private and only exposing thorugh const getters, this would allow guarantee of normalized quaternions for operations
**/
class Quaternion{
public:
    double w; 
    double i; 
    double j; 
    double k;
    Quaternion(double w = 1.0, double i = 0.0, double j = 0.0, double k = 0.0): w (w), i (i), j (j), k (k) {
        if (w == 0.0 && i == 0.0 & j == 0.0 && k == 0.0){
            w = 1.0;
        }
        normalize();
    }

    Quaternion& operator*=(const double scalar){
        w *= scalar;
        i *= scalar;
        j *= scalar;
        k *= scalar;
        return *this;
    }

    Quaternion& operator*=(const Quaternion& other){
        double w0 = w;
        double i0 = i;
        double j0 = j;
        double k0 = k;

        w = (w0*other.w) - (i0 * other.i) - (j0 * other.j) - (k0 * other.k);
        i = (w0*other.i) + (i0 * other.w) + (j0 * other.k) - (k0 * other.j);
        j = (w0*other.j) - (i0 * other.k) + (j0 * other.w) + (k0 * other.i);
        k = (w0*other.k) + (i0 * other.j) - (j0 * other.i) + (k0 * other.w);
        return *this;
    }

    Quaternion operator*(const Quaternion& other) const{
        Quaternion ret_val = *this;
        ret_val*=other;
        return ret_val;
    }

    Quaternion inverse() const {
        Quaternion inv = *this;
        inv.i = -(inv.i);
        inv.j = -(inv.j);
        inv.k = -(inv.k);   
        return inv;
    }

    void normalize(){
        double norm_factor = sqrt((w*w) + (i*i) + (j*j) + (k*k));
        w /= norm_factor;
        i /= norm_factor;
        j /= norm_factor;
        k /= norm_factor;
    }

};


#endif