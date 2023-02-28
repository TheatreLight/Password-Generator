#include "controller.h"

Controller::Controller(Model* model) : model_(model) {}

QString Controller::GetPassword(int mode, int numbers, int seed)
{
    return QString::fromStdString(model_->GetPwd(mode, numbers, seed));
}
