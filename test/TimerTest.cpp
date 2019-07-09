//
// Created by kevin on 09/07/19.
//

#include "gtest/gtest.h"

#include "../Timer.h"

TEST(TimerTest, DefaultConstructor) {
    Timer t;
    ASSERT_FALSE(t.isRunning());
    ASSERT_EQ(0, t.getDuration());
}

