#include "sdk.h"

unsigned long __stdcall cheat_thread( _In_ LPVOID reserved ) {
	return 0;
}

BOOL WINAPI DllMain( _In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved ) {
	if ( reason == DLL_PROCESS_ATTACH ) {
		if ( auto* const thread_handle = CreateThread( nullptr, 0, cheat_thread, instance, 0, nullptr ) )
			CloseHandle( thread_handle );
	}

	return TRUE;
}