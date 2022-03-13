#include "sdk.h"

void c_offsets::init( ) {
	auto vgui_mat_surface = g_modules.get( _( "vguimatsurface.dll" ) ); {
		// x-ref "-pixel_offset_x".
		this->m_sigs.start_drawing = vgui_mat_surface.get_sig( _( "55 8B EC 64 A1 00 00 00 00 6A FF 68 6C B2 0C 10" ) ).m_ptr;

		// x-ref "Too many popups! Rendering will be bad!"
		this->m_sigs.finish_drawing = vgui_mat_surface.get_sig( _( "55 8B EC 6A FF 68 DC B1 0C 10 64 A1 00 00 00 00 50" ) ).m_ptr;
	}
}