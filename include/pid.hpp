/**
 * @file pid.hpp
 * @author Driver : Badrinarayanan Raghunathan Srikumar
           Navigator : Shelvin Pauly
 * @brief  Header file that has class and member definitions
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_
/// Specific set of maximum and minimum values were defined for proprotional
/// ,Integral and Derivative constants.
/// In order to take an integral or a derivative, the dt term should be very
/// small. Hence a maxx value for dt was set as tmax.
const double Kpmax = 1;
const double Kpmin = -1;
const double Kimax = 1;
const double Kimin = -1;
const double Kdmax = 1;
const double Kdmin = -1;
const double tmax = 0.05;
/// A PID class with Kp,Ki,Kd,dt and max,min values
// for the process variable is created
/// with these variables as private members
class PID {
  double Kp;
  double Ki;
  double Kd;
  double dt;
  double max;
  double min;
  double KiError;
  double prev_error = 0;
  /// A constructor that is used to define initial values for the above
  /// variables
 public:
  PID(double p, double i, double d, double t, double ma, double mi);
  /// A compute function that computes the process variable using the necessary
  /// constants is written
  double compute(double sp, double pv);
  /// Takes in the set point and process variable and calculates the error
  /// using each constant and also computes the new value of the process
  /// variable

  double getKp();
  /// Function to return Proportional constant
  double getKi();
  /// Function to return Integral constant
  double getKd();
  /// Function to return Derivative constant
  double getdt();
  /// Function to return time interval
};
#endif  // INCLUDE_PID_HPP_
