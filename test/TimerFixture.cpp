#include "gtest/gtest.h"

#include "../Timer.h"


class TimerSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        t = Timer();
    }

    Timer t;
};


TEST_F(TimerSuite, StartTimer) {
    time_point<steady_clock> start = steady_clock::now();
    t.startTimer();

    ASSERT_TRUE(t.isRunning());
    ASSERT_LE(start, t.getStart());
    ASSERT_GE(steady_clock::now(), t.getStart());
}

TEST_F(TimerSuite, StopTimer){
    t.stopTimer();

    ASSERT_FALSE(t.isRunning());
}