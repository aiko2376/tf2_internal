#pragma once

// todo: maybe have something a bit more clean, i just want to automate grabbing all sigs.
struct signature_t {
	signature_t( const char* dll, const char* sig, bool relative = false ) {
		this->m_dll = dll;
		this->m_rel = relative;
		this->m_sig = sig;
		this->m_ptr = nullptr;
	}

	const char* m_dll;
	const char* m_sig;
	bool m_rel;
	uintptr_t* m_ptr;
};

class c_offsets {
public:
	struct {
		// x-ref "-pixel_offset_x"
		signature_t start_drawing = signature_t( "vguimatsurface.dll", "55 8B EC 64 A1 ? ? ? ? 6A FF 68 6C" );

		// x-ref "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.!:-/%"
		signature_t finish_drawing = signature_t( "vguimatsurface.dll", "55 8B EC 6A FF 68 DC B1 0C 10 64 A1 ? ? ? ? 50 64 89 25 ? ? ? ? 51 56 6A" );
	} m_signatures;
}; inline c_offsets g_offsets;