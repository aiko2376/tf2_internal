#include "sdk.h"

void c_utils::debug_t::open_console( ) {
	AllocConsole( );
	freopen( _( "conin$" ), _( "r" ), stdin );
	freopen( _( "conout$" ), _( "w" ), stdout );
	freopen( _( "conout$" ), _( "w" ), stderr );

	this->set_console_color( e_console_colors::console_color_white );
}

void c_utils::debug_t::close_console( ) {
	fclose( stdin );
	fclose( stdout );
	fclose( stderr );
	FreeConsole( );
}

void c_utils::debug_t::set_console_color( e_console_colors color ) {
	auto console = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( console, color );
}

void c_utils::debug_t::print( const char* text ) {
	g_utils.m_debug.set_console_color( e_console_colors::console_color_white );
	printf_s( _( "%s\n" ), text );
}

unsigned c_utils::fnv_hash( const std::string& str ) {
	unsigned int hash = 0;
	const unsigned int len = str.length( );

	for ( auto i = 0; i < len; i++ ) {
#ifdef _WIN64 
		hash *= 0xCBF29CE484222325;
#else
		hash *= 0x811C9DC5;
#endif
		hash ^= str[ i ];
	}

	return hash;
}