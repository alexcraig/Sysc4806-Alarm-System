// {{{RME classifier 'Logical View::SystemHandler'

#ifndef SystemHandler_H
#define SystemHandler_H

#ifdef PRAGMA
#pragma interface "SystemHandler.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <CellConfiguration.h>
#include <DisplayProtocol.h>
#include <HandlerProtocol.h>
#include <KeypadProtocol.h>
#include <PhoneProtocol.h>
#include <TestProtocol.h>
#include <UserConfiguration.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR
#include <cstdio>

// }}}USR
// }}}RME

extern const RTActorClass SystemHandler;

#define SUPER RTActor
class SystemHandler_Actor : public RTActor
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
	// {{{RME classAttribute 'config'
	UserConfiguration config;
	// }}}RME
	// {{{RME classAttribute 'cellResponded'
	bool cellResponded[ NUMBER_OF_CELLS ];
	// }}}RME
	// {{{RME classAttribute 'breakInTimerRunning'
	bool breakInTimerRunning;
	// }}}RME
	// {{{RME classAttribute 'testPassed'
	bool testPassed;
	// }}}RME

protected:
	// {{{RME capsuleRole 'displayR1'
	RTActorRef displayR1;
	// }}}RME
	// {{{RME capsuleRole 'keypadR1'
	RTActorRef keypadR1;
	// }}}RME
	// {{{RME capsuleRole 'soundAlarmR1'
	RTActorRef soundAlarmR1;
	// }}}RME
	// {{{RME capsuleRole 'cellHandlerR1'
	RTActorRef cellHandlerR1;
	// }}}RME
	// {{{RME capsuleRole 'phoneLineR1'
	RTActorRef phoneLineR1;
	// }}}RME
	// {{{RME port 'toCells'
	HandlerProtocol::Base toCells;
	// }}}RME
	// {{{RME port 'toKeypad'
	KeypadProtocol::Conjugate toKeypad;
	// }}}RME
	// {{{RME port 'toDisplay'
	DisplayProtocol::Conjugate toDisplay;
	// }}}RME
	// {{{RME port 'toInternalAlarm'
	HandlerProtocol::Base toInternalAlarm;
	// }}}RME
	// {{{RME port 'toLog'
	Log::Base toLog;
	// }}}RME
	// {{{RME port 'selftestTimeout'
	Timing::Base selftestTimeout;
	// }}}RME
	// {{{RME port 'toPhone'
	PhoneProtocol::Conjugate toPhone;
	// }}}RME
	// {{{RME port 'selftestPeriodic'
	Timing::Base selftestPeriodic;
	// }}}RME
	// {{{RME port 'breakInTimeout'
	Timing::Base breakInTimeout;
	// }}}RME
	// {{{RME port 'testSystem'
	TestProtocol::Conjugate testSystem;
	// }}}RME
	// {{{RME port 'testPort'
	TestProtocol::Base testPort;
	// }}}RME
	// {{{RME port 'internalAlarmTest'
	TestProtocol::Base internalAlarmTest;
	// }}}RME

public:
	SystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~SystemHandler_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initializing:J4D6E6A3D017C:TimeoutElapsed'
	INLINE_METHODS void transition2_TimeoutElapsed( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:J4D7FC414029B:TestArmed'
	INLINE_METHODS void transition3_TestArmed( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:J4D7FD0A500FA:TestDisarmed'
	INLINE_METHODS void transition4_TestDisarmed( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Disabled:J4D6E70570280:EnablePressed'
	INLINE_METHODS void transition6_EnablePressed( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:EnablePasswordValidate:False'
	INLINE_METHODS void transition8_False( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:J4D6E736B011E:DisablePressed'
	INLINE_METHODS void transition9_DisablePressed( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:DisablePasswordValidate:True'
	INLINE_METHODS void transition11_True( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:DisablePasswordValidate:False'
	INLINE_METHODS void transition12_False( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:J4D6E78CD004D:StartSelfTest'
	INLINE_METHODS void transition13_StartSelfTest( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:J4D6E7A440149:GotCellHearbeat'
	INLINE_METHODS void transition14_GotCellHearbeat( const void * rtdata, HandlerProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:EnablePasswordValidate:True'
	INLINE_METHODS void transition15_True( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:J4D6E8F35018B:BreakInTimeout'
	INLINE_METHODS void transition16_BreakInTimeout( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:J4D6E908F020A:SelfTestComplete'
	INLINE_METHODS void transition17_SelfTestComplete( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Disarmed:J4D6E70570280:ArmPressed'
	INLINE_METHODS void transition18_ArmPressed( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E736B011E:DisarmPressed'
	INLINE_METHODS void transition19_DisarmPressed( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:ArmPasswordValidate:True'
	INLINE_METHODS void transition21_True( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:ArmPasswordValidate:False'
	INLINE_METHODS void transition22_False( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:DisarmPasswordValidate:True'
	INLINE_METHODS void transition24_True( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:DisarmPasswordValidate:False'
	INLINE_METHODS void transition25_False( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Disarmed:J4D6E7F6F029A:DisarmedFailure'
	INLINE_METHODS void transition27_DisarmedFailure( const PeripheralIdentifier * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E88EA022D:ArmedFailure'
	INLINE_METHODS void transition28_ArmedFailure( const PeripheralIdentifier * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E8D7B033E:ArmedBreakin'
	INLINE_METHODS void transition29_ArmedBreakin( const PeripheralIdentifier * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E8E4202D2:BreakInTimerExpired'
	INLINE_METHODS void transition30_BreakInTimerExpired( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E91C001CE:SuccesfullPhoneCall'
	INLINE_METHODS void transition31_SuccesfullPhoneCall( const void * rtdata, PhoneProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E920B022C:FailedPhoneCall'
	INLINE_METHODS void transition32_FailedPhoneCall( const void * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_TimeoutElapsed( void );
	INLINE_CHAINS void chain4_TestDisarmed( void );
	INLINE_CHAINS void chain3_TestArmed( void );
	INLINE_CHAINS void chain6_EnablePressed( void );
	INLINE_CHAINS void chain14_GotCellHearbeat( void );
	INLINE_CHAINS void chain9_DisablePressed( void );
	INLINE_CHAINS void chain17_SelfTestComplete( void );
	INLINE_CHAINS void chain13_StartSelfTest( void );
	INLINE_CHAINS void chain16_BreakInTimeout( void );
	INLINE_CHAINS void chain27_DisarmedFailure( void );
	INLINE_CHAINS void chain18_ArmPressed( void );
	INLINE_CHAINS void chain29_ArmedBreakin( void );
	INLINE_CHAINS void chain28_ArmedFailure( void );
	INLINE_CHAINS void chain19_DisarmPressed( void );
	INLINE_CHAINS void chain31_SuccesfullPhoneCall( void );
	INLINE_CHAINS void chain32_FailedPhoneCall( void );
	INLINE_CHAINS void chain30_BreakInTimerExpired( void );
	INLINE_CHAINS void chain20_PasswordEntered( void );

protected:
	// {{{RME choicePoint ':TOP:Initialized:Enabled:ArmPasswordValidate'
	INLINE_METHODS int choicePoint3_ArmPasswordValidate( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain21_True( void );
	INLINE_CHAINS void chain22_False( void );
	INLINE_CHAINS void chain23_PasswordEntered( void );

protected:
	// {{{RME choicePoint ':TOP:Initialized:Enabled:DisarmPasswordValidate'
	INLINE_METHODS int choicePoint4_DisarmPasswordValidate( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain24_True( void );
	INLINE_CHAINS void chain25_False( void );
	INLINE_CHAINS void chain7_PasswordEntered( void );

protected:
	// {{{RME choicePoint ':TOP:Initialized:EnablePasswordValidate'
	INLINE_METHODS int choicePoint1_EnablePasswordValidate( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain15_True( void );
	INLINE_CHAINS void chain8_False( void );
	INLINE_CHAINS void chain10_PasswordEntered( void );

protected:
	// {{{RME choicePoint ':TOP:Initialized:DisablePasswordValidate'
	INLINE_METHODS int choicePoint2_DisablePasswordValidate( const RTString * rtdata, RTProtocol * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain11_True( void );
	INLINE_CHAINS void chain12_False( void );

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
	static const RTFieldDescriptor rtg_SystemHandler_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SystemHandler_H */

// }}}RME
