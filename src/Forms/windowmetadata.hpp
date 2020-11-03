#ifndef WINDOWMETADATA_HPP
#define WINDOWMETADATA_HPP

#include <QDialog>

namespace Ui {
class WindowMetadata;
}

class WindowMetadata : public QDialog
{
    Q_OBJECT

public:
    explicit WindowMetadata(QWidget *parent = nullptr);
    ~WindowMetadata();

private slots:
    void on_pushButton_cancel_clicked();

private:
    Ui::WindowMetadata *ui;
};

#endif // WINDOWMETADATA_HPP
