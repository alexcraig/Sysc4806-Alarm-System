// {{{RME component 'Component View::TestCellHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "RTSystem/TestCellHandler.h"
#endif

#include <RTSystem/TestCellHandler.h>
extern const RTActorClass TestCellHandler;

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

const char * const default_argv[] = { "TestCellHandler" };

static const RTSystemDescriptor _rtg_system =
{
	&TestCellHandler
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
