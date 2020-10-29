#include "treeitem.hpp"

TreeItem::TreeItem(const QVector<QVariant> &data, TreeItem *parent)
    : _data(data), _parent(parent)
{}

TreeItem::~TreeItem()
{
    qDeleteAll(_children);
}

void TreeItem::appendChild(TreeItem *item)
{
    _children.append(item);
}

TreeItem *TreeItem::getChild(int row)
{
    if (row < 0 ||
        row >= _children.size())
        return nullptr;

    return _children.at(row);
}

QVariant TreeItem::getData(int column) const
{
    if (column < 0 ||
        column >= _data.size())
        return QVariant();
    return _data.at(column);
}

int TreeItem::getChildrenCount() const
{
    return _children.count();
}

int TreeItem::getCurrentRow() const
{
    if (_parent)
        return _parent->_children.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

int TreeItem::getDataCount() const
{
    return _data.count();
}

TreeItem *TreeItem::getParent()
{
    return _parent;
}
