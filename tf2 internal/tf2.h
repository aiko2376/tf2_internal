#pragma once

class c_tf2 {
public:
	struct {
		HMODULE client;
	} m_modules;

	void init( );
}; inline c_tf2 g_tf2;