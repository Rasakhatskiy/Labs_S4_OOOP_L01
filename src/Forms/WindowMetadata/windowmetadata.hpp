#ifndef WINDOWMETADATA_HPP
#define WINDOWMETADATA_HPP

#include <QDialog>
#include <QMessageBox>

#include "../../FileInfo/metadata.hpp"

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
    /*!
     * \brief sets metadata to window fields.
     * \param metadata[in] metadata to set.
     */
    void setMetaData(const Metadata& metadata);

    /*! Path of the read file.*/
    QString path;
};

#endif // WINDOWMETADATA_HPP
