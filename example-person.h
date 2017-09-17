#ifndef EXAMPLE_PERSON_H
#define EXAMPLE_PERSON_H

#include <glib-object.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE_PERSON (example_person_get_type())

G_DECLARE_FINAL_TYPE (ExamplePerson, example_person, EXAMPLE, PERSON, GObject)

G_END_DECLS

#endif /* EXAMPLE_PERSON */
