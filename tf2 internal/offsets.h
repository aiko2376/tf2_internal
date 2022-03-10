#pragma once

class c_offsets {
public:
	struct {
		struct {
			uint8_t* interface_regs;
		} client;

		struct {
			uint8_t* interface_regs;
		} engine;
	} m_sigs;

	void init( );
}; inline c_offsets g_offsets;