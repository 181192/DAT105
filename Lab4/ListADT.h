//
// Created by k on 17.02.18.
//

#ifndef LAB4_LISTADT_H
#define LAB4_LISTADT_H

template<class T>
class ListADT {
public:
    /**
     * Adding a new element first in the list and returning a bool.
     * @param element The new element
     * @return True if OK, else false
     */
    virtual void addFirst(T *element) = 0;

    /**
     * Adding a new element to the end of the list and returning a bool.
     * @param element The new element
     * @return True if OK, else false
     */
    virtual void addLast(T *element) = 0;

    /**
    * Remove the first element in the list
    * and return a pointer to the element.
    */
    virtual T *removeFirst() = 0;

    /**
    * Remove the last element in the list
    * and return a pointer to the element.
    */
    virtual T *removeLast() = 0;

    /**
    * Return a pointer to the first occurrence of the given
    * value in the list.
    */
    virtual T *find(T *element) = 0;

    /**
    * Remove the first occurrence of the given value in the list
    * and return a pointer to the element.
    */
    virtual T *remove(T *element) = 0;

    /**
    * return a pointer to the first element in the list.
    */
    virtual T *getFirst() = 0;

    /**
    * Return a pointer to the last element in the list.
    */
    virtual T *getLast() = 0;

    /**
    * Return true if the given value is found in the list,
    * false otherwise.
    */
    virtual bool contains(T *element) = 0;

    /**
    * Return true if the list is empty, false otherwise.
    */
    virtual bool isEmpty() = 0;

    /**
    * Return the number of elements in the list.
    */
    virtual int size() = 0;

};


#endif //LAB4_LISTADT_H
