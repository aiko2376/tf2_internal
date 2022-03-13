#pragma once

// forward decl.
class i_client_entity;
class c_base_entity;

// todo: remove once impl.
class i_collideable;
class i_client_renderable;
class i_client_thinkable;
class i_client_thinkable;

class i_client_unknown : public i_handle_entity {
public:
	virtual i_collideable* get_collideable( ) = 0;
	virtual i_client_networkable* get_client_networkable( ) = 0;
	virtual i_client_renderable* get_client_renderable( ) = 0;
	virtual i_client_entity* get_i_client_entity( ) = 0;
	virtual c_base_entity* get_base_entity( ) = 0;
	virtual i_client_thinkable* get_client_thinkable( ) = 0;
};

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