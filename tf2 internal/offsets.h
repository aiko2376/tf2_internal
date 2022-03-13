#pragma once

class c_offsets {
public:
	struct {
		uint8_t* start_drawing;
		uint8_t* finish_drawing;
	} m_sigs;

	void init( );
}; inline c_offsets g_offsets;