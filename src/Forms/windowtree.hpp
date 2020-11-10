#ifndef WINDOWTREE_HPP
#define WINDOWTREE_HPP

#include <QDialog>
#include "../Tree/treemodel.hpp"

namespace Ui {
class WindowTree;
}

class WindowTree : public QDialog
{
    Q_OBJECT

public:
    explicit WindowTree(const QStringList& data, QWidget *parent = nullptr);
    ~WindowTree();

private slots:
    void on_button_ok_clicked();

private:
    Ui::WindowTree *ui;

    /*!
     * \brief writes tree to tree model.
     * \param data[in] File paths data to write to tree.
     */
    void setupTree(const QStringList& data);
};

#endif // WINDOWTREE_HPP
