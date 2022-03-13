#pragma once

struct netvar_t {
	unsigned int m_hashed_table;
	unsigned int m_hashed_var;
	uintptr_t m_offset;
};

class c_netvars {
	void get_offsets( );
public:
	std::deque< netvar_t > m_netvars;

	struct {
		struct {
			uintptr_t m_vec_origin, m_i_team_num;
		} dt_base_entity;
	} m_offsets;

	void init( );
	netvar_t get( const char* table, const char* var );
}; inline c_netvars g_netvars;