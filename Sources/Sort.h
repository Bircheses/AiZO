#ifndef AIZO_SORT_H
#define AIZO_SORT_H

/**
 * Abstract Sort class for saving, deleting and showing table
 */
class Sort {
private:
    int* tabCopy;
    int tabSize;
public:
    virtual void printTab();
    virtual void deleteTab();
    int *getTabCopy();
    void setTabCopy(int *tab);
    int getTabSize() const;
    void setTabSize(int tabSize);
};

#endif