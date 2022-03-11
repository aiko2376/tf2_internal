#pragma once

struct netvar_t {
	const char* m_table;
	const char* m_var;
	uintptr_t m_offset;
};

class c_netvars {
public:
	std::deque< netvar_t > m_netvars;

	void init( );
	netvar_t get( const char* table, const char* var );
}; inline c_netvars g_netvars;