#pragma once

class i_client_entity {
public:
	virtual void release( void ) = 0;
	virtual const vector& get_abs_origin( void ) const = 0;
	virtual const vector& get_abs_angles( void ) const = 0;
	virtual c_mouth_info* get_mouth( void ) = 0;
	virtual bool get_sound_spatialization( spatialization_info_t& info ) = 0;
};