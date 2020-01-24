Description of the API created for CS4500 Assignment 1: Part 2

object.h: This is the class that all objects will derive from.
There are no fields, and there is a constructor, destructor, an "equals" method,
and a "hash" method. The destructor, equals, and hash methods are all virtual
because they will vary based on the object that inherits this class.

array.h: This is the class that represents arrays. It's parent class is Object
The class has two fields: length and list.
Length is a size_t that represents the length of the array.
List is an Object pointer that represents an array of objects.
We made the "list" field as an object array because we wanted it to be able to
store any kind of object instead of something specific.
The class has a constructor, a copy constructor, and a constructor that just
takes in a length. The class also has a destructor.
The methods we decided to include as the API include:
    size() - returns a the length of the list. We decided to include this so you
    don't have to directly access the length field which could be dangerous.
    set(size_t i, Object* o) - which replaces the object in the index "i" in the list
    array with the object given
    remove(size_t i) - removes the object at the index "i"
    index_of(Object* o) - returns the index in which the object given appears
    hash() - returns a hash of the array
    get(size_t i) - returns the object stored in the index "i" in the field
    "list"
    equals(Object* o) - returns whether or not this list and the list given are
    equal
    clear() - acts as a destructor for the array and destroys all the objects in
    "list"
    add(size_t i, Object* o) - adds the object given into the array at index
    "i". It will also push all the objects that were to the right of "i" back
    one.
    push_back(Object* o) - adds the object given to the end of the array

we decided not to add a resize method as we deemed that should be automatically
done as a "private" method. (we also realize there are no private methods in
CwC). resizing the array should not be apart of the API.

These methods all take in Objects because we wanted it to be general so that any
object can be put into an array!
