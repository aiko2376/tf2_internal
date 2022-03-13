#include "sdk.h"

void c_interfaces::gather( ) {
	auto client = g_modules.get( _( "client.dll" ) ); {
		this->m_client = client.get_interface( _( "VClient0" ) ).as< i_base_client_dll >( );
		this->m_prediction = client.get_interface( _( "VClientPrediction0" ) ).as< i_prediction >( );
		this->m_entity_list = client.get_interface( _( "VClientEntityList0" ) ).as< i_client_entity_list >( );
	}

	auto engine = g_modules.get( _( "engine.dll" ) ); {
		this->m_engine = engine.get_interface( _( "VEngineClient0" ) ).as< iv_engine_client >( );
		this->m_engine_sound = engine.get_interface( _( "IEngineSoundClient0" ) ).as< i_engine_sound >( );
		this->m_engine_vgui = engine.get_interface( _( "VEngineVGui0" ) ).as< i_engine_vgui >( );
	}

	auto vgui_mat_surface = g_modules.get( _( "vguimatsurface.dll" ) ); {
		this->m_surface = vgui_mat_surface.get_interface( _( "VGUI_Surface0" ) ).as< i_surface >( );
	}
}

void c_interfaces::init( ) {
	this->gather( );
}