// {{{RME classifier 'Logical View::TestSystemHandler'

#ifndef TestSystemHandler_H
#define TestSystemHandler_H

#ifdef PRAGMA
#pragma interface "TestSystemHandler.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <DisplayProtocol.h>
#include <HandlerProtocol.h>
#include <TestProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <cstdio>

// }}}USR
// }}}RME

extern const RTActorClass TestSystemHandler;

#define SUPER RTActor
class TestSystemHandler_Actor : public RTActor
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME
	// {{{RME classAttribute 'count'
	int count;
	// }}}RME
	// {{{RME classAttribute 'breakin'
	int breakin;
	// }}}RME
	// {{{RME classAttribute 'passFail'
	int passFail;
	// }}}RME

protected:
	// {{{RME capsuleRole 'systemHandlerR1'
	RTActorRef systemHandlerR1;
	// }}}RME
	// {{{RME capsuleRole 'display'
	RTActorRef display;
	// }}}RME
	// {{{RME port 'testSystem'
	TestProtocol::Base testSystem;
	// }}}RME
	// {{{RME port 'setAlarms'
	HandlerProtocol::Base setAlarms;
	// }}}RME
	// {{{RME port 'selftestTimeout'
	Timing::Base selftestTimeout;
	// }}}RME
	// {{{RME port 'toDisplay'
	DisplayProtocol::Conjugate toDisplay;
	// }}}RME

public:
	TestSystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~TestSystemHandler_Actor( void );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:timeout:J4D7003EB01D3:disarm'
	INLINE_METHODS void transition2_disarm( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP1:False'
	INLINE_METHODS void transition4_False( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP1:True'
	INLINE_METHODS void transition5_True( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:enable:J4D700892013E:arm'
	INLINE_METHODS void transition6_arm( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:initializing:J4D7008B601EA:enable'
	INLINE_METHODS void transition7_enable( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP2:True'
	INLINE_METHODS void transition9_True( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP1_0:False'
	INLINE_METHODS void transition11_False( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP1_0:True'
	INLINE_METHODS void transition12_True( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP2:False'
	INLINE_METHODS void transition13_False( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:failTimeout:J4D700D02031A:t1'
	INLINE_METHODS void transition14_t1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP3:True'
	INLINE_METHODS void transition15_True( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP3:False'
	INLINE_METHODS void transition16_False( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain8_failTest( void );

protected:
	// {{{RME choicePoint ':TOP:CP2'
	INLINE_METHODS int choicePoint2_CP2( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain9_True( void );
	INLINE_CHAINS void chain13_False( void );
	INLINE_CHAINS void chain7_enable( void );
	INLINE_CHAINS void chain3_t1( void );

protected:
	// {{{RME choicePoint ':TOP:CP1'
	INLINE_METHODS int choicePoint1_CP1( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain5_True( void );
	INLINE_CHAINS void chain4_False( void );
	INLINE_CHAINS void chain17_reset( void );

protected:
	// {{{RME choicePoint ':TOP:CP3'
	INLINE_METHODS int choicePoint4_CP3( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain15_True( void );
	INLINE_CHAINS void chain16_False( void );
	INLINE_CHAINS void chain2_disarm( void );
	INLINE_CHAINS void chain6_arm( void );
	INLINE_CHAINS void chain10_t1( void );

protected:
	// {{{RME choicePoint ':TOP:CP1_0'
	INLINE_METHODS int choicePoint3_CP1_0( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain12_True( void );
	INLINE_CHAINS void chain11_False( void );
	INLINE_CHAINS void chain14_t1( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTComponentDescriptor rtg_capsule_roles[];
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_TestSystemHandler_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TestSystemHandler_H */

// }}}RME
