// Copyright 2022 Coffee man

#include <iostream>
#include <cassert>

#include "Automata.h"

int main(int argc, char **argv) {
    Automata automata;

    automata.on();
    automata.getMenu(nullptr);
    automata.coin(5);
    automata.coin(5);
    automata.choice(0);
    assert(automata.check());
    automata.cook();
    automata.finish();
    automata.off();

    return EXIT_SUCCESS;
}
