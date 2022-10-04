#include "../include/pid.hpp"
#include <iostream>


PID::PID(double p, double i, double d, double t, double ma, double mi) {
    Kp = p;
    Ki = i;
    Kd = d;
    dt = t;
    max = ma;
    min = mi;
  }
double PID:: compute(double sp, double pv) {
   /// Takes in the set point and process variable and calculates the error
   /// using each constant and also computes the new value of the process
   /// variable
   return 5;
}

double PID:: getKp(){
   return Kp;
}
double PID:: getKi(){
   return Ki;
}
double PID:: getKd(){
   return Kd;
}
double PID:: getdt(){
   return dt;
}
