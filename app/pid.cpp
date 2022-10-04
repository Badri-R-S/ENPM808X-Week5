/**
 * @file pid.cpp
 * @author Driver : Badrinarayanan Raghunathan Srikumar
           Navigator : Shelvin Pauly
 * @brief  Program that includes the class and member function definitions
           for the main.cpp
 * @version 0.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Necessary header files added
#include "../include/pid.hpp"
#include <iostream>

/// Constructor
PID::PID(double p, double i, double d, double t, double ma, double mi) {
    Kp = p;
    Ki = i;
    Kd = d;
    dt = t;
    max = ma;
    min = mi;
  }
/// Compute method that computes the process variable using error constants
double PID:: compute(double sp, double pv) {
/// Takes in the set point and process variable and calculates the error
/// using each constant and also computes the new value of the process
/// variable
return 5;
}
/// Funtion to return Proportional constant
double PID:: getKp() {
return Kp;
}
/// Function to return Integral constant
double PID:: getKi() {
return Ki;
}
/// Function to return Derivative constant
double PID:: getKd() {
return Kd;
}
/// Function to return time interval
double PID:: getdt() {
return dt;
}
