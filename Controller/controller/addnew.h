#ifndef ADDNEW_H
#define ADDNEW_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QDebug>

#include "slidingstackedwidget.h"
#include "dropsitewindow.h"

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
    DropSiteWindow* drop;
    QLabel* label;

    void CreateForm();
    void CreateLayout();
    void CreateConnections();

    const static QStringList monthValues;
public:
    AddNew(QWidget *parent = 0);
    ~AddNew();

    QVBoxLayout* Layout() const;
    std::vector<QString> getFormContent() const;
    const QString getDropDownFilesPath() const;
    void setLabelMsg(const QString &);
};

#endif // ADDNEW_H
