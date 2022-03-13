#pragma once

class c_hooks {
	enum e_indexes {
		PAINT = 13
	};

	void hook( void* func, void* iface, int index, void* original );
	void hook( void* func, uint8_t* addr, void* original );
public:
	struct {
		typedef void( __fastcall* paint_fn )( uintptr_t, uintptr_t, paint_mode_t );
		paint_fn paint;
	} m_original;

	void init( );
	void unload( );
}; inline c_hooks g_hooks;