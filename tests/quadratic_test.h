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

//TEST(quadraticTest, negative) {
//    ASSERT_EQ(fibonachi(-1), 0);
//}

//TEST(quadraticTest, inputFile) {
//    val = 2;
//    char *filename = (char *)malloc(sizeof(char) * 1024);
//    sprintf(filename, "%s/input321.txt", INPUTDIR);

//    int fd = open(filename, O_RDONLY);
//    free(filename);
//    if (fd < 0) {
//        ASSERT_EQ(errno, 0);
//    }

//    char *buf = (char *)malloc(sizeof(char) * 512);
//    int readcount = read(fd, buf, 512);
//    ASSERT_TRUE(readcount > 0);
//    close(fd);

//    int input = 0;
//    int output =0;
//    int ret = sscanf(buf, "%d %d", &input, &output);
//    free(buf);
//    ASSERT_EQ(ret, 2);

//    ret = fibonachi(input);
//    ASSERT_EQ(ret, output);
//}

#endif // QUADRATIC_H
