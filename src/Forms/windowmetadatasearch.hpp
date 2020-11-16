#ifndef WINDOWMETADATASEARCH_H
#define WINDOWMETADATASEARCH_H

#include <QDialog>
#include <QDir>
#include <QStringList>

#include "../FileInfo/metadata.hpp"

namespace Ui {
class WindowMetadataSearch;
}

class WindowMetadataSearch : public QDialog
{
    Q_OBJECT

public:
    explicit WindowMetadataSearch(
        const QString& path,
        const bool &isAND,
        QWidget *parent = nullptr);
    ~WindowMetadataSearch();

private slots:
    void on_button_search_clicked();

private:
    QStringList search(QString scanDirPath);

    Ui::WindowMetadataSearch *ui;
    QString path;
    bool isAND;


};

#endif // WINDOWMETADATASEARCH_H
