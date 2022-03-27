// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata automata;

    automata.on();
    automata.coin(5);

    automata.choice(0);

    EXPECT_EQ(false, automata.check());
}

TEST(task1, test2) {
    Automata automata;

    automata.on();
    automata.coin(10);

    automata.choice(0);

    EXPECT_EQ(true, automata.check());
}

TEST(task1, test3) {
    Automata automata;

    automata.on();
    automata.coin(20);

    automata.choice(1);

    EXPECT_EQ(true, automata.check());
}

TEST(task2, test1) {
    Automata automata;

    automata.on();
    automata.off();

    EXPECT_EQ(ST_OFF, automata.getState());
}

TEST(task2, test2) {
    Automata automata;

    automata.on();
    automata.coin(5);

    EXPECT_EQ(ST_ACCEPT, automata.getState());
}

TEST(task2, test3) {
    Automata automata;

    automata.on();
    automata.off();

    EXPECT_EQ(ST_OFF, automata.getState());
}

TEST(task2, test4) {
    Automata automata;

    automata.on();
    automata.coin(5);
    automata.cancel();

    EXPECT_EQ(ST_WAIT, automata.getState());
}

TEST(task2, test5) {
    Automata automata;

    automata.on();
    automata.coin(5);
    automata.coin(5);

    EXPECT_EQ(ST_ACCEPT, automata.getState());
}

TEST(task2, test6) {
    Automata automata;

    automata.on();
    automata.coin(5);
    automata.choice(0);

    EXPECT_EQ(ST_CHECK, automata.getState());
}

TEST(task2, test7) {
    Automata automata;

    automata.on();
    automata.coin(5);
    automata.choice(0);

    EXPECT_EQ(ST_CHECK, automata.getState());
}

TEST(task2, test8) {
    Automata automata;

    automata.on();
    automata.coin(5);
    automata.choice(0);
    automata.check();

    EXPECT_EQ(ST_CHECK, automata.getState());
}

TEST(task2, test9) {
    Automata automata;

    automata.on();
    automata.coin(5);
    automata.choice(0);
    automata.cancel();

    EXPECT_EQ(ST_WAIT, automata.getState());
}

TEST(task2, test10) {
    Automata automata;

    automata.on();
    automata.coin(10);
    automata.choice(0);
    automata.cook();

    EXPECT_EQ(ST_COOK, automata.getState());
}

TEST(task2, test11) {
    Automata automata;

    automata.on();
    automata.coin(10);
    automata.choice(0);
    automata.cook();
    automata.finish();

    EXPECT_EQ(ST_WAIT, automata.getState());
}
