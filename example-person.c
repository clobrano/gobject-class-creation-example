#include "example-person.h"

struct _ExamplePerson
{
  GObject parent_object;
};

/* This declares typedef struct _ExamplePerson ExamplePerson */
G_DEFINE_TYPE (ExamplePerson, example_person, G_TYPE_OBJECT);

/* class initializer, called only once */
static void
example_person_class_init (ExamplePersonClass *klass)
{

}

/* instance initializer */
static void
example_person_init (ExamplePerson *self)
{

}
