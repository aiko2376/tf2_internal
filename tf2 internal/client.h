#pragma once

class c_client {
	void resolve_user( );
public:
	const char* m_user = "\x90\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
	bool m_unloading = false;
	bool m_debug_build = false;

	void init( );
	void unload( );
}; inline c_client g_cl;