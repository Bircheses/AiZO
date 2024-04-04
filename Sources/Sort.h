#ifndef AIZO_SORT_H
#define AIZO_SORT_H

/**
 * Abstract Sort class for saving, deleting and showing table
 */
class Sort {
private:
    int* tabCopy = nullptr;
    int tabSize = 0;
public:
    virtual void printTab();
    virtual void deleteTab();
    template<typename T> T *getTabCopy();
    template<typename T> void setTabCopy(const T *tab);
    [[nodiscard]] int getTabSize() const;
    virtual void setTabSize(int size);
    template<typename T> void swap(T *a, T *b);
};

#endif