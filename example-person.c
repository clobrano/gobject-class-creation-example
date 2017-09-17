#include "example-person.h"

struct _ExamplePerson
{
  GObject parent_object;

  gchar *name;
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
  self->name = g_strdup ("");
}

const gchar *
example_person_get_name (ExamplePerson *self)
{
  return self->name;
}

void
example_person_set_name (ExamplePerson *self,
                         const gchar *name)
{
  if (g_strcmp0 (self->name, name) != 0)
    {
      g_free (self->name);
      self->name = g_strdup (name);
    }
}
