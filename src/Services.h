#pragma once

#include<string>

struct date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
    unsigned int hour;
    unsigned int minute;

};

struct servicesType {
    bool pro;
    std::string type;
};

enum processState {
    WaitingPayment,
    Scheduled,
    InProgress,
    Concluded
};

class Intervention {

private:
    unsigned int _id;
    date _appointment;
    servicesType _type;
    bool _forcePro;
    processState _state;
    float _price;

public:
    static unsigned int _idSeq;

    Intervention(date appointment, servicesType type, bool forcePro, float price);
    // o price aqui é temporário tenho que perguntar aos amgs se faz sentido cada serviço ter um preço base e caso
    // sim meter o preço dentro do servicesType, podendo depois fazer o custo total contabilizar de forma
    // diferente dependendo das condições

    servicesType getType();

    processState getProcessState();

    float getPrice() const;

};
