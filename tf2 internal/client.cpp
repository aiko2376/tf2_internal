#include "sdk.h"

void c_client::init( ) {
	g_utils.m_debug.open_console( );
	this->resolve_user( );

	g_modules.init( );
	g_tf2.init( );
	g_tier0.warning( _( "init\n" ) );
}

void c_client::resolve_user( ) {
#ifndef _LOADER
	// if loader can't set username, default to admin
	this->m_user = _( "developer" );
	this->m_debug_build = true;
#else
	// todo: communicate with loader to get username (maybe thru headers(????))
	this->m_user = _( "user" );
#endif
}

void c_client::unload( ) {
	// let the cheat know we're unloading.
	this->m_unloading = true;

	g_utils.m_debug.close_console( );
}