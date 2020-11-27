#include "test.h"

#include <str.h> // MULTIPLE INCLUDES OKAY.
#include <str.h>
#include <str.h>
#include <str.h>

#define P
#define T int
#include <stk.h>

typedef const char* charp;
#define P
#define T charp
#define U int
#include <map.h>

#define P
#define T int
#define U int
#include <map.h>

#define P
#define T int
#include <pqu.h>

#define P
#define T int
#include <que.h>

#define P
#define T int
#include <lst.h>

#define P
#define T int
#include <deq.h>

#define P
#define T int
#include <set.h>

#define P
#define T char
#include <vec.h>

#define P
#define T int
#include <vec.h>

#define P
#define T unsigned
#include <vec.h>

#define P
#define T float
#include <vec.h>

#define P
#define T double
#include <vec.h>

typedef struct
{
    int x;
    int y;
}
point;

#define P
#define T point
#include <vec.h>

#define T str
#include <vec.h>

typedef struct
{
    vec_point path;
    str name;
}
person;

static person
person_init(size_t path_capacity, const char* first, const char* last)
{
    person self;
    self.path = vec_point_init();
    self.name = str_create(first);
    str_append(&self.name, " ");
    str_append(&self.name, last);
    vec_point_reserve(&self.path, path_capacity);
    return self;
}

static person
person_init_default(void)
{
    return person_init(0, "NONE", "NONE");
}

static void
person_free(person* self)
{
    vec_point_free(&self->path);
    str_free(&self->name);
}

static person
person_copy(person* self)
{
    person copy = {
        vec_point_copy(&self->path),
        str_copy(&self->name),
    };
    return copy;
}

#define T person
#include <vec.h>

static int
int_match(int* a, int* b)
{
    return *a == *b;
}

static int
int_compare(int* a, int* b)
{
    return *a < *b;
}

static int
int_key_compare(int* a, int* b)
{
    return (*a == *b) ? 0 : (*a < *b) ? -1 : 1;
}

static int
charp_key_compare(charp* a, charp* b)
{
    return strcmp(*a, *b);
}

static int
is_value_2(int* key, int* value)
{
    (void) key;
    return *value == 2;
}

int
main(void)
{
    {
        vec_int a = vec_int_init();
        vec_int_push_back(&a, 1);
        vec_int_push_back(&a, 2);
        vec_int_push_back(&a, 3);
        vec_int_push_back(&a, 4);
        vec_int_free(&a);
    }{
        map_charp_int a = map_charp_int_create(charp_key_compare);
        map_charp_int_insert(&a, "C", 93);
        map_charp_int_insert(&a, "B", 92);
        map_charp_int_insert(&a, "D", 94);
        map_charp_int_insert(&a, "A", 91);
        map_charp_int_insert(&a, "AA", 91);
        map_charp_int_insert(&a, "AAA", 91);
        map_charp_int_insert(&a, "E", 94);
        map_charp_int_insert(&a, "G", 94);
        map_charp_int_insert(&a, "F", 94);
        map_charp_int_free(&a);
    }{
        map_int_int a = map_int_int_create(int_key_compare);
        map_int_int_insert(&a, 1, 1);
        map_int_int_insert(&a, 4, 1);
        map_int_int_insert(&a, 8, 2);
        map_int_int_insert(&a, -1, 2);
        map_int_int_insert(&a, -3, 2);
        map_int_int_insert(&a, -2, 2);
        map_int_int_insert(&a, 2, 2);
        map_int_int_insert(&a, 21, 2);
        map_int_int_insert(&a, 3, 1);
        map_int_int_insert(&a, 9, 1);
        map_int_int_insert(&a, -21, 2);
        map_int_int_insert(&a, -4, 2);
        map_int_int_remove_if(&a, is_value_2);
        map_int_int_free(&a);
    }{
        const size_t size = 16;
        deq_int a = deq_int_init();
        for(size_t i = 0; i < size; i++) deq_int_push_back(&a, i);
        for(size_t i = 0; i < size; i++) deq_int_push_front(&a, i);
        deq_int_insert(&a, deq_int_begin(&a) + 1, 99);
        deq_int_sort(&a, int_compare);
        deq_int_free(&a);
    }{
        lst_int a = lst_int_init();
        lst_int_push_back(&a, 1);
        lst_int_push_back(&a, 2);
        lst_int_push_back(&a, 3);
        lst_int_push_back(&a, 4);
        lst_int_push_back(&a, 5);
        lst_int_push_back(&a, 6);
        lst_int_push_back(&a, 7);
        lst_int_push_back(&a, 8);
        lst_int_free(&a);
    }{
        vec_str b = vec_str_init();
        vec_str_push_back(&b, str_create("This"));
        vec_str_push_back(&b, str_create("is"));
        vec_str_push_back(&b, str_create("a"));
        vec_str_push_back(&b, str_create("test"));
        vec_str_resize(&b, 512);
        vec_str_free(&b);
    }{
        vec_person c = vec_person_init();
        vec_person_push_back(&c, person_init(128, "FIRST", "JONES"));
        vec_person_push_back(&c, person_init(256, "LAST", "ALEXA"));
        vec_person_push_back(&c, person_init(512, "NAME", "ANOTHER"));
        vec_person d = vec_person_copy(&c);
        vec_person_free(&c);
        vec_person_free(&d);
    }{
        lst_int a = lst_int_init();
        lst_int_push_back(&a, 1);
        lst_int_push_back(&a, 1);
        lst_int_push_back(&a, 1);
        lst_int_push_back(&a, 2);
        lst_int_push_back(&a, 3);
        lst_int_push_back(&a, 3);
        lst_int_push_back(&a, 4);
        lst_int_push_back(&a, 6);
        lst_int_push_back(&a, 6);
        lst_int_push_back(&a, 6);
        lst_int_push_back(&a, 6);
        lst_int_push_back(&a, 6);
        lst_int_push_back(&a, 8);
        lst_int_push_back(&a, 8);
        lst_int_unique(&a, int_match);
        lst_int_free(&a);
    }
    TEST_PASS(__FILE__);
}
