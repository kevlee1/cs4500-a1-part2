//lang::CwC
//object class for assignment 1 - part 2
// maintained by: <lee.kev@husky.neu.edu, vullo.b@husky.neu.edu>

class Object {
    public:
        Object() {}
        virtual ~Object() {}
        // Determines if two objects are equal
        virtual bool equals(Object *o) {}
        // outputs a hash of the object
        virtual size_t hash() {}
};

