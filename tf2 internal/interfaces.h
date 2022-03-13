#pragma once

class c_interfaces {
	void gather( );
public:
	void init( );

	i_base_client_dll* m_client;
	iv_engine_client* m_engine;
	i_prediction* m_prediction;
	i_engine_sound* m_engine_sound;
	i_client_entity_list* m_entity_list;
	i_engine_vgui* m_engine_vgui;
}; inline c_interfaces g_interfaces;