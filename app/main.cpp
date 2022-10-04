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
#include "pid.hpp"



/// Necessary namespace identifiers are includes
using std::cin;
using std::cout;
using std::endl;



/// Main function
int main() {
  double kp, ki, kd, t, maximum, minimum;
  kp = 1;
  ki = 1;
  kd = 1;
  t = -1;
  maximum = 10;
  minimum = -10;
  /// Constructor is called
  /// Process variable is calculated and printed by calling the compute method
  PID pid(1, 1, 1, 0.05, 10, -10);
  double setpoint = 5;
  double process_var = 1;
  for (int i = 0; i < 500; i++) {
    process_var = pid.compute(setpoint, process_var);
    cout << "Output = " << process_var << endl;
  }
}
