// Copyright 2022 Coffee man

#include <cassert>

#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu = { "Вода кипячёная", "Вода газированная", "Чай" };
    prices = { 10, 20, 30 };
    state = ST_OFF;

    current_choice = 0;
    to_subtract = 0;
}

// Включение автомата
void Automata::on(void) {
    switch (state) {
        case ST_OFF:
            state = ST_WAIT;
            break;
        default:
            break;
    }
}

// Выключение автомата
void Automata::off(void) {
    switch (state) {
        case ST_WAIT:
            state = ST_OFF;
            break;
        default:
            break;
    }
}

// Занесение денег на счёт пользователем
void Automata::coin(CashAmount_t amount) {
    switch (state) {
        case ST_WAIT:
        case ST_ACCEPT:
            cash += amount;
            state = ST_ACCEPT;
            break;
        default:
            break;
    }
}

// Считывание меню с напитками и ценами для пользователя
void Automata::getMenu(std::ostream *out) {
    if (!out) return;

    auto &os = *out;

    assert(menu.size() == prices.size());

    auto it_menu = menu.begin();
    auto it_price = prices.begin();

    while (it_menu != menu.end()) {
        os << *it_menu << " - " << *it_price << '\n';

        it_menu++;
        it_price++;
    }
}

// Считывание текущего состояния для пользователя
enum STATES Automata::getState(void) {
    return state;
}

// Выбор напитка пользователем
// choice_id должен начинаться с 0
void Automata::choice(unsigned choice_id) {
    switch (state) {
        case ST_ACCEPT:
            state = ST_CHECK;
            current_choice = choice_id;
            break;
        default:
            break;
    }
}

// Проверка наличия необходимой суммы
bool Automata::check(void) {
    switch (state) {
        case ST_CHECK:
            try {
                CashAmount_t needed_price = prices.at(current_choice);

                if (needed_price <= cash) {
                    return true;
                }
            } catch (...) {
                current_choice = 0;
                cash = 0;
                state = ST_WAIT;
                to_subtract = 0;
                return false;
            }
            break;
        default:
            break;
    }

    return false;
}

// Отмена сеанса обслуживания пользователем
void Automata::cancel(void) {
    switch (state) {
        case ST_ACCEPT:
        case ST_CHECK:
            state = ST_WAIT;
            current_choice = 0;
            cash = 0;
            to_subtract = 0;
            break;
        default:
            break;
    }
}

// Имитация процесса приготовления напитка
void Automata::cook(void) {
    switch (state) {
        case ST_CHECK:
            state = ST_COOK;
            cash -= to_subtract;
            break;
        default:
            break;
    }
}

// Завершение обслуживания пользователя
void Automata::finish(void) {
    switch (state) {
        case ST_COOK:
            state = ST_WAIT;
            break;
        default:
            break;
    }
}
