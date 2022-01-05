#ifndef ADDNEW_H
#define ADDNEW_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QDebug>

class AddNew :  public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QVBoxLayout* formLayout;
    QComboBox* month;
    QSpinBox* year;
    QSpinBox* b2b;
    QSpinBox* b2c;
    QSpinBox* b2g;
    QPushButton* submit;

    void CreateForm();
    void CreateLayout();
    void CreateConnections();

    static QStringList monthValues;
    static QString currentYear;
public:
    AddNew(QWidget *parent = 0);
    ~AddNew();

    QVBoxLayout* Layout() const;
    std::vector<QString> getFormContent() const;
};

#endif // ADDNEW_H
