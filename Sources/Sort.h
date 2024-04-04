#ifndef AIZO_SORT_H
#define AIZO_SORT_H

/**
 * Abstract Sort class for saving, deleting and showing table
 */
template <typename T>
class Sort {
private:
    T *tabCopy = nullptr;
    int tabSize = 0;
public:
    virtual void printTab();
    virtual void deleteTab();
    T *getTabCopy();
    virtual void setTabCopy(const T *tab);
    [[nodiscard]] int getTabSize() const;
    virtual void setTabSize(int size);
    void swap(T *a, T *b);
};

#endif