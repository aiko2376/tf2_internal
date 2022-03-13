#pragma once

class c_hooks {
	enum e_indexes {
		PAINT = 13
	};
public:
	struct {
		typedef void( __fastcall* paint_fn )( std::uintptr_t, std::uintptr_t, paint_mode_t );
		paint_fn paint;
	} m_original;

	void init( );
	void unload( );
}; inline c_hooks g_hooks;