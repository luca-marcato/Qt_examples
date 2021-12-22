#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QString>

class SideBar: public QWidget
{
private:

    class SideBarButton : public QPushButton {
    private:
        int index;
    public:
        SideBarButton(int, const QString&, QWidget* = Q_NULLPTR);
        SideBarButton(int, const QIcon&, const QString&, QWidget* = Q_NULLPTR);
        int getIndex() const;
        int onPressed() const;
    };

    QVector<const SideBarButton*> buttons; //vector o array ??
public:
    SideBar(QWidget* = Q_NULLPTR);
    SideBarButton* buttonAt(int) const;
    int countButton() const;
    void addButton(QPushButton*);
    void removeButton(int);
    void removeButtons(int, int);
    QVector<const SideBarButton*> getButtons() const;
};

#endif // SIDEBAR_H
