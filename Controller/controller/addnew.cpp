#include "addnew.h"

QStringList AddNew::monthValues = {
        "Gennaio",
        "Febbraio",
        "Marzo",
        "Aprile",
        "Maggio",
        "Giugno",
        "Luglio",
        "Agosto",
        "Settembre",
        "Ottobre",
        "Novembre",
        "Dicembre"
    };

QString AddNew::currentYear = "2020";

AddNew::AddNew(QWidget* parent) : QWidget(parent),
    layout(new QVBoxLayout()), formLayout(new QVBoxLayout()),
     formRow1(new QHBoxLayout()), formRow2(new QHBoxLayout()),
     formRow3(new QHBoxLayout()), formRow4(new QHBoxLayout()),
     sumbit(new QPushButton(tr("Submit")))
{
    CreateForm();
    CreateLayout();
}

AddNew::~AddNew() {}

void AddNew::CreateForm() {
    QComboBox* months = new QComboBox();
    months->addItems(monthValues);
    QSpinBox* years = new QSpinBox();
    years->setRange(currentYear.toInt() - 100, currentYear.toInt() + 100);
    years->setValue(currentYear.toInt());
    formRow1->addWidget(months);
    formRow1->addWidget(years);

    QLabel* B2BLabel = new QLabel();
    B2BLabel->setText("B2B: ");
    QSpinBox* b2b = new QSpinBox();
    b2b->setRange(0, INT_MAX);
    formRow2->addWidget(B2BLabel);
    formRow2->addWidget(b2b);

    QLabel* B2CLabel = new QLabel();
    B2CLabel->setText("B2C: ");
    QSpinBox* b2c = new QSpinBox();
    b2c->setRange(0, INT_MAX);
    formRow3->addWidget(B2CLabel);
    formRow3->addWidget(b2c);

    QLabel* B2GLabel = new QLabel();
    B2GLabel->setText("B2G: ");
    QSpinBox* b2g = new QSpinBox();
    b2g->setRange(0, INT_MAX);
    formRow4->addWidget(B2GLabel);
    formRow4->addWidget(b2g);
}

void AddNew::CreateLayout() {
    QLabel* title = new QLabel();
    title->setText("Chart Parameters:\n");
    formLayout->addWidget(title);

    QLabel* dateLabel = new QLabel();
    dateLabel->setText("Insert Date");
    formLayout->addWidget(dateLabel);
    formLayout->addLayout(formRow1);

    QLabel* valuesLabel = new QLabel();
    valuesLabel->setText("Insert Values");
    formLayout->addWidget(valuesLabel);
    formLayout->addLayout(formRow2);
    formLayout->addLayout(formRow3);
    formLayout->addLayout(formRow4);
    formLayout->addWidget(sumbit, Qt::AlignRight);
    formLayout->insertStretch(formLayout->count());
    layout->addLayout(formLayout);
}

void AddNew::CreateConnections() {

}

QVBoxLayout* AddNew::Layout() const {
    return layout;
}
