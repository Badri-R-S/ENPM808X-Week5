#ifndef PID_HPP_
#define PID_HPP_
/// Specific set of maximum and minimum values were defined for proprotional
/// ,Integral and Derivative constants.
/// In order to take an integral or a derivative, the dt term should be very
/// small. Hence a maxx value for dt was set as tmax.
const double Kpmax = 1;
const double Kpmin = -1;
const double Kimax = 0.1;
const double Kimin = -0.1;
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
  double getKi();
  double getKd();
  double getdt();
};
#endif // PID_HPP_