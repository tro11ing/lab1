#ifndef QUADRATIC_TEST_H
#define QUADRATIC_TEST_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern "C" {
#include "equation.h"
#include "quadratic.h"
}

TEST(quadraticTest, abc0) {
    struct equation e = {0,0,0,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.infinity,1);
}

TEST(quadraticTest, ab0) {
    struct equation e = {0,0,1,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,0);
}

TEST(quadraticTest, bc0) {
    struct equation e = {4,0,0,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.x1,0.0);
    ASSERT_EQ(e.x2,e.x1);
}

TEST(quadraticTest, ac0) {
    struct equation e = {0,4,0,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.x1,0.0);
    ASSERT_EQ(e.x2,e.x1);
}

TEST(quadraticTest, a0) {
    struct equation e = {0,2,4,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.x1,-2.0);
    ASSERT_EQ(e.x1,e.x2);
}

TEST(quadraticTest, b0) {
    struct equation e = {2,0,-8,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.x1,2.0);
    ASSERT_EQ(e.x2,-2.0);
}

TEST(quadraticTest, c0) {
    struct equation e = {2,4,0,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.x1,0.0);
    ASSERT_EQ(e.x2,-2.0);
}

TEST(quadraticTest, abc) {
    struct equation e = {1,-5,6,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.x1,3.0);
    ASSERT_EQ(e.x2,2.0);
}

TEST(quadraticTest, disclessthan0) {
    struct equation e = {2,1,7,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,0);
}

TEST(quadraticTest, realnum) {
    struct equation e = {1,3,-7,0,0,0,0};
    float ans1 = ((-3) + sqrt(37))/2;
    float ans2 = ((-3) - sqrt(37))/2;
    float precision = 0.00001;
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_LE(e.x1,ans1+precision);
    ASSERT_GE(e.x1,ans1-precision);
    ASSERT_LE(e.x2,ans2+precision);
    ASSERT_GE(e.x2,ans2-precision);
}

#endif // QUADRATIC_H
