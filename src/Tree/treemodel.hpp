#ifndef TREEMODEL_HPP
#define TREEMODEL_HPP

#include <QAbstractItemModel>
#include <QList>
#include <QModelIndex>
#include <src/FileInfo/fileinfo.hpp>
#include "treeitem.hpp"


/*!
 * \brief The TreeModel class
 * Overridden QAbstractItemModel
 * Provides tree model for qt tree view
 */
class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

private:
    /*!
     * \brief Converts paths to tree model.
     * \param lines[in] String list of file paths.
     * \param parent[out] Treeitem to apply model.
     */
    void setupModelData(
        const QList<FileInfo> &files,
        TreeItem *parent);

    /*! Root item of tree model.*/
    TreeItem *rootItem;

public:
    /*!
     * \brief Constructor, creates _root node, calls setupModelData
     * \param data[in] Data for constructing tree.
     * \param parent[in] Parent object.
     */
    explicit TreeModel(
        const QList<FileInfo> &data,
        QObject *parent = nullptr);

    /*! Destructor, deletes root */
    ~TreeModel();

    /*! Overrided system QAbstractItemModel function.*/
    QVariant data(const QModelIndex &index, int role) const override;
    /*! Overrided system QAbstractItemModel function.*/
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    /*! Overrided system QAbstractItemModel function.*/
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    /*! Overrided system QAbstractItemModel function.*/
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    /*! Overrided system QAbstractItemModel function.*/
    QModelIndex parent(const QModelIndex &index) const override;
    /*! Overrided system QAbstractItemModel function.*/
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /*! Overrided system QAbstractItemModel function.*/
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
};

#endif // TREEMODEL_HPP
