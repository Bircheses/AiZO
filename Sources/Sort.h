#ifndef AIZO_SORT_H
#define AIZO_SORT_H

/**
 * Abstract Sort class, parent of all sorting classes
 */
template <typename T>
class Sort {
private:
    T *tabCopy = nullptr; //Copy of a given array
    int tabSize = 0; //Size of a given array
public:
    virtual bool isSortCorrect(); //Function that checks if sorting was correct
    virtual void printTab(); //Function that prints out array
    virtual void deleteTab(); //Function that deletes copy of array
    T *getTabCopy(); //Function that returns tabCopy
    virtual void setTabCopy(const T *tab); //Function that creates array copy of a given array
    [[nodiscard]] int getTabSize() const; //Function that returns size of an array
    virtual void setTabSize(int size); //Function that sets size of array
    void swap(T *a, T *b); //Function that swaps values between to given pointers
};

#endif