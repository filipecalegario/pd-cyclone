#define CYCLONE_MAGIC_NAN 0x7FFFFFFFul
#define CYCLONE_MAGIC_INF 0x7F800000ul
#define CYCLONE_MAGIC_NEGATIVE_INF 0xFF800000ul

/*This is a public function that returns float fields. It is not declared in m_pd.h,
so we have to declare it here. The arguments are the object and the inlet number
(indexed from zero)*/
EXTERN t_float *obj_findsignalscalar(t_object *x, int m);
/*end magic*/

/*int-float unions*/
//~ union i32_fl {
	//~ int32_t if_int32;
	//~ t_float if_float;
//~ };

union magic_ui32_fl {
	uint32_t uif_uint32;
	t_float uif_float;
};

void magic_setnan (t_float *in);
int magic_isnan (t_float in);
int magic_isinf (t_float in);




// from old fragile (bits and pieces likely to break with any new Pd version.)

t_outconnect *magic_outlet_connections(t_outlet *o);
t_outconnect *magic_outlet_nextconnection(t_outconnect *last, t_object **destp, int *innop);

// from forky
int magic_inlet_connection(t_object *x, t_glist *glist, int inno, t_symbol *outsym);

