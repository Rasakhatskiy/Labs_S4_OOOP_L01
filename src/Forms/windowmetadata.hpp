#ifndef WINDOWMETADATA_HPP
#define WINDOWMETADATA_HPP

#include <QDialog>
#include <QMessageBox>

#include "../FileInfo/metadata.hpp"

namespace Ui {
class WindowMetadata;
}

class WindowMetadata : public QDialog
{
    Q_OBJECT

public:
    explicit WindowMetadata(const QString& path, QWidget *parent = nullptr);
    ~WindowMetadata();

private slots:
    void on_pushButton_cancel_clicked();

    void on_button_save_clicked();

private:
    Ui::WindowMetadata *ui;
    void setMetaData(const Metadata& metadata);
    QString path;
};

#endif // WINDOWMETADATA_HPP
