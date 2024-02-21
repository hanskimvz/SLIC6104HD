/****************************************************************************
*
* CMutex
*
****************************************************************************/
#include "Mutex.h"

CMutex::CMutex( void )
{
#ifdef _LINUX
	// We could use PTHREAD_MUTEX_ERRORCHECK_NP for Linux debug builds
	pthread_mutex_init( &m_mutex, NULL );
#endif
#ifdef _WIN32
	m_mutex = ::CreateMutex( NULL, TRUE, NULL );
#endif
}

CMutex::~CMutex( void )
{
#ifdef _LINUX
	pthread_mutex_destroy( &m_mutex );
#endif
#ifdef _WIN32
	::CloseHandle( m_mutex );
#endif
}

void CMutex::Lock( void )
{
#ifdef _LINUX
	pthread_mutex_lock( &m_mutex );
#endif
#ifdef _WIN32
	::WaitForSingleObject( m_mutex, INFINITE );
#endif
}

void CMutex::Unlock( void )
{
#ifdef _LINUX
	pthread_mutex_unlock( &m_mutex );
#endif
#ifdef _WIN32
	::ReleaseMutex( m_mutex );
#endif
}


