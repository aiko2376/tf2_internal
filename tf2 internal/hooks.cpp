#include "sdk.h"

void __fastcall paint( uintptr_t ecx, uintptr_t edx, paint_mode_t mode ) {
	if ( g_cl.m_unloading )
		return g_hooks.m_original.paint( ecx, edx, mode );

	g_hooks.m_original.paint( ecx, edx, mode );

	g_interfaces.m_surface->start_drawing( ); {

	} g_interfaces.m_surface->finish_drawing( );
}

void c_hooks::init( ) {
	MH_Initialize( );
	this->hook( paint, g_interfaces.m_engine_vgui, e_indexes::PAINT, &this->m_original.paint );
	MH_EnableHook( MH_ALL_HOOKS );
}

void c_hooks::unload( ) {
	MH_DisableHook( MH_ALL_HOOKS );
	MH_RemoveHook( MH_ALL_HOOKS );
	MH_Uninitialize( );
}

void c_hooks::hook( void* func, void* iface, int index, void* original ) {
	auto status = MH_CreateHook( c_utils::get_virtual_function<void*>( iface, index ), func, reinterpret_cast< void** >( original ) );

	if ( status != MH_STATUS::MH_OK ) {
		g_utils.m_debug.set_console_color( e_console_colors::console_color_red );
		printf_s( _( "failed to hook (index %i)\n" ), index );
	}
}

void c_hooks::hook( void* func, uint8_t* addr, void* original ) {
	auto status = MH_CreateHook( addr, func, reinterpret_cast< void** >( original ) );

	if ( status != MH_STATUS::MH_OK ) {
		g_utils.m_debug.set_console_color( e_console_colors::console_color_red );
		printf_s( _( "failed to hook\n" ) );
	}
}