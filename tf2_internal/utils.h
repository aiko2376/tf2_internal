#pragma once

class c_utils {
	typedef void* ( *create_interface_fn )( const char* name, int return_code );
public:
	__forceinline static uintptr_t* get_interface( const char* mod, const char* name ) {
		const auto create_interface = reinterpret_cast< create_interface_fn >( GetProcAddress( GetModuleHandle( mod ), "CreateInterface" ) );
		return static_cast< uintptr_t* >( create_interface( name, 0 ) );
	}
}; inline c_utils g_utils;