#pragma once

class c_tier0 {
	typedef void( __cdecl* generic_msg_fn )( const char* message );

	module_t tier0_module_;
	generic_msg_fn msg_, con_warning_, dev_msg_;
public:
	void init( );
	void msg( const char* text );
	void warning( const char* text );
	void dev_msg( const char* text );
}; inline c_tier0 g_tier0;