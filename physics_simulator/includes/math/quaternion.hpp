#ifndef QUATERNION_H
#define QUATERNION_H
#include <cmath>
#include <math.h>
class Quaternion{
public:
    double w; 
    double i; 
    double j; 
    double k;
    Quaternion(double w, double i, double j, double k): w (w), i (i), j (j), k (k) {}

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

    Quaternion conjugate() const {
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
    inline Quaternion operator*(const Quaternion& quaternion, const double scalar) {
        Quaternion ret_val = quaternion;
        ret_val*=scalar;
        return ret_val;
    }

    inline Quaternion operator*(const double scalar, const Quaternion& quaternion) {
        Quaternion ret_val = quaternion;
        ret_val*=scalar;
        return ret_val;
    }

#endif