#include "../sdk/sdk.h"

unsigned long __stdcall cheat_thread( _In_ LPVOID reserved ) {

#ifdef _DEBUG
	AllocConsole( );
	SetConsoleTitleA( xor("TF2 Internal" ));
	freopen_s( reinterpret_cast< FILE** >( stdout ), xor("CONOUT$"), xor("w"), stdout );
	g_utils.log( "[DEBUG]: Injected\n" );
#endif

	g_client.init( );

	while ( !( GetAsyncKeyState( VK_DELETE ) & 1 ) )
		std::this_thread::sleep_for( std::chrono::milliseconds( 250 ) );

	g_client.unload( );

	FreeLibraryAndExitThread( static_cast< HMODULE >( reserved ), 0 );
}

BOOL WINAPI DllMain( _In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved ) {
	if ( reason == DLL_PROCESS_ATTACH ) {
		if ( auto* const& thread_handle = CreateThread( nullptr, 0, cheat_thread, instance, 0, nullptr ); thread_handle )
			CloseHandle( thread_handle );
	}

	return TRUE;
}