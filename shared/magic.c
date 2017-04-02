// from old fragile (bits and pieces likely to break with any new Pd version.)
// and forky

#include "m_pd.h"
#include "magic.h"
#include <string.h> // needed?
// from forky
#include "g_canvas.h" // needed?
#include "shared.h" // needed?

struct _outlet // local to m_obj.c.
{
    t_object *o_owner;
    struct _outlet *o_next;
    t_outconnect *o_connections;
    t_symbol *o_sym;
};
/* LATER export write access to o_connections field ('grab' class).
LATER encapsulate 'traverseoutlet' routines (not in the stable API yet). */


t_outconnect *magic_outlet_connections(t_outlet *o) // obj_starttraverseoutlet() replacement
    {
    return (o ? o->o_connections : 0);
    }

t_outconnect *magic_outlet_nextconnection(t_outconnect *last, t_object **destp, int *innop)
    {
    t_inlet *dummy;
    return (obj_nexttraverseoutlet(last, destp, &dummy, innop));
    }

int magic_inlet_connection(t_object *x, t_glist *glist, int inno, t_symbol *outsym)
{
    t_linetraverser t;
    linetraverser_start(&t, glist);
    while (linetraverser_next(&t))
        if (t.tr_ob2 == x && t.tr_inno == inno &&
            (!outsym || outsym == outlet_getsymbol(t.tr_outlet)))
        return (1);
    return (0);
}