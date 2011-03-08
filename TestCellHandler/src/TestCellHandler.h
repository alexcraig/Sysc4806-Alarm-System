// {{{RME classifier 'Logical View::TestCellHandler'

#ifndef TestCellHandler_H
#define TestCellHandler_H

#ifdef PRAGMA
#pragma interface "TestCellHandler.h"
#endif

#include <RTSystem/TestCellHandler.h>
#include <DisplayProtocol.h>
#include <HandlerProtocol.h>
#include <TestProtocol.h>
class CellConfiguration;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass TestCellHandler;

#define SUPER RTActor
class TestCellHandler_Actor : public RTActor
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
	// {{{RME classAttribute 'testCase'
	int testCase;
	// }}}RME

protected:
	// {{{RME capsuleRole 'display'
	RTActorRef display;
	// }}}RME
	// {{{RME capsuleRole 'cellHandlerR1'
	RTActorRef cellHandlerR1;
	// }}}RME
	// {{{RME port 'testSystem'
	TestProtocol::Base testSystem;
	// }}}RME
	// {{{RME port 'com'
	HandlerProtocol::Base com;
	// }}}RME
	// {{{RME port 'toDisplay'
	DisplayProtocol::Conjugate toDisplay;
	// }}}RME
	// {{{RME port 'timeout'
	Timing::Base timeout;
	// }}}RME
	// {{{RME port 'debugLog'
	Log::Base debugLog;
	// }}}RME

public:
	TestCellHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~TestCellHandler_Actor( void );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:armDisarmTest'
	INLINE_METHODS void enter2_armDisarmTest( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME enter ':TOP:soundAlarmsTest'
	INLINE_METHODS void enter3_soundAlarmsTest( void );
	// }}}RME
	// {{{RME enter ':TOP:testOneAlarmAndSensor'
	INLINE_METHODS void enter4_testOneAlarmAndSensor( void );
	// }}}RME
	// {{{RME enter ':TOP:RespondTest'
	INLINE_METHODS void enter5_RespondTest( void );
	// }}}RME
	// {{{RME enter ':TOP:testAlarmAndSensor'
	INLINE_METHODS void enter6_testAlarmAndSensor( void );
	// }}}RME
	// {{{RME enter ':TOP:runSelfTest'
	INLINE_METHODS void enter7_runSelfTest( void );
	// }}}RME
	// {{{RME enter ':TOP:assertSelfTest'
	INLINE_METHODS void enter8_assertSelfTest( void );
	// }}}RME
	// {{{RME transition ':TOP:CP1:testDone'
	INLINE_METHODS void transition3_testDone( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:testOneAlarmAndSensor:J4D7643150010:nextTest' guard '1'
	INLINE_METHODS int guard5_nextTest_event1( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:testOneAlarmAndSensor:J4D7643150010:nextTest'
	INLINE_METHODS void transition5_nextTest( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:CP2:testDone'
	INLINE_METHODS void transition7_testDone( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:testAlarmAndSensor:J4D76837A01F1:nextTest'
	INLINE_METHODS void transition9_nextTest( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_isTestComplete( void );

protected:
	// {{{RME choicePoint ':TOP:CP1'
	INLINE_METHODS int choicePoint1_CP1( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain3_testDone( void );
	INLINE_CHAINS void chain4_continueArmTest( void );
	INLINE_CHAINS void chain6_isTestComplete( void );

protected:
	// {{{RME choicePoint ':TOP:CP2'
	INLINE_METHODS int choicePoint2_CP2( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain7_testDone( void );
	INLINE_CHAINS void chain8_continueAlarmTest( void );
	INLINE_CHAINS void chain5_nextTest( void );
	INLINE_CHAINS void chain10_continueRespondTest( void );
	INLINE_CHAINS void chain9_nextTest( void );
	INLINE_CHAINS void chain11_awaitTestResults( void );

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
	static const RTFieldDescriptor rtg_TestCellHandler_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* TestCellHandler_H */

// }}}RME
