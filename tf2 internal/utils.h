#pragma once

typedef void* ( *create_interface_fn )( const char* name, int return_code );

enum e_console_colors {
	console_color_white = 15,
	console_color_red = 12,
	console_color_green = 10,
	console_color_cyan = 11
};

class c_utils {
public:
	template < typename T >
	__forceinline static T get_virtual_function( void* base, const std::uint16_t index ) {
		return ( *static_cast< T** >( base ) )[ index ];
	}

	__forceinline static uintptr_t* get_interface( module_t mod, const char* name ) {
		static auto create_interface = mod.get_proc_address< create_interface_fn >( _( "CreateInterface" ) );

		if ( !create_interface ) {
			printf_s( _( "failed to get CreateInterface (%s)" ), mod.m_name );
			return nullptr;
		}

		return static_cast< uintptr_t* >( create_interface( name, 0 ) );
	}

	struct debug_t {
		void open_console( );
		void close_console( );
		void set_console_color( e_console_colors color );
		void print( const char* text );
	} m_debug;

	unsigned fnv_hash( const std::string& str );
}; inline c_utils g_utils;

#define __VFUNC( function_name, index, type, ... ) \
	__forceinline auto function_name { \
		return c_utils::get_virtual_function< type >( this, index )( this, __VA_ARGS__ ); \
	}; \