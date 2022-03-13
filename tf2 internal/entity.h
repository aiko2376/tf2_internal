#pragma once

class i_client_entity {
public:
	virtual void release( void ) = 0;
	virtual const vector& get_abs_origin( void ) const = 0;
	virtual const vector& get_abs_angles( void ) const = 0;
	virtual c_mouth_info* get_mouth( void ) = 0;
	virtual bool get_sound_spatialization( spatialization_info_t& info ) = 0;
};

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