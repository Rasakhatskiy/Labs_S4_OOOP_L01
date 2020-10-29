#ifndef TREEMODEL_HPP
#define TREEMODEL_HPP

#include <QAbstractItemModel>
#include <QModelIndex>
#include "treeitem.hpp"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

private:
    void setupModelData(const QStringList &lines, TreeItem *parent);

    TreeItem *rootItem;

public:
    /*!
     * \brief Constructor, creates _root node, calls setupModelData
     * \param data[in] Data for constructing tree.
     * \param parent[in] Parent object.
     */
    explicit TreeModel(const QString &data, QObject *parent = nullptr);

    /*! Destructor, deletes root */
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


};

#endif // TREEMODEL_HPP
