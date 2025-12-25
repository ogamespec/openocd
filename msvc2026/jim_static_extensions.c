#include "jim.h"

int Jim_InitStaticExtensions(Jim_Interp* interp)
{
	extern int Jim_bootstrapInit(Jim_Interp*);
	extern int Jim_aioInit(Jim_Interp*);
	extern int Jim_readdirInit(Jim_Interp*);
	extern int Jim_regexpInit(Jim_Interp*);
	extern int Jim_fileInit(Jim_Interp*);
	extern int Jim_globInit(Jim_Interp*);
	extern int Jim_execInit(Jim_Interp*);
	extern int Jim_clockInit(Jim_Interp*);
	extern int Jim_arrayInit(Jim_Interp*);
	extern int Jim_stdlibInit(Jim_Interp*);
	extern int Jim_tclcompatInit(Jim_Interp*);
	//Jim_bootstrapInit(interp);
	Jim_aioInit(interp);
	Jim_readdirInit(interp);
	//Jim_regexpInit(interp);
	Jim_fileInit(interp);
	//Jim_globInit(interp);
	Jim_execInit(interp);
	Jim_clockInit(interp);
	Jim_arrayInit(interp);
	//Jim_stdlibInit(interp);
	//Jim_tclcompatInit(interp);
	return JIM_OK;
}