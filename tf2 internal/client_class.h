#pragma once

// todo: remove once we have i_client_networkable
class i_client_networkable;

typedef i_client_networkable* ( *create_client_class_fn )( int ent_num, int serial_num );
typedef i_client_networkable* ( *create_event_fn )( );

class client_class {
	create_client_class_fn m_create_fn;
	create_event_fn m_create_event_fn;
	const char* m_network_name;
	recv_table* m_recv_table;
	client_class* m_next;
	int	m_class_id;
};