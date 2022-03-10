#pragma once

class c_mem {
public:
	int m_sigs_scanned;
	std::uint8_t* get_sig( module_t mod, const char* signature );
}; inline c_mem g_mem;