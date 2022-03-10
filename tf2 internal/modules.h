#pragma once

// forward decl.
class interface_reg;
enum e_console_colors;

struct interface_t {
	const char* m_name;
	unsigned int m_hash;
	uintptr_t* m_ptr;

	template < typename T >
	T* as( ) {
		return reinterpret_cast< T* >( this );
	}
};

struct module_t {
private:
	interface_t get_interface_exact( const char* name );
public:
	const char* m_name;
	HMODULE m_module;
	unsigned int m_hash;
	std::deque< interface_t > m_interfaces;

	template < typename T >
	T get_proc_address( const char* proc ) {
		auto proc_addr = reinterpret_cast< T >( GetProcAddress( this->m_module, proc ) );

		if ( !proc_addr ) {
			printf_s( _( "failed to get %s (%s)\n" ), proc, this->m_name );
		}

		return proc_addr;
	}

	void populate_interfaces( uint8_t* reg );
	interface_t get_interface( const char* name, bool exact = false );
};


class c_modules {
	std::deque< module_t > modules_;
public:
	void init( );
	module_t get( const char* name );
	void add( const char* name, bool populate_ifaces = true );
}; inline c_modules g_modules;