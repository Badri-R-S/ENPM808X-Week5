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
#include <iterator>

/**
 * @brief Constructor for PID class
 * 
 * @param p proportional gain
 * @param i integral gain
 * @param d differential gain
 * @param t time interval 
 * @param ma maximum permissible value for p,i,d
 * @param mi minimum permissible value for p,i,d
 */

PID::PID(double p, double i, double d, double t, double ma, double mi) {
    Kp = p;
    Ki = i;
    Kd = d;
    dt = t;
    max = ma;
    min = mi;
    KiError = 0;
    prev_error = 0;
  }

/**
 * @brief Computes the process variable using error constants
 * 
 * @param sp set point is the target value of the process variable
 * @param pv current state of the process variable
 * @return double 
 */
double PID:: compute(double sp, double pv) {
double Error, KdError;
Error = sp - pv;
KdError = Error-prev_error;
KiError = KiError + Error;
double Newpv;
Newpv = Kp*Error + Kd*KdError/dt + Ki*KiError*dt;
prev_error = Error;
return Newpv;
}

/**
 * @brief Get the Kp object (proportional constant)
 * 
 * @return double 
 */
double PID:: getKp() {
return Kp;
}
/**
 * @brief Get the Ki object (Integral constant)
 * 
 * @return double 
 */
double PID:: getKi() {
return Ki;
}

/**
 * @brief Get the Kd object (Derivative constant)
 * 
 * @return double 
 */
double PID:: getKd() {
return Kd;
}
/**
 * @brief Function to return time interval
 * 
 * @return double 
 */
double PID:: getdt() {
return dt;
}
