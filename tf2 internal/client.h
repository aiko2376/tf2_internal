#pragma once

class c_client {
public:
	const char* m_user = "user";
	bool m_unloading = false;
	bool m_debug_build = true;

	void init( );
	void unload( );
}; inline c_client g_cl;