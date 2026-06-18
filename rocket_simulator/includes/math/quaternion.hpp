#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion{
    private:
        double a_; 
        double b_; 
        double c_; 
        double d_;
    public:
        //constructor
    Quaternion(double a, double b, double c, double d): 
                a_ (a), b_ (b), c_ (c), d_ (d) {}
        //readonly public access
        double a() const {return a_;}
        double b() const {return b_;}
        double c() const {return c_;}
        double d() const {return d_;}
};

#endif