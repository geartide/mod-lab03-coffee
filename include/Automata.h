// Copyright 2022 Coffee man

#pragma once

#include <string>
#include <vector>
#include <iostream>

enum STATES {
    ST_OFF,
    ST_WAIT,
    ST_ACCEPT,
    ST_CHECK,
    ST_COOK
};

typedef double CashAmount_t;

class Automata {
    CashAmount_t cash;
    std::vector<std::string> menu;
    std::vector<CashAmount_t> prices;
    enum STATES state;

    unsigned current_choice;
    CashAmount_t to_subtract;

 public:
    Automata();

    // Включение автомата
    void on(void);

    // Выключение автомата
    void off(void);

    // Занесение денег на счёт пользователем
    void coin(CashAmount_t amount);

    // Считывание меню с напитками и ценами для пользователя
    void getMenu(std::ostream *out);

    // Считывание текущего состояния для пользователя
    enum STATES getState(void);

    // Выбор напитка пользователем
    void choice(unsigned choice_id);

    // Проверка наличия необходимой суммы
    bool check(void);

    // Отмена сеанса обслуживания пользователем
    void cancel(void);

    // Имитация процесса приготовления напитка
    void cook(void);

    // Завершение обслуживания пользователя
    void finish(void);
};
