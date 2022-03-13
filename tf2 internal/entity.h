#pragma once

class c_base_entity : public i_client_entity {
public:
	// todo: maybe macro this?
	// though some people might complain about macros.
	template < typename T >
	T& get( uintptr_t offset ) {
		return *reinterpret_cast< T* >( reinterpret_cast< uintptr_t >( this ) + offset );
	}

	vector& m_vec_origin( );
	int& m_i_team_num( );
};