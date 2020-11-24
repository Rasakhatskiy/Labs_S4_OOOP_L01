#ifndef TREEITEM_HPP
#define TREEITEM_HPP

#include <QVector>
#include <QVariant>

/*!
 * \brief Provides node for constructing tree,
 * that can be applied to tree model.
 */
class TreeItem
{
private:
    /*!
     * \brief Vector of children nodes.
     */
    QVector<TreeItem*> _children;

    /*!
     * \brief Vector of data.
     */
    QVector<QVariant> _data;

    /*!
     * \brief Pointer to parent node.
     */
    TreeItem *_parent;

public:

    /*!
     * Constructor of node.
     * Assigns data and parent node.
     * Assigns parent node to nullptr if not defined.
     * \param[in] data Data of the node.
     * \param[in] parent Parent node of the node.
     */
    explicit TreeItem(
        const QVector<QVariant> &data,
        TreeItem *parent = nullptr);

    /*!
     * \brief Destructor. Deletes all children.
      */
    ~TreeItem();

    /*!
     * \brief Appends child to current node.
     * \param[in] child Child to append.
     */
    void appendChild(TreeItem *child);

    /*!
     * \brief Gets child by index.
     * \param row[in] Index of the child.
     * \return Child on index 'row'.
     */
    TreeItem *getChild(int row);

    /*!
     * \brief Gets data entry by index.
     * \param column[in] Index of the data entry.
     * \return Data entry at index 'column'
     */
    QVariant getData(int column) const;

    /*!
     * \brief Gets number of children.
     * \return Number of children.
     */
    int getChildrenCount() const;

    /*!
     * \brief Gets number of data entries.
     * \return Number of data entries.
     */
    int getDataCount() const;

    /*!
     * \brief Gets index of parent's row with this node.
     * \return Index of parent row with this node.
     */
    int getCurrentRow() const;

    /*!
     * \brief Gets parent of the current node.
     * \return Parent of the current node.
     */
    TreeItem *getParent();

    /*!
     * \brief Checks if children contain data.
     * \param[in] data
     * \return Index of child if found, -1 if not.
     */
    int findChildrenData(const QVariant& data);

};

#endif // TREEITEM_HPP
