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
    Array* a = new Array();
    Array* b = new Array();
    Array* c = new Array();
    int x = 10;
    int y = 9;
    bool t = true;
    bool f = false;
    bool t1 = true;
    bool f1 = false;
    float u = 1.0;
    float r = 2.0;
    float s = 3.0;
    
    a->push_back(x);
    a->add(1, y);
    t_true(a->get(0)->equals(x));
    t_true(a->index_of(y) == 1);

    b->push_back(t);
    b->add(1, f);
    t_true(b->get(0)->equals(t));
    t_true(b->index_of(f) == 1);

    c->push_back(u);
    c->add(1, r);
    t_true(c->get(0)->equals(u));
    t_true(c->index_of(r) == 1);
}
int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
