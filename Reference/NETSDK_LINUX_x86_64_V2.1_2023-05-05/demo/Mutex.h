
#ifndef __MUTEX_IF_H__
#define __MUTEX_IF_H__


#define _LINUX

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>


class CMutex
{
private: // Unimplemented
    CMutex( const CMutex& );
    CMutex& operator=( const CMutex& );

public:
    CMutex( void );
    virtual ~CMutex( void );

    void Lock( void );
    void Unlock( void );

private:
#ifdef _LINUX
    pthread_mutex_t m_mutex;
#endif
#ifdef _WIN32
    HANDLE          m_mutex;
#endif
};


#endif

