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

			this->m_netvars.emplace_back( g_utils.fnv_hash( table->m_net_table_name ), g_utils.fnv_hash( prop.m_var_name ), prop.m_offset );
		}

		cc = cc->m_next;
	}

	g_utils.m_debug.set_console_color( e_console_colors::console_color_cyan );
	printf_s( _( "populated %i netvars\n" ), this->m_netvars.size( ) );

	// get our offsets.
	this->get_offsets( );
}

netvar_t c_netvars::get( const char* table, const char* var ) {
	auto hashed_table = g_utils.fnv_hash( table );
	auto hashed_var = g_utils.fnv_hash( var );

	for ( auto& netvar : this->m_netvars ) {
		// not the table we want.
		if ( netvar.m_hashed_table != hashed_table )
			continue;

		// not the var we want.
		if ( netvar.m_hashed_var != hashed_var )
			continue;

		return netvar;
	}
}

void c_netvars::get_offsets( ) {
	this->m_offsets.dt_base_entity.m_vec_origin = this->get( _( "DT_BaseEntity" ), _( "m_vecOrigin" ) ).m_offset;
	this->m_offsets.dt_base_entity.m_i_team_num = this->get( _( "DT_BaseEntity" ), _( "m_iTeamNum" ) ).m_offset;
}