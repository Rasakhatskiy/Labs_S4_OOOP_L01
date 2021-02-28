#ifndef WINDOWTREE_HPP
#define WINDOWTREE_HPP

#include <QDialog>
#include "../../Tree/treemodel.hpp"

namespace Ui {
class WindowTree;
}


/*!
 * \brief Window for printing filesystem to tree.
 */
class WindowTree : public QDialog
{
    Q_OBJECT

public:
    explicit WindowTree(const QList<FileInfo>& data, QWidget *parent = nullptr);
    ~WindowTree();

private slots:
    void on_button_ok_clicked();

private:
    Ui::WindowTree *ui;

    /*!
     * \brief writes tree to tree model.
     * \param data[in] File paths data to write to tree.
     */
    void setupTree(const QList<FileInfo>& data);
};

#endif // WINDOWTREE_HPP
