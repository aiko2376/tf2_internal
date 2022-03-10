#include "sdk.h"

void c_interfaces::gather( ) {
	auto client = g_modules.get( _( "client.dll" ) ); {
		this->m_client = client.get_interface( _( "VClient0" ) ).as< i_base_client_dll >( );
	}
}

void c_interfaces::init( ) {
	this->gather( );
}