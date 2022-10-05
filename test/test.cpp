/**
 * @file test.cpp
 * @author Driver : Badrinarayanan Raghunathan Srikumar
           Navigator : Shelvin Pauly
 * @brief Unit testing for main.cpp
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */

// Necessary header files added
#include <gtest/gtest.h>

#include <iostream>

#include "../include/pid.hpp"

::testing::AssertionResult IsBetweenmaxmin(double val, double a, double b) {
  if ((val >= a) && (val <= b))
    return ::testing::AssertionSuccess();
  else
    return ::testing::AssertionFailure()
           << val << " is outside the range " << a << " to " << b;
}
/// Unit test to check if the Proportional constant is in the range
TEST(testingforkp, Testfail) {
  PID pid(0.5, 1, 0.01, 0.05, 10, -10);
  std::cout << pid.getKp() << "_____" << Kpmax << "_____" << Kpmin;
  EXPECT_TRUE(IsBetweenmaxmin(pid.getKp(), Kpmin, Kpmax));
}
/// Unit test to check if the Integral constant is in the range
TEST(testingforki, TestFail) {
  PID pid(0.5, 1, 0.01, 0.05, 10, -10);
  EXPECT_TRUE(IsBetweenmaxmin(pid.getKi(), Kimin, Kimax));
}
/// Unit test to check if the Derivative constant is in the range
TEST(testingforkd, TestFail) {
  PID pid(0.5, 1, 0.01, 0.05, 10, -10);
  EXPECT_TRUE(IsBetweenmaxmin(pid.getKd(), Kdmin, Kdmax));
}
/// Unit test to check if dt is in the range
TEST(testingfortime, TestFail) {
  PID pid(0.5, 1, 0.01, 0.05, 10, -10);
  EXPECT_TRUE(IsBetweenmaxmin(pid.getdt(), 0, tmax));
}
/// Unit test to check compute function
TEST(Pidcompute, testcompute) {
  double set_point = 5;
  double pv = 1;
  PID pid(0.5, 1, 0.01, 0.05, 10, -10);
  for (int i = 0; i < 150; i++) {
    pv = pid.compute(set_point, pv);
  }
  EXPECT_NEAR(set_point, pv, 0.1);
}
