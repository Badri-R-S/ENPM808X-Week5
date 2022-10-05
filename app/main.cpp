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

// Necessary header files were added

#include <cstdlib>
#include <iostream>

#include "../include/pid.hpp"

// Necessary namespace identifiers are includes
using std::cin;
using std::cout;
using std::endl;

/// Main function
int main() {
  /// Constructor is called
  /// Process variable is calculated and printed by calling the compute method
  PID pid(0.5, 1, 0.01, 0.05, 10, -10);
  double setpoint = 5;
  double process_var = 1;
  /// Process variable is calculated multiple times till it reaches the setpoint
  for (int i = 0; i < 150; i++) {
    process_var = pid.compute(setpoint, process_var);
    cout << "Output = " << process_var << endl;
  }
}
