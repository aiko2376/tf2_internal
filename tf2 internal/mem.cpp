#include "sdk.h"

// ugh... i borrow this a LONG time ago (5-6 years ago) and i can't remember who from
// sorry..
std::uint8_t* c_mem::get_sig( module_t mod, const char* signature ) {
	if ( !mod.m_module )
		return nullptr;

	this->m_sigs_scanned++;

	static auto pattern_to_byte = [ ]( const char* pattern ) {
		auto bytes = std::vector< int >{ };
		const auto start = const_cast< char* >( pattern );
		const auto end = const_cast< char* >( pattern ) + std::strlen( pattern );

		for ( auto current = start; current < end; ++current ) {
			if ( *current == '?' ) {
				++current;

				if ( *current == '?' )
					++current;

				bytes.push_back( -1 );
			}
			else {
				bytes.push_back( std::strtoul( current, &current, 16 ) );
			}
		}
		return bytes;
	};

	const auto dos_header = reinterpret_cast< PIMAGE_DOS_HEADER >( mod.m_module );
	const auto nt_headers = reinterpret_cast< PIMAGE_NT_HEADERS >( reinterpret_cast< std::uint8_t* >( mod.m_module ) + dos_header->e_lfanew );

	const auto size_of_image = nt_headers->OptionalHeader.SizeOfImage;
	auto pattern_bytes = pattern_to_byte( signature );
	const auto scan_bytes = reinterpret_cast< std::uint8_t* >( mod.m_module );

	const auto s = pattern_bytes.size( );
	const auto d = pattern_bytes.data( );

	for ( auto i = 0ul; i < size_of_image - s; ++i ) {
		auto found = true;

		for ( auto j = 0ul; j < s; ++j ) {
			if ( scan_bytes[ i + j ] != d[ j ] && d[ j ] != -1 ) {
				found = false;
				break;
			}
		}

		if ( found ) {
			auto addr = &scan_bytes[ i ];

			g_utils.m_debug.set_console_color( e_console_colors::console_color_green );
			printf_s( _( "sig %i success\n" ), this->m_sigs_scanned );

			return addr;
		}
	}

	g_utils.m_debug.set_console_color( e_console_colors::console_color_red );
	printf_s( _( "failed to find sig %i\n" ), this->m_sigs_scanned );

	return nullptr;
}