//lang::CwC
// array class for assignment 1 - part 2
// maintained by <lee.kev@husky.neu.edu, vullo.b@husky.neu.edu>
#pragma once
#include <stdio.h>
#include "object.h"

class Array : public Object {
    public:
        // constructor
        Array() {}
        // copy constructor
        Array(Array* a) {}
        // destructor
        ~Array() {}
        // returns the length of the array
        size_t size() {}
        // replaces the object at index "i" with the object given
        Object* set(size_t i, Object* o) {}
        // removes the object at index "i"
        Object* remove(size_t i) {}
        // returns the index of the object in "list"
        // if the object is not in the list will return a number greater than
        // the length of the array
        size_t index_of(Object* o) {}
        // returns the hash value representing the array
        size_t hash() {}
        // returns the object at index "i" in "list"
        Object* get(size_t i) {}
        // determines if this array is equal to the object given
        // which could be another array
        bool equals(Object* o) {}
        // destroys all the objects in "list"
        void clear() {}
        // adds the object given into the array at index "i".
        // it will also push all the objects that were to the right of "i"
        // back one to make room for the new object.
        void add(size_t i, Object* o) {}
        // adds the object given to the end of the array
        void push_back(Object* o) {}
};
