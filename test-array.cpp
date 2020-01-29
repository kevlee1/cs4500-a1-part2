//lang::CwC
// test file for assignment 1 - part 2
// maintained by <lee.kev@husky.neu.edu, vullo.b@husky.neu.edu>
#include <stdio.h>
#include "array.h"
#include "string.h"
void FAIL() {
    exit(1);
}

void OK(const char* m) {
    printf("%s\n", m);
}

void t_true(bool p) {
    if (!p) FAIL();
}
void t_fail(bool p) {
    if (p) FAIL();
}
// tests:
// initializing Array
// adding Strings to array
// Array::add
// Array::push_back
// Array::clear
// Array::size
void test1() {
    String* s = new String("Hello");
    String* t = new String("World");
    Array* a = new Array();
    a->add(0 ,s);
    a->push_back(t);
    t_true(a->get(0)->equals(s));
    t_true(a->get(1)->equals(t));
    a->clear();
    size_t length;
    length = a->size();
    t_true(length == 0);
    OK("TEST 1");
}
// tests:
// Array::equals
// Array::hash
void test2() {
    String* s = new String("Hello");
    String* t = new String("World");
    Array* a = new Array();
    a->add(0, s);
    a->add(1, t);
    Array* b = new Array();
    b->push_back(s);
    b->push_back(t);
    t_true(a->equals(b));
    t_true(b->equals(a));
    t_true(a->hash() == b->hash());
    OK("TEST 2");
}

// tests:
// Array::get
// Array::index_of
// Array::remove
// Array::set
void test3() {
    Object* s = new String("Hello");
    Object* t = new String("World");
    Array* a = new Array();
    a->add(0, s);
    a->add(1, t);
    t_true(a->get(0)->equals(s));
    t_true(a->index_of(s) == 0);
    Object* u = new String("!");
    a->set(1, u);
    t_true(a->get(1)->equals(u));
    a->remove(1);
    t_true(a->size() == 1);
    OK("TEST 3");
}
int main() {
    test1();
    test2();
    test3();
    return 0;
}
