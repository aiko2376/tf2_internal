#pragma once

class i_base_client_dll {
public:
	virtual int	init( create_interface_fn app_system_factory, create_interface_fn physics_factory, c_global_vars_base* globals ) = 0;
	virtual void post_init( ) = 0;
	virtual void shutdown( void ) = 0;
	virtual bool replay_init( create_interface_fn replay_factory ) = 0;
	virtual bool replay_post_init( ) = 0;
	virtual void level_init_pre_entity( char const* map_name ) = 0;
	virtual void level_init_post_entity( ) = 0;
	virtual void level_shutdown( void ) = 0;
	virtual client_class* get_all_classes( void ) = 0;
	virtual int	hud_vid_init( void ) = 0;
	virtual void hud_process_input( bool active ) = 0;
	virtual void hud_update( bool active ) = 0;
	virtual void hud_reset( void ) = 0;
	virtual void hud_text( const char* message ) = 0;
	virtual void in_activate_mouse( void ) = 0;
	virtual void in_deactive_mouse( void ) = 0;
	virtual void in_accumulate( void ) = 0;
	virtual void in_clear_states( void ) = 0;
	virtual bool in_is_key_down( const char* name, bool& is_down ) = 0;
	virtual void in_on_mouse_wheeld( int delta ) = 0;
	virtual int	in_key_event( int event_code, button_code_t key_num, const char* current_binding ) = 0;
	virtual void create_move( int sequence_number, float input_sample_frametime, bool active ) = 0;
	virtual void extra_mouse_sample( float frame_time, bool active ) = 0;
};