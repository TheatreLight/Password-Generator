#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

#include <QString>

class Controller
{
public:
    explicit Controller(Model* model);
    QString GetPassword(int mode, int numbers, int seed);
private:
    Model* model_;
};

#endif // CONTROLLER_H
