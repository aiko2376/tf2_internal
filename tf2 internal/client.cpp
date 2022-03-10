#include "sdk.h"

void c_client::init( ) {
	g_utils.m_debug.open_console( );

	g_modules.init( );
	g_tf2.init( );
	g_tier0.warning( _( "init\n" ) );
}

void c_client::unload( ) {
	// let the cheat know we're unloading.
	this->m_unloading = true;

	g_utils.m_debug.close_console( );
}