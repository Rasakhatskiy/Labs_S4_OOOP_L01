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
    void setupTree(const QStringList& data);
};

#endif // WINDOWTREE_HPP
