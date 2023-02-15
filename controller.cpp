#include "controller.h"

Controller::Controller(Model* model) : model_(model) {}

QString Controller::GetPassword(int mode, int numbers)
{
    return QString::fromStdString(model_->GetPwd(mode, numbers));
}
