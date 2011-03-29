// {{{RME classifier 'Logical View::ConcurrencyTestSystem'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ConcurrencyTestSystem.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <ConcurrencyTestSystem.h>
extern const RTActorClass Display;
extern const RTActorClass SystemHandler;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_ConcurrencyTestSystem_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ConcurrencyTestSystem_Actor( _rts, _ref );
}

const RTActorClass ConcurrencyTestSystem =
{
	(const RTActorClass *)0
  , "ConcurrencyTestSystem"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_ConcurrencyTestSystem_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "TestDisarmedAlarm"
  , "Enabled"
  , "Armed"
  , "DisarmPressed"
  , "BreakInDetected"
  , "PasswordEntered"
  , "Initialized"
  , "TestFailed"
  , "TestDisarmArm"
  , "Armed"
  , "DisarmPressed"
  , "ArmPressed"
  , "PasswordEntered"
  , "Initialized"
  , "ArmDuringAlarm"
  , "Armed"
  , "BreakInDetected"
  , "Initialized"
  , "ArmPressed"
  , "testPassed"
  , "CP1"
  , "CP1"
  , "CP1"
};

static const RTInterfaceDescriptor rtg_interfaces_systemHandlerR1[] =
{
	{
		"testSystem"
	  , 1
	}
  , {
		"failSensors"
	  , 1
	}
  , {
		"failAlarms"
	  , 0
	}
  , {
		"phoneTest"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_systemHandlerR1[] =
{
	{
		0
	  , &TestProtocol::Base::rt_class
	}
  , {
		1
	  , &PeripheralTest::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_display[] =
{
	{
		"toSystem"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_display[] =
{
	{
		0
	  , &DisplayProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

ConcurrencyTestSystem_Actor::ConcurrencyTestSystem_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ConcurrencyTestSystem_Actor::~ConcurrencyTestSystem_Actor( void )
{
}

int ConcurrencyTestSystem_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// systemHandlerR1
		switch( rtg_portId )
		{
		case 0:
			// testSystem
			if( rtg_repIndex < 1 )
			{
				// testSystem
				rtg_end.port = &testSystem;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		case 1:
			// failSensors
			if( rtg_repIndex < 1 )
			{
				// failSensors
				rtg_end.port = &failSensors;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// display
		switch( rtg_portId )
		{
		case 0:
			// toSystem
			if( rtg_repIndex < 1 )
			{
				// toDisplay
				rtg_end.port = &toDisplay;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	return RTActor::_followOutV( rtg_end, rtg_compId, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:TestDisarmedAlarm:Enabled:J4D90FCF701CD:armed'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition9_armed( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.arm_pressed().send();
	testSystem.password_entered(password).send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:Armed:J4D90FED70302:disarmPressed'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition10_disarmPressed( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.disarm_pressed().send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:DisarmPressed:J4D90FF1D02A4:breakin'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition11_breakin( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	failSensors.trigger().send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:BreakInDetected:J4D910080013A:passEntered'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition12_passEntered( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.password_entered(password).send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:Initialized:J4D9101CF0167:t1'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition13_t1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.enabled_pressed().send();
	testSystem.password_entered(password).send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:J4D90FB3B023D:Initial'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition14_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	toLog.log("===== STARTING TEST: Alarm Going Off While Disarming =====");
	timing.informIn(RTTimespec(5, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:PasswordEntered:J4D91EB5A005A:getDisarmed'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition15_getDisarmed( const void * rtdata, TestProtocol::Base * rtport )
{
	// {{{USR
	this->count=1;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:CP1:True'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition17_True( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	toLog.log("=====TEST PASSED: Alarm Going Off While Disarming =====");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmedAlarm:CP1:False'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition18_False( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	toLog.log("===== TEST FAILED: Alarm Going Off While Disarming =====");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:Armed:J4D90FED70302:disarmPressed'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition25_disarmPressed( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.disarm_pressed().send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:DisarmPressed:J4D90FF1D02A4:rearm'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition27_rearm( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	testSystem.arm_pressed().send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:ArmPressed:J4D910080013A:passEntered'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition28_passEntered( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.password_entered(password).send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:PasswordEntered:J4D91EB5A005A:getDisarmed'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition29_getDisarmed( const void * rtdata, TestProtocol::Base * rtport )
{
	// {{{USR
	this->count=1;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:J4D91EB8F014C:nextTest'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition31_nextTest( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	toLog.log("===== STARTING TEST: Arm Pressed While Disabling =====");
	timing.informIn(RTTimespec(5, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:Initialized:J4D91F116012D:arm'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition32_arm( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.arm_pressed().send();
	testSystem.password_entered(password).send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:CP1:False'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition33_False( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	toLog.log("===== TEST FAILED: Arm Pressed While Disabling =====");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:TestDisarmArm:CP1:True'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition34_True( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	toLog.log("=====TEST PASSED: Arm Pressed While Disabling =====");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ArmDuringAlarm:Initialized:J4D91F5ED0005:armed'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition37_armed( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String password="1234";
	testSystem.arm_pressed().send();
	testSystem.password_entered(password).send();
	timing.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ArmDuringAlarm:J4D91F17103E4:test3'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition38_test3( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	toLog.log("===== STARTING TEST: Arm Pressed While Break In =====");
	timing.informIn(RTTimespec(5, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ArmDuringAlarm:Armed:J4D91F62500A2:breakin'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition39_breakin( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	failSensors.trigger().send();
	timing.informIn(RTTimespec(5, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ArmDuringAlarm:CP1:False'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition40_False( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	toLog.log("===== TEST FAILED: Arm Pressed While Break In =====");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ArmDuringAlarm:BreakInDetected:J4D91F8620276:rearm'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition42_rearm( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	testSystem.arm_pressed().send();
	timing.informIn(RTTimespec(5, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ArmDuringAlarm:J4D91FBFE0301:success'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition44_success( const void * rtdata, TestProtocol::Base * rtport )
{
	// {{{USR
	this->count=1;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:ArmDuringAlarm:CP1:True'
INLINE_METHODS void ConcurrencyTestSystem_Actor::transition45_True( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	toLog.log("===== TEST PASSED: Arm Pressed While Break In =====");
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
	// transition ':TOP:TestDisarmedAlarm:J4D90FB3B023D:Initial'
	rtgChainBegin( 2, "Initial" );
	rtgTransitionBegin();
	transition14_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 8 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain21_display( void )
{
	// transition ':TOP:TestDisarmedAlarm:Enabled:J4D91EEA40082:display'
	rtgChainBegin( 3, "display" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain9_armed( void )
{
	// transition ':TOP:TestDisarmedAlarm:Enabled:J4D90FCF701CD:armed'
	rtgChainBegin( 3, "armed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_armed( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain19_armedCorrectly( void )
{
	// transition ':TOP:TestDisarmedAlarm:Armed:J4D91EE1B0168:armedCorrectly'
	rtgChainBegin( 4, "armedCorrectly" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain20_display( void )
{
	// transition ':TOP:TestDisarmedAlarm:Armed:J4D91EE890302:display'
	rtgChainBegin( 4, "display" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain10_disarmPressed( void )
{
	// transition ':TOP:TestDisarmedAlarm:Armed:J4D90FED70302:disarmPressed'
	rtgChainBegin( 4, "disarmPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition10_disarmPressed( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain22_display( void )
{
	// transition ':TOP:TestDisarmedAlarm:DisarmPressed:J4D91EEB5039D:display'
	rtgChainBegin( 5, "display" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain11_breakin( void )
{
	// transition ':TOP:TestDisarmedAlarm:DisarmPressed:J4D90FF1D02A4:breakin'
	rtgChainBegin( 5, "breakin" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition11_breakin( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain12_passEntered( void )
{
	// transition ':TOP:TestDisarmedAlarm:BreakInDetected:J4D910080013A:passEntered'
	rtgChainBegin( 6, "passEntered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition12_passEntered( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain15_getDisarmed( void )
{
	// transition ':TOP:TestDisarmedAlarm:PasswordEntered:J4D91EB5A005A:getDisarmed'
	rtgChainBegin( 7, "getDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition15_getDisarmed( msg->data, (TestProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain16_testPassed( void )
{
	// transition ':TOP:TestDisarmedAlarm:PasswordEntered:J4D91EBD0030E:testPassed'
	rtgChainBegin( 7, "testPassed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_CP1( msg->data, (Timing::Base *)msg->sap() ) )
		chain17_True();
	else
		chain18_False();
}

// {{{RME choicePoint ':TOP:TestDisarmedAlarm:CP1'
INLINE_METHODS int ConcurrencyTestSystem_Actor::choicePoint1_CP1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	return (this->count==1);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain17_True( void )
{
	// transition ':TOP:TestDisarmedAlarm:CP1:True'
	rtgChainBegin( 22, "True" );
	rtgTransitionBegin();
	transition17_True( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:TestDisarmedAlarm:J4D91EB8F0147:nextTest'
	rtgChainBegin( 2, "nextTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 10 );
	// transition ':TOP:TestDisarmArm:J4D91EB8F014C:nextTest'
	rtgChainBegin( 10, "nextTest" );
	rtgTransitionBegin();
	transition31_nextTest( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 15 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain18_False( void )
{
	// transition ':TOP:TestDisarmedAlarm:CP1:False'
	rtgChainBegin( 22, "False" );
	rtgTransitionBegin();
	transition18_False( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:TestDisarmedAlarm:J4D90FB8E0142:testFailed'
	rtgChainBegin( 2, "testFailed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 9 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain13_t1( void )
{
	// transition ':TOP:TestDisarmedAlarm:Initialized:J4D9101CF0167:t1'
	rtgChainBegin( 8, "t1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition13_t1( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain23_armedCorrectly( void )
{
	// transition ':TOP:TestDisarmArm:Armed:J4D91EE1B0168:armedCorrectly'
	rtgChainBegin( 11, "armedCorrectly" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 11 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain24_display( void )
{
	// transition ':TOP:TestDisarmArm:Armed:J4D91EE890302:display'
	rtgChainBegin( 11, "display" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 11 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain25_disarmPressed( void )
{
	// transition ':TOP:TestDisarmArm:Armed:J4D90FED70302:disarmPressed'
	rtgChainBegin( 11, "disarmPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition25_disarmPressed( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 12 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain26_display( void )
{
	// transition ':TOP:TestDisarmArm:DisarmPressed:J4D91EEB5039D:display'
	rtgChainBegin( 12, "display" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 12 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain27_rearm( void )
{
	// transition ':TOP:TestDisarmArm:DisarmPressed:J4D90FF1D02A4:rearm'
	rtgChainBegin( 12, "rearm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition27_rearm( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 13 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain28_passEntered( void )
{
	// transition ':TOP:TestDisarmArm:ArmPressed:J4D910080013A:passEntered'
	rtgChainBegin( 13, "passEntered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition28_passEntered( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 14 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain29_getDisarmed( void )
{
	// transition ':TOP:TestDisarmArm:PasswordEntered:J4D91EB5A005A:getDisarmed'
	rtgChainBegin( 14, "getDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition29_getDisarmed( msg->data, (TestProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 14 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain30_testPassed( void )
{
	// transition ':TOP:TestDisarmArm:PasswordEntered:J4D91EBD0030E:testPassed'
	rtgChainBegin( 14, "testPassed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_CP1( msg->data, (Timing::Base *)msg->sap() ) )
		chain34_True();
	else
		chain33_False();
}

// {{{RME choicePoint ':TOP:TestDisarmArm:CP1'
INLINE_METHODS int ConcurrencyTestSystem_Actor::choicePoint2_CP1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	return (this->count==1);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain34_True( void )
{
	// transition ':TOP:TestDisarmArm:CP1:True'
	rtgChainBegin( 23, "True" );
	rtgTransitionBegin();
	transition34_True( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:TestDisarmArm:J4D91F17103DF:test3'
	rtgChainBegin( 10, "test3" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 16 );
	// transition ':TOP:ArmDuringAlarm:J4D91F17103E4:test3'
	rtgChainBegin( 16, "test3" );
	rtgTransitionBegin();
	transition38_test3( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 19 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain33_False( void )
{
	// transition ':TOP:TestDisarmArm:CP1:False'
	rtgChainBegin( 23, "False" );
	rtgTransitionBegin();
	transition33_False( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:TestDisarmArm:J4D91F0930020:testFailed'
	rtgChainBegin( 10, "testFailed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 9 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain32_arm( void )
{
	// transition ':TOP:TestDisarmArm:Initialized:J4D91F116012D:arm'
	rtgChainBegin( 15, "arm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition32_arm( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 11 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain7_alarmSuccess( void )
{
	// transition ':TOP:ArmDuringAlarm:J4D91FBFE02FC:alarmSuccess'
	rtgChainBegin( 16, "alarmSuccess" );
	exitToChainState( 16, rtg_parent_state );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 16 );
	// transition ':TOP:ArmDuringAlarm:J4D91FBFE0301:success'
	rtgChainBegin( 16, "success" );
	rtgTransitionBegin();
	transition44_success( msg->data, (TestProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint3_CP1( msg->data, msg->sap() ) )
		chain45_True();
	else
		chain40_False();
}

// {{{RME choicePoint ':TOP:ArmDuringAlarm:CP1'
INLINE_METHODS int ConcurrencyTestSystem_Actor::choicePoint3_CP1( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	return (this->count==1);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain45_True( void )
{
	// transition ':TOP:ArmDuringAlarm:CP1:True'
	rtgChainBegin( 24, "True" );
	rtgTransitionBegin();
	transition45_True( msg->data, msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:ArmDuringAlarm:J4D91FCE40032:testsPassed'
	rtgChainBegin( 16, "testsPassed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 21 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain40_False( void )
{
	// transition ':TOP:ArmDuringAlarm:CP1:False'
	rtgChainBegin( 24, "False" );
	rtgTransitionBegin();
	transition40_False( msg->data, msg->sap() );
	rtgTransitionEnd();
	// transition ':TOP:ArmDuringAlarm:J4D91F683020C:testFailed'
	rtgChainBegin( 16, "testFailed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 9 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain35_armedCorrectly( void )
{
	// transition ':TOP:ArmDuringAlarm:Armed:J4D91EE1B0168:armedCorrectly'
	rtgChainBegin( 17, "armedCorrectly" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 17 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain36_display( void )
{
	// transition ':TOP:ArmDuringAlarm:Armed:J4D91EE890302:display'
	rtgChainBegin( 17, "display" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 17 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain39_breakin( void )
{
	// transition ':TOP:ArmDuringAlarm:Armed:J4D91F62500A2:breakin'
	rtgChainBegin( 17, "breakin" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition39_breakin( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 18 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain41_display( void )
{
	// transition ':TOP:ArmDuringAlarm:BreakInDetected:J4D91F79E00EB:display'
	rtgChainBegin( 18, "display" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 18 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain42_rearm( void )
{
	// transition ':TOP:ArmDuringAlarm:BreakInDetected:J4D91F8620276:rearm'
	rtgChainBegin( 18, "rearm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition42_rearm( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 20 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain37_armed( void )
{
	// transition ':TOP:ArmDuringAlarm:Initialized:J4D91F5ED0005:armed'
	rtgChainBegin( 19, "armed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition37_armed( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 17 );
}

INLINE_CHAINS void ConcurrencyTestSystem_Actor::chain43_testState( void )
{
	// transition ':TOP:ArmDuringAlarm:ArmPressed:J4D91F8830092:testState'
	rtgChainBegin( 20, "testState" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint3_CP1( msg->data, msg->sap() ) )
		chain45_True();
	else
		chain40_False();
}

void ConcurrencyTestSystem_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; stateIndex = rtg_parent_state[ stateIndex - 1 ] )
		switch( stateIndex )
		{
		case 1:
			// {{{RME state ':TOP'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					chain1_Initial();
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			unexpectedMessage();
			return;
			// }}}RME
		case 2:
			// {{{RME state ':TOP:TestDisarmedAlarm'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
			// }}}RME
		case 3:
			// {{{RME state ':TOP:TestDisarmedAlarm:Enabled'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_display_string:
					chain21_display();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain9_armed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 4:
			// {{{RME state ':TOP:TestDisarmedAlarm:Armed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_armed:
					chain19_armedCorrectly();
					return;
				case TestProtocol::Base::rti_display_string:
					chain20_display();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain10_disarmPressed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 5:
			// {{{RME state ':TOP:TestDisarmedAlarm:DisarmPressed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_display_string:
					chain22_display();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain11_breakin();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 6:
			// {{{RME state ':TOP:TestDisarmedAlarm:BreakInDetected'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain12_passEntered();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 7:
			// {{{RME state ':TOP:TestDisarmedAlarm:PasswordEntered'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				chain15_getDisarmed();
				return;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain16_testPassed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 8:
			// {{{RME state ':TOP:TestDisarmedAlarm:Initialized'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain13_t1();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 9:
			// {{{RME state ':TOP:TestFailed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
			// }}}RME
		case 10:
			// {{{RME state ':TOP:TestDisarmArm'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
			// }}}RME
		case 11:
			// {{{RME state ':TOP:TestDisarmArm:Armed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_armed:
					chain23_armedCorrectly();
					return;
				case TestProtocol::Base::rti_display_string:
					chain24_display();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain25_disarmPressed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 12:
			// {{{RME state ':TOP:TestDisarmArm:DisarmPressed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_display_string:
					chain26_display();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain27_rearm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 13:
			// {{{RME state ':TOP:TestDisarmArm:ArmPressed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain28_passEntered();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 14:
			// {{{RME state ':TOP:TestDisarmArm:PasswordEntered'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				chain29_getDisarmed();
				return;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain30_testPassed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 15:
			// {{{RME state ':TOP:TestDisarmArm:Initialized'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain32_arm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 16:
			// {{{RME state ':TOP:ArmDuringAlarm'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_alarms_triggered:
					chain7_alarmSuccess();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 17:
			// {{{RME state ':TOP:ArmDuringAlarm:Armed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_armed:
					chain35_armedCorrectly();
					return;
				case TestProtocol::Base::rti_display_string:
					chain36_display();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain39_breakin();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 18:
			// {{{RME state ':TOP:ArmDuringAlarm:BreakInDetected'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 1:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Base::rti_display_string:
					chain41_display();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain42_rearm();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 19:
			// {{{RME state ':TOP:ArmDuringAlarm:Initialized'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain37_armed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 20:
			// {{{RME state ':TOP:ArmDuringAlarm:ArmPressed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 3:
				// {{{RME port 'timing'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain43_testState();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		case 21:
			// {{{RME state ':TOP:testPassed'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * ConcurrencyTestSystem_Actor::getActorData( void ) const
{
	return &ConcurrencyTestSystem_Actor::rtg_class;
}

const RTActor_class ConcurrencyTestSystem_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 21
  , ConcurrencyTestSystem_Actor::rtg_parent_state
  , &ConcurrencyTestSystem
  , 2
  , ConcurrencyTestSystem_Actor::rtg_capsule_roles
  , 5
  , ConcurrencyTestSystem_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , ConcurrencyTestSystem_Actor::rtg_ConcurrencyTestSystem_fields
};

const RTStateId ConcurrencyTestSystem_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 2
  , 2
  , 2
  , 2
  , 2
  , 2
  , 1
  , 1
  , 10
  , 10
  , 10
  , 10
  , 10
  , 1
  , 16
  , 16
  , 16
  , 16
  , 1
};

const RTComponentDescriptor ConcurrencyTestSystem_Actor::rtg_capsule_roles[] =
{
	{
		"systemHandlerR1"
	  , &SystemHandler
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, systemHandlerR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 4
	  , rtg_interfaces_systemHandlerR1
	  , 2
	  , rtg_bindings_systemHandlerR1
	}
  , {
		"display"
	  , &Display
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, display )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_display
	  , 1
	  , rtg_bindings_display
	}
};

const RTPortDescriptor ConcurrencyTestSystem_Actor::rtg_ports[] =
{
	{
		"testSystem"
	  , (const char *)0
	  , &TestProtocol::Base::rt_class
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, ConcurrencyTestSystem_Actor::testSystem )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"failSensors"
	  , (const char *)0
	  , &PeripheralTest::Conjugate::rt_class
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, ConcurrencyTestSystem_Actor::failSensors )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"timing"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, ConcurrencyTestSystem_Actor::timing )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toDisplay"
	  , (const char *)0
	  , &DisplayProtocol::Conjugate::rt_class
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, ConcurrencyTestSystem_Actor::toDisplay )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toLog"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, ConcurrencyTestSystem_Actor::toLog )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor ConcurrencyTestSystem_Actor::rtg_ConcurrencyTestSystem_fields[] =
{
	// {{{RME classAttribute 'count'
	{
		"count"
	  , RTOffsetOf( ConcurrencyTestSystem_Actor, count )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
