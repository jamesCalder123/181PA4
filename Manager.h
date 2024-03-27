#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee //not sure which access specifier to use
{
    private:
        double bonus;
    public:
        Manager(string theName, double theWage, double theHours, double theBonus);
        double calcPay() const;
};

#endif //MANAGER_H