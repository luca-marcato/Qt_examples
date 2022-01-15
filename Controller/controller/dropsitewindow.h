#ifndef DROPSITEWINDOW_H
#define DROPSITEWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QMimeData;
class QPushButton;
class QTableWidget;
QT_END_NAMESPACE
class DropArea;

class DropSiteWindow : public QWidget
{
    Q_OBJECT

public:
    DropSiteWindow(QWidget* =nullptr);

    const QString getFilesPath() const;
public slots:
    void getFiles(const QMimeData *mimeData);

private:
    DropArea *dropArea;

    QPushButton *cancelButton;
    QPushButton *okButton;
    QDialogButtonBox *buttonBox;

    QString* files;
};


#endif // DROPSITEWINDOW_H
