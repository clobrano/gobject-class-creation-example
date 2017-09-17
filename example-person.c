#include "example-person.h"

struct _ExamplePerson
{
  GObject parent_object;

  gchar *name;
};

/* This declares typedef struct _ExamplePerson ExamplePerson */
G_DEFINE_TYPE (ExamplePerson, example_person, G_TYPE_OBJECT);

enum
{
  PROP_0,
  PROP_NAME,
  PROP_LAST
};

static void
example_person_get_property (GObject *object,
                             guint prop_id,
                             GValue *value,
                             GParamSpec *properties)
{
  ExamplePerson *self = (ExamplePerson *) object;

  switch (prop_id)
    {
    case PROP_NAME:
      g_value_set_string (value, example_person_get_name (self));
      break;
    }
}

static void
example_person_set_property (GObject *object,
                             guint prop_id,
                             const GValue *value,
                             GParamSpec *properties)
{
  ExamplePerson *self = (ExamplePerson *) object;

  switch (prop_id)
    {
    case PROP_NAME:
      example_person_set_name (self, g_value_get_string (value));
      break;
    }
}

static GParamSpec *properties [PROP_LAST];

/* class initializer, called only once */
static void
example_person_class_init (ExamplePersonClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = example_person_get_property;
  object_class->set_property = example_person_set_property;

  properties [PROP_NAME] =
    g_param_spec_string ("name",
                         "Name",
                         "Example Person's name",
                         NULL,
                         (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_properties (object_class, PROP_LAST, properties);
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
