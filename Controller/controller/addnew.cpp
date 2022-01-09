#include "addnew.h"

const QStringList AddNew::monthValues = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "Dicember"
    };

const QString AddNew::currentYear = "2022";

AddNew::AddNew(QWidget* parent) : QWidget(parent),
    layout(new QVBoxLayout()), formLayout(new QVBoxLayout()),
     month(new QComboBox()), year(new QSpinBox()),
     b2b(new QSpinBox()), b2c(new QSpinBox()),
     b2g(new QSpinBox()), submit(new QPushButton(tr("Submit")))
{
    CreateForm();
    CreateLayout();
    CreateConnections();
}

AddNew::~AddNew() {}

void AddNew::CreateForm() {
    QLabel* title = new QLabel();
    title->setText("Chart Parameters:\n");

    QLabel* dateLabel = new QLabel();
    dateLabel->setText("Insert Date");
    QHBoxLayout* formRow1 = new QHBoxLayout();
    month->addItems(monthValues);
    year->setRange(currentYear.toInt() - 100, currentYear.toInt() + 100);
    year->setValue(currentYear.toInt());
    formRow1->addWidget(month);
    formRow1->addWidget(year);

    QLabel* valuesLabel = new QLabel();
    valuesLabel->setText("Insert Values");
    QHBoxLayout* formRow2 = new QHBoxLayout();
    QLabel* B2BLabel = new QLabel();
    B2BLabel->setText("B2B: ");
    b2b->setRange(0, INT_MAX);
    formRow2->addWidget(B2BLabel);
    formRow2->addWidget(b2b);

    QHBoxLayout* formRow3 = new QHBoxLayout();
    QLabel* B2CLabel = new QLabel();
    B2CLabel->setText("B2C: ");
    b2c->setRange(0, INT_MAX);
    formRow3->addWidget(B2CLabel);
    formRow3->addWidget(b2c);

    QHBoxLayout* formRow4 = new QHBoxLayout();
    QLabel* B2GLabel = new QLabel();
    B2GLabel->setText("B2G: ");
    b2g->setRange(0, INT_MAX);
    formRow4->addWidget(B2GLabel);
    formRow4->addWidget(b2g);

    formLayout->addWidget(title);
    formLayout->addWidget(dateLabel);
    formLayout->addLayout(formRow1);
    formLayout->addWidget(valuesLabel);
    formLayout->addLayout(formRow2);
    formLayout->addLayout(formRow3);
    formLayout->addLayout(formRow4);
}

void AddNew::CreateLayout() {
    formLayout->addWidget(submit, Qt::AlignRight);
    formLayout->insertStretch(formLayout->count());
    layout->addLayout(formLayout);
}

void AddNew::CreateConnections() {
    connect(submit, SIGNAL(pressed()), this->parentWidget()->parentWidget(), SLOT(addNewChart()));
}

QVBoxLayout* AddNew::Layout() const {
    return layout;
}

std::vector<QString> AddNew::getFormContent() const {
    std::vector<QString> form;
    form.push_back(QString::number(year->value()));
    form.push_back(month->currentText());
    form.push_back(QString::number(b2b->value()));
    form.push_back(QString::number(b2c->value()));
    form.push_back(QString::number(b2g->value()));
    return form;
}


