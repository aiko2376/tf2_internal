#include "../../sdk/sdk.h"

void c_client::init( ) {
	MH_Initialize( );

	//hook code here


	MH_EnableHook( MH_ALL_HOOKS );
}

void c_client::unload( ) {
	MH_Uninitialize( );
	MH_DisableHook( MH_ALL_HOOKS );

#ifdef _DEBUG
	FreeConsole( );
#endif
}