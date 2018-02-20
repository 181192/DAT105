//
// Created by k on 17.02.18.
//

#ifndef LAB4_LISTADT_H
#define LAB4_LISTADT_H


template<class T>
class ListADT {
public:
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
    virtual T *find() = 0;

    /**
    * Remove the first occurrence of the given value in the list
    * and return a pointer to the element.
    */
    virtual T *remove() = 0;

    /**
    * return a pointer to the first node in the list.
    */
    virtual T *first() = 0;

    /**
    * Return a pointer to the last node in the list.
    */
    virtual T *last() = 0;

    /**
    * Return true if the given value is found in the list,
    * false otherwise.
    */
    virtual bool contains() = 0;

    /**
    * Return true if the list is empty, false otherwise.
    */
    virtual bool isEmpty() = 0;

    /**
    * Return the number of elements in the list.
    */
    virtual int size();

};


#endif //LAB4_LISTADT_H
