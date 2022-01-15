#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QBoxLayout>

class ModifyDialog: public QDialog
{
private:
    QString date;
    int b2b;
    int b2c;
    int b2g;
    QLabel* info;
    QSpinBox* b2bWidget;
    QSpinBox* b2cWidget;
    QSpinBox* b2gWidget;
    QPushButton* submit;
    QVBoxLayout* layout;

    void CreateForm();
    void CreateLayout();
    void CreateConnections();
public:
    ModifyDialog(QWidget* =0);
    void setDate(const QString &);
    void setValues(const QString&, const QString&, const QString&);
    std::vector<QString> getFormContent(std::vector<QString>&) const;
    void active(bool);
};

#endif // MODIFYDIALOG_H
