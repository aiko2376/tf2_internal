#pragma once

// todo: fill this.
class i_surface {
	typedef void( __thiscall* start_drawing_fn )( void* );
	typedef void( __thiscall* finish_drawing_fn )( void* );
public:
	void start_drawing( );
	void finish_drawing( );
};