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

TEST(quadraticTest, disclessthan0) {
    struct equation e = {2,1,7,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,0);
}

TEST(quadraticTest, a0) {
    struct equation e = {0,2,4,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
    ASSERT_EQ(e.x1,e.x2);
}

TEST(quadraticTest, abc) {
    struct equation e = {1,-5,6,0,0,0,0};
    quadratic(&e);
    ASSERT_EQ(e.is_solutions,1);
}

#endif // QUADRATIC_H
