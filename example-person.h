#ifndef EXAMPLE_PERSON_H
#define EXAMPLE_PERSON_H

#include <glib-object.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE_PERSON (example_person_get_type())

G_DECLARE_FINAL_TYPE (ExamplePerson, example_person, EXAMPLE, PERSON, GObject)

const gchar *example_person_get_name (ExamplePerson *self);
void         example_person_set_name (ExamplePerson *self, const gchar *name);

G_END_DECLS

#endif /* EXAMPLE_PERSON */
