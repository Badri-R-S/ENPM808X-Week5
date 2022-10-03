/**
 * @file main.cpp
 * @author @driver : Badrinarayanan Raghunathan Srikumar
           @navigator : Shelvin Pauly
 * @brief A C++ program to implement PID controller
 * @version 0.1
 * @date 2022-10-01
 *
 * @copyright Copyright (c) 2022
 *
 */

/// Necessary header files were added

#include <cstdlib>
#include <iostream>
/// Specific set of maximum and minimum values were defined for proprotional
/// ,Integral and Derivative constants.
/// In order to take an integral or a derivative, the dt term should be very
/// small. Hence a maxx value for dt was set as tmax.
double Kpmax = 1;
double Kpmin = -1;
double Kimax = 0.1;
double Kimin = -0.1;
double Kdmax = 1;
double Kdmin = -1;
double tmax = 0.05;

/// Necessary namespace identifiers are includes
using std::cin;
using std::cout;
using std::endl;

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
  /// A constructor that is used to define initial values for the above
  /// variables
 public:
  PID(double p, double i, double d, double t, double ma, double mi) {
    Kp = p;
    Ki = i;
    Kd = d;
    dt = t;
    max = ma;
    min = mi;
  }
  /// A compute function that computes the process variable using the necessary
  /// constants is written
  double compute(double sp, double pv) {}
};

/// Main function
int main() {
  double kp, ki, kd, t, maximum, minimum;
  kp = 0.1;
  ki = 0.04;
  kd = 0.1;
  t = 0.01;
  maximum = 10;
  minimum = -10;
  /// Unit test to check if the Proportional constant is in the range
  if (kp > Kpmax || kp < Kpmin) {
    cout << " Proportional constant cannot be more than " << Kpmax
         << " or less than " << Kpmin;
    return 0;
  }
  /// Unit test to check if the Integral constant is in the range
  if (ki > Kimax) {
    cout << " Integral constant cannot br more than " << Kimax
         << " or less than " << Kimin;
    return 1;
  }
  /// Unit test to check if the Derivative constant is in the range
  if (kd > Kdmax) {
    cout << "Derivative constant cannot be more than " << Kdmax
         << " or less than " << Kdmin;
    return 2;
  }
  /// Unit test to check if dt is in the range
  if (t > tmax || t < 0) {
    cout << " To integrate and take derivative of the errors,"
         << " dt cannot be more than " << tmax << " or less than 0";
    return 3;
  }
  /// Constructor is called
  PID pid = PID(kp, ki, kd, t, maximum, minimum);
  /// Process variable is calculated and printed by calling the compute method
  double setpoint = 5;
  double process_var = 1;
  for (int i = 0; i < 500; i++) {
    process_var = pid.compute(setpoint, process_var);
    cout << "Output = " << process_var << endl;
  }
}
