#ifndef ADDNEW_H
#define ADDNEW_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>

class AddNew :  public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QVBoxLayout* formLayout;
    QHBoxLayout* formRow1;
    QHBoxLayout* formRow2;
    QHBoxLayout* formRow3;
    QHBoxLayout* formRow4;
    QPushButton* sumbit;

    void CreateForm();
    void CreateLayout();
    void CreateConnections();

    static QStringList monthValues;
    static QString currentYear;
public:
    AddNew(QWidget *parent = 0);
    ~AddNew();

    QVBoxLayout* Layout() const;
};

#endif // ADDNEW_H
