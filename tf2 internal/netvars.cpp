#include "sdk.h"

void c_netvars::init( ) {
	auto cc = g_interfaces.m_client->get_all_classes( );

	while ( cc ) {
		auto table = cc->m_recv_table;

		// bad table.
		if ( !table )
			continue;

		// go through all our props.
		for ( int i = 0; i < table->m_num_of_props; i++ ) {
			auto& prop = table->m_props[ i ];

			this->m_netvars.emplace_back( table->m_net_table_name, prop.m_var_name, prop.m_offset );
		}

		cc = cc->m_next;
	}

	g_utils.m_debug.set_console_color( e_console_colors::console_color_cyan );
	printf_s( _( "populated %i netvars\n" ), this->m_netvars.size( ) );
}

netvar_t c_netvars::get( const char* table, const char* var ) {
	auto hashed_table = g_utils.fnv_hash( table );
	auto hashed_var = g_utils.fnv_hash( var );
	auto debug_build = g_cl.m_debug_build;

	for ( auto& netvar : this->m_netvars ) {
		// not the table we want.
		if ( g_utils.fnv_hash( netvar.m_table ) != hashed_table )
			continue;

		// not the var we want.
		if ( g_utils.fnv_hash( netvar.m_var ) != hashed_var )
			continue;

		// we found our netvar.
		if ( debug_build ) {
			g_utils.m_debug.set_console_color( e_console_colors::console_color_green );
			printf_s( "%s -> %i\n", var, netvar.m_offset );
		}

		return netvar;
	}

	if ( debug_build ) {
		g_utils.m_debug.set_console_color( e_console_colors::console_color_red );
		printf_s( _( "failed to get %s -> %s\n" ), table, var );
	}
}