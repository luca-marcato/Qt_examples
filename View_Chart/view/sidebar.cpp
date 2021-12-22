#include "sidebar.h"

SideBar::SideBarButton::SideBarButton(int index, const QString &text, QWidget *parent) : QPushButton(text, parent), index(index) {}

SideBar::SideBarButton::SideBarButton(int index, const QIcon& icon, const QString &text, QWidget *parent) : QPushButton(icon, text, parent), index(index) {}

int SideBar::SideBarButton::getIndex() const {
    return index;
}

int SideBar::SideBarButton::onPressed() const {
    return index;
}

SideBar::SideBarButton* SideBar::buttonAt(int i) const {
    return buttons.at(i);
}

int SideBar::countButton() const {
    return buttons.size();
}

SideBar::SideBar(QWidget *parent) : QWidget(parent), buttons(QVector<SideBarButton*>()) {}

void SideBar::addButton(QPushButton *btr) {
    if(buttons.isEmpty()) {
        buttons.push_back(new SideBarButton(0, btr->text(), btr->parentWidget()));
    } else {
        buttons.push_back(new SideBarButton(buttons.last()->getIndex() + 1, btr->text(), btr->parentWidget()));
    }
}

void SideBar::removeButton(int i) {
    buttons.remove(i);
}

void SideBar::removeButtons(int i, int n) {
    buttons.remove(i, n);
}

QVector<const SideBar::SideBarButton*> SideBar::getButtons() const {
    return buttons;
}
