#include "sdk.h"

void c_tier0::init( ) {
	this->tier0_module_ = g_modules.get( _( "tier0.dll" ) );

	this->msg_ = this->tier0_module_.get_proc_address< generic_msg_fn >( _( "Msg" ) );
	this->con_warning_ = this->tier0_module_.get_proc_address< generic_msg_fn >( _( "?ConWarning@@YAXPBDZZ" ) );
	this->dev_msg_ = this->tier0_module_.get_proc_address< generic_msg_fn >( _( "?DevMsg@@YAXPBDZZ" ) );

	if ( g_cl.m_debug_build ) {
		g_utils.m_debug.set_console_color( e_console_colors::console_color_green );
		printf_s( _( "tier0 (0x%p)\n" ), this->tier0_module_.m_module );
		printf_s( _( "msg: (0x%p)\n" ), this->msg_ );
		printf_s( _( "con_warning: (0x%p)\n" ), this->con_warning_ );
		printf_s( _( "dev_msg: (0x%p)\n" ), this->dev_msg_ );
	}
}

// dunno why we have these.
void c_tier0::msg( const char* text ) {
	if ( !this->msg_ )
		return;

	this->msg_( text );
}

void c_tier0::warning( const char* text ) {
	if ( !this->con_warning_ )
		return;

	this->con_warning_( text );
}

void c_tier0::dev_msg( const char* text ) {
	if ( !this->dev_msg_ )
		return;

	this->dev_msg_( text );
}