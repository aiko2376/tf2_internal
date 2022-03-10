#pragma once

class c_interfaces {
	void gather( );
	void add( module_t mod, const char* name );
public:
	void init( );

	i_base_client_dll* m_client;
}; inline c_interfaces g_interfaces;