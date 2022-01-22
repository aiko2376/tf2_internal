#pragma once

class c_utils {
	using create_interface_fn = void*(__cdecl*)( const char* name, int return_code );
public:
	__forceinline static uintptr_t* get_interface( const char* mod, const char* name ) {
		static auto create_interface = reinterpret_cast< create_interface_fn >( GetProcAddress( GetModuleHandle( mod ), "CreateInterface" ) );
		return static_cast< uintptr_t* >( create_interface( name, 0 ) );
	}

	template <typename ...v_args>
	void log(const char* fmt,v_args const& ...args )
	{
		printf( fmt, args... );
	}


}; inline c_utils g_utils;