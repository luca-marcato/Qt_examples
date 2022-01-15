#ifndef DROPAREA_H
#define DROPAREA_H

#include <QLabel>

QT_BEGIN_NAMESPACE
class QMimeData;
QT_END_NAMESPACE

class DropArea : public QLabel
{
    Q_OBJECT
public:
    explicit DropArea(QWidget *parent = nullptr);

public slots:
    void clear();

signals:
    void changed(const QMimeData *mimeData = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *) override;
    void dragMoveEvent(QDragMoveEvent *) override;
    void dragLeaveEvent(QDragLeaveEvent *) override;
    void dropEvent(QDropEvent *) override;

private:
    static unsigned int files;
    QLabel *label;
};

#endif // DROPAREA_H
