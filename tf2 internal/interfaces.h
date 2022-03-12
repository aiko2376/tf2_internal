#pragma once

class c_interfaces {
	void gather( );
public:
	void init( );

	i_base_client_dll* m_client;
	iv_engine_client* m_engine;
	i_prediction* m_prediction;
}; inline c_interfaces g_interfaces;