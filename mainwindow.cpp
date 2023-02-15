#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtConcurrent/QtConcurrentRun>

MainWindow::MainWindow(Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow), controller_(controller)
{
    ui_->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui_;
}
void MainWindow::on_pushButton_clicked()
{
    ui_->lineEdit->clear();
    int numbers = ui_->comboBox->currentText().toInt();
    int mode = GetMode();
    QString s = controller_->GetPassword(mode, numbers);
    ui_->lineEdit->setText(s);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString q = ui_->lineEdit->text();
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(q);
}

int MainWindow::GetMode() {
    int res = 0;
    if (ui_->radioButton->isChecked()) {
        res = 1;
    }
    if (ui_->radioButton_2->isChecked()) {
        res = 2;
    }
    if (ui_->radioButton_3->isChecked()) {
        res = 3;
    }
    return res;
}
