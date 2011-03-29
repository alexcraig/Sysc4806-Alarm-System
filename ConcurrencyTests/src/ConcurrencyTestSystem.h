// {{{RME classifier 'Logical View::ConcurrencyTestSystem'

#ifndef ConcurrencyTestSystem_H
#define ConcurrencyTestSystem_H

#ifdef PRAGMA
#pragma interface "ConcurrencyTestSystem.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <DisplayProtocol.h>
#include <PeripheralTest.h>
#include <TestProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ConcurrencyTestSystem;

#define SUPER RTActor
class ConcurrencyTestSystem_Actor : public RTActor
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
	// {{{RME port 'failSensors'
	PeripheralTest::Conjugate failSensors;
	// }}}RME
	// {{{RME port 'timing'
	Timing::Base timing;
	// }}}RME
	// {{{RME port 'toDisplay'
	DisplayProtocol::Conjugate toDisplay;
	// }}}RME
	// {{{RME port 'toLog'
	Log::Base toLog;
	// }}}RME

public:
	ConcurrencyTestSystem_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ConcurrencyTestSystem_Actor( void );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:TestDisarmedAlarm:Enabled:J4D90FCF701CD:armed'
	INLINE_METHODS void transition9_armed( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:Armed:J4D90FED70302:disarmPressed'
	INLINE_METHODS void transition10_disarmPressed( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:DisarmPressed:J4D90FF1D02A4:breakin'
	INLINE_METHODS void transition11_breakin( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:BreakInDetected:J4D910080013A:passEntered'
	INLINE_METHODS void transition12_passEntered( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:Initialized:J4D9101CF0167:t1'
	INLINE_METHODS void transition13_t1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:J4D90FB3B023D:Initial'
	INLINE_METHODS void transition14_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:PasswordEntered:J4D91EB5A005A:getDisarmed'
	INLINE_METHODS void transition15_getDisarmed( const void * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:CP1:True'
	INLINE_METHODS void transition17_True( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmedAlarm:CP1:False'
	INLINE_METHODS void transition18_False( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:Armed:J4D90FED70302:disarmPressed'
	INLINE_METHODS void transition25_disarmPressed( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:DisarmPressed:J4D90FF1D02A4:rearm'
	INLINE_METHODS void transition27_rearm( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:ArmPressed:J4D910080013A:passEntered'
	INLINE_METHODS void transition28_passEntered( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:PasswordEntered:J4D91EB5A005A:getDisarmed'
	INLINE_METHODS void transition29_getDisarmed( const void * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:J4D91EB8F014C:nextTest'
	INLINE_METHODS void transition31_nextTest( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:Initialized:J4D91F116012D:arm'
	INLINE_METHODS void transition32_arm( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:CP1:False'
	INLINE_METHODS void transition33_False( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:TestDisarmArm:CP1:True'
	INLINE_METHODS void transition34_True( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ArmDuringAlarm:Initialized:J4D91F5ED0005:armed'
	INLINE_METHODS void transition37_armed( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ArmDuringAlarm:J4D91F17103E4:test3'
	INLINE_METHODS void transition38_test3( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ArmDuringAlarm:Armed:J4D91F62500A2:breakin'
	INLINE_METHODS void transition39_breakin( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ArmDuringAlarm:CP1:False'
	INLINE_METHODS void transition40_False( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ArmDuringAlarm:BreakInDetected:J4D91F8620276:rearm'
	INLINE_METHODS void transition42_rearm( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ArmDuringAlarm:J4D91FBFE0301:success'
	INLINE_METHODS void transition44_success( const void * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:ArmDuringAlarm:CP1:True'
	INLINE_METHODS void transition45_True( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain21_display( void );
	INLINE_CHAINS void chain9_armed( void );
	INLINE_CHAINS void chain19_armedCorrectly( void );
	INLINE_CHAINS void chain20_display( void );
	INLINE_CHAINS void chain10_disarmPressed( void );
	INLINE_CHAINS void chain22_display( void );
	INLINE_CHAINS void chain11_breakin( void );
	INLINE_CHAINS void chain12_passEntered( void );
	INLINE_CHAINS void chain15_getDisarmed( void );
	INLINE_CHAINS void chain16_testPassed( void );

protected:
	// {{{RME choicePoint ':TOP:TestDisarmedAlarm:CP1'
	INLINE_METHODS int choicePoint1_CP1( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain17_True( void );
	INLINE_CHAINS void chain18_False( void );
	INLINE_CHAINS void chain13_t1( void );
	INLINE_CHAINS void chain23_armedCorrectly( void );
	INLINE_CHAINS void chain24_display( void );
	INLINE_CHAINS void chain25_disarmPressed( void );
	INLINE_CHAINS void chain26_display( void );
	INLINE_CHAINS void chain27_rearm( void );
	INLINE_CHAINS void chain28_passEntered( void );
	INLINE_CHAINS void chain29_getDisarmed( void );
	INLINE_CHAINS void chain30_testPassed( void );

protected:
	// {{{RME choicePoint ':TOP:TestDisarmArm:CP1'
	INLINE_METHODS int choicePoint2_CP1( const void * rtdata, Timing::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain34_True( void );
	INLINE_CHAINS void chain33_False( void );
	INLINE_CHAINS void chain32_arm( void );
	INLINE_CHAINS void chain7_alarmSuccess( void );

protected:
	// {{{RME choicePoint ':TOP:ArmDuringAlarm:CP1'
	INLINE_METHODS int choicePoint3_CP1( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain45_True( void );
	INLINE_CHAINS void chain40_False( void );
	INLINE_CHAINS void chain35_armedCorrectly( void );
	INLINE_CHAINS void chain36_display( void );
	INLINE_CHAINS void chain39_breakin( void );
	INLINE_CHAINS void chain41_display( void );
	INLINE_CHAINS void chain42_rearm( void );
	INLINE_CHAINS void chain37_armed( void );
	INLINE_CHAINS void chain43_testState( void );

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
	static const RTFieldDescriptor rtg_ConcurrencyTestSystem_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ConcurrencyTestSystem_H */

// }}}RME
