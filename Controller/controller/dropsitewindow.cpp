#include <QtWidgets>

#include "droparea.h"
#include "dropsitewindow.h"

DropSiteWindow::DropSiteWindow(QWidget* parent) : QWidget(parent), files(new QString())
{
    dropArea = new DropArea;
    connect(dropArea, &DropArea::changed,
            this, &DropSiteWindow::getFiles);

    cancelButton = new QPushButton(tr("Cancel"));
    okButton = new QPushButton(tr("Confirm"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(cancelButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(okButton, QDialogButtonBox::ActionRole);

    connect(cancelButton, &QAbstractButton::clicked, dropArea, &DropArea::clear);
    connect(okButton, SIGNAL(pressed()), this->parentWidget()->parentWidget()->parentWidget(), SLOT(addNewFiles()));
    connect(okButton, &QAbstractButton::clicked, dropArea, &DropArea::clear);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(dropArea);
    mainLayout->addWidget(buttonBox);

    setWindowTitle(tr("Drop Site"));
    setMinimumSize(350, 500);
}


void DropSiteWindow::getFiles(const QMimeData *mimeData) {
    if (!mimeData)
        return;
    delete files;
    files = new QString();
    QList<QUrl> urlList = mimeData->urls();
    for (int i = 0; i < urlList.size() && i < 10; ++i)
        files->append(urlList.at(i).toString() + QLatin1Char('|'));
}

const QString DropSiteWindow::getFilesPath() const {
    return *files;
}

