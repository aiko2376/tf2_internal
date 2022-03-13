#include "sdk.h"

void __fastcall paint( std::uintptr_t ecx, std::uintptr_t edx, paint_mode_t mode ) {
	g_hooks.m_original.paint( ecx, edx, mode );
}

void c_hooks::init( ) {
	MH_Initialize( );
	MH_CreateHook( c_utils::get_virtual_function<void*>( g_interfaces.m_engine_vgui, e_indexes::PAINT ), paint, reinterpret_cast< void** >( &this->m_original.paint ) );
	MH_EnableHook( MH_ALL_HOOKS );
}

void c_hooks::unload( ) {
	MH_DisableHook( MH_ALL_HOOKS );
	MH_RemoveHook( MH_ALL_HOOKS );
	MH_Uninitialize( );
}