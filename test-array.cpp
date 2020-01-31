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
void test4() {
    Array* a = new Array(10);
    Array* b = new Array(10);
    Array* c = new Array(10);
    Array* d = new Array(10);
    Integer* x = new Integer(10);
    Integer* y = new Integer(9);
    Bool* t = new Bool(true);
    Bool* f = new Bool(false);
    Float* u = new Float(1.0);
    Float* r = new Float(2.0);

    a->push_back(x);
    a->add(1, y);
    t_true(a->get(0)->equals(x));
    t_true(a->get(1)->equals(y));

    b->push_back(t);
    b->add(1, f);
    t_true(b->get(0)->equals(t));
    t_true(b->get(1)->equals(f));

    c->push_back(u);
    c->add(1, r);
    t_true(c->get(0)->equals(u));
    t_true(c->get(1)->equals(r));
    c->set(1, u);
    t_true(c->get(1)->equals(u));
    
    d->push_back(x);
    d->add(1, y);

    t_false(a->equals(c));
    t_true(a->equals(d));

    t_true(d->size() == 2);
    OK("TEST 4");
}
void test5() {
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Array* a = new Array();
    a->push_back(o1);
    a->push_back(o2);
    t_true(a->get(0)->equals(o1));
    t_true(a->get(1)->equals(o2));
    t_true(a->size() == 2); 
    a->set(o3, 0);
    t_true(a->get(0)->equals(o3));
    a->clear();
    t_true(a->size() == 0);
    OK("TEST 5");
}
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
