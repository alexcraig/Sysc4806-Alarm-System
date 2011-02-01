// {{{RME component 'Component View::TopLevelTesting'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RTSystem/TopLevelTesting.h"
#endif

#include <RTSystem/TopLevelTesting.h>
extern const RTActorClass SystemHandler;

#if USE_THREADS

void _rtg_createThreads( RTDebugger * debugger )
{
}

void _rtg_mapLogicalThreads( RTController * controller )
{
}

void _rtg_deleteThreads( void )
{
}
#else

void _rtg_mapLogicalThreads( RTController * controller )
{
}
#endif

const char * const default_argv[] = { "SystemHandler" };

static const RTSystemDescriptor _rtg_system =
{
	&SystemHandler
#if USE_THREADS
  , DEFAULT_MAIN_PRIORITY
  , 20000
  , DEFAULT_TIMER_PRIORITY
  , 20000
  , _rtg_createThreads
  , _rtg_deleteThreads
#endif
  , _rtg_mapLogicalThreads
};

int RTMain::entryPoint( int argc, const char * const * argv )
{
	if( argc <= 0 )
	{
		argc = 1;
		argv = default_argv;
	}
	_argc   = argc;
	_argv   = argv;
	_system = &_rtg_system;
	return execute();
}

// }}}RME
