#include "sdk.h"

vector& c_base_entity::m_vec_origin( ) {
	return this->get< vector >( g_netvars.m_offsets.dt_base_entity.m_vec_origin );
}

int& c_base_entity::m_i_team_num( ) {
	return this->get< int >( g_netvars.m_offsets.dt_base_entity.m_i_team_num );
}