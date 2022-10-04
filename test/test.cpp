#include <gtest/gtest.h>
#include <iostream>
#include "../include/pid.hpp"

::testing::AssertionResult IsBetweenmaxmin(double val, double a, double b)
{
    if((val > a) && (val <= b))
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure()
               << val << " is outside the range " << a << " to " << b;
}
// /// Unit test to check if the Proportional constant is in the range
TEST(testingforkp, Testfail)
{
    PID pid(2, 1, 0.5, 0.05, 10, -10);
    std::cout << pid.getKp() << "_____" << Kpmax << "_____" << Kpmin;
    EXPECT_FALSE(IsBetweenmaxmin(pid.getKp(), Kpmin, Kpmax));
}
 /// Unit test to check if the Integral constant is in the range
TEST(testingforki, TestFail)
 {
     PID pid(1, 2, 0.5, 0.05, 10, -10);
     EXPECT_FALSE(IsBetweenmaxmin(pid.getKi(), Kimin, Kimax));
 }
 /// Unit test to check if the Derivative constant is in the range
 TEST(testingforkd, TestFail)
 {
     PID pid(1, 1, 2, 0.05, 10, -10);
     EXPECT_FALSE(IsBetweenmaxmin(pid.getKd(), Kdmin, Kdmax));
 }
 /// Unit test to check if dt is in the range
 TEST(testingfortime, TestFail)
 {
     PID pid(1, 1, 0.5, 0.5, 10, -10);
     EXPECT_FALSE(IsBetweenmaxmin(pid.getdt(), 0, tmax));
 }
/// Unit test to check compute function
TEST(Pidcompute, testcompute) {
    PID pid(1, 1, 0.5, 0.5, 10, -10);
    double result = pid.compute(0.1, 0.2);
    ASSERT_EQ(result, 5);
}
