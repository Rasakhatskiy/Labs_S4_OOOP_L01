#include "treemodel.hpp"

void TreeModel::setupModelData(
    const QList<FileInfo> &files,
    TreeItem *parent)
{
    for(auto &fileInfo : files)
    {
        auto subStrings = fileInfo.getFullpath().split("/");
        auto current = rootItem;
        for (int i = 0; i < subStrings.size() - 1; ++i)
        {
            auto index = current->findChildrenData(subStrings[i]);
            if (index >= 0)
            {
                current = current->getChild(index);
                continue;
            }
            else
            {
                QString empty = "";
                QVector<QVariant> data(
                {
                    subStrings[i],
                    empty,
                    empty,
                    empty,
                    "Dir",
                    empty
                });
                auto child = new TreeItem(data, current);
                current->appendChild(child);
                current = child;
                continue;
            }
        }
        QVector<QVariant> data(
        {
            subStrings[subStrings.size() - 1],
            QString::number(fileInfo.getLength() / 1024) + " KB",
            fileInfo.getDateOfCreation().toString(),
            fileInfo.getDateOfModification().toString(),
            fileInfo.isDir() ? "Dir" :
            fileInfo.isFile() ? "File" :
            fileInfo.isSymLink() ? "Link" :
            "Undefined",
            fileInfo.getSymlinkPath()
        });
        auto child = new TreeItem(data, current);
        current->appendChild(child);
        current = child;
    }
}

TreeModel::TreeModel(
    const QList<FileInfo> &data,
    QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new TreeItem({
        tr("Title"),
        tr("Size"),
        tr("Creation date"),
        tr("Modification date"),
        tr("Type"),
        tr("Link path")});

    setupModelData(data, rootItem);
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->getChild(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->getParent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->getCurrentRow(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->getChildrenCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->getDataCount();
    return rootItem->getDataCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->getData(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->getData(section);

    return QVariant();
}
