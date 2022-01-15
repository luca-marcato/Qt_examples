#include "modifydialog.h"

ModifyDialog::ModifyDialog(QWidget* parent) : QDialog(parent),
                                              info(new QLabel()),
                                              b2bWidget(new QSpinBox()),
                                              b2cWidget(new QSpinBox()),
                                              b2gWidget(new QSpinBox()),
                                              submit(new QPushButton(tr("Confirm"))),
                                              layout(new QVBoxLayout())
{
    CreateForm();
    CreateLayout();
    CreateConnections();
}


void ModifyDialog::CreateForm(){
    info->setText("CHART: No Data Avaiable");
    layout->addWidget(info);

    QHBoxLayout* formRow1  = new QHBoxLayout();
    QLabel* b2bLabel = new QLabel("B2B value: ");
    formRow1->addWidget(b2bLabel);
    b2bWidget->setRange(0, INT_MAX);
    formRow1->addWidget(b2bWidget);

    QHBoxLayout* formRow2  = new QHBoxLayout();
    QLabel* b2cLabel = new QLabel("B2C value: ");
    formRow2->addWidget(b2cLabel);
    b2cWidget->setRange(0, INT_MAX);
    formRow2->addWidget(b2cWidget);

    QHBoxLayout* formRow3  = new QHBoxLayout();
    QLabel* b2gLabel = new QLabel("B2G value: ");
    formRow3->addWidget(b2gLabel);
    b2gWidget->setRange(0, INT_MAX);
    formRow3->addWidget(b2gWidget);

    layout->addLayout(formRow1);
    layout->addLayout(formRow2);
    layout->addLayout(formRow3);
}

void ModifyDialog::CreateLayout() {
    layout->addWidget(submit, Qt::AlignHCenter);
    this->setLayout(layout);
}

void ModifyDialog::CreateConnections() {
    QObject::connect(submit, SIGNAL(pressed()), this->parentWidget()->parentWidget()->parentWidget(), SLOT(updateChart()));
}

void ModifyDialog::setDate(const QString& dateVal) {
    date = dateVal;
    info->setText("CHART: " + date);
}

void ModifyDialog::setValues(const QString& b2bVal, const QString& b2cVal, const QString& b2gVal) {
    b2b = b2bVal.toInt();
    b2bWidget->setValue(b2b);
    b2c = b2cVal.toInt();
    b2cWidget->setValue(b2c);
    b2g = b2gVal.toInt();
    b2gWidget->setValue(b2g);
}

std::vector<QString> ModifyDialog::getFormContent(std::vector<QString>& form) const {
    form.push_back(QString::number(b2bWidget->value()));
    form.push_back(QString::number(b2cWidget->value()));
    form.push_back(QString::number(b2gWidget->value()));
    return form;
}

void ModifyDialog::active(bool value) {
   submit->setVisible(value);
}
