// {{{RME classifier 'Logical View::TestCellHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TestCellHandler.h"
#endif

#include <RTSystem/TestCellHandler.h>
#include <TestCellHandler.h>
#include <CellConfiguration.h>
extern const RTActorClass CellHandler;
extern const RTActorClass Display;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_TestCellHandler_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new TestCellHandler_Actor( _rts, _ref );
}

const RTActorClass TestCellHandler =
{
	(const RTActorClass *)0
  , "TestCellHandler"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_TestCellHandler_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "armDisarmTest"
  , "soundAlarmsTest"
  , "testOneAlarmAndSensor"
  , "RespondTest"
  , "testAlarmAndSensor"
  , "runSelfTest"
  , "assertSelfTest"
  , "CP1"
  , "CP2"
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

static const RTInterfaceDescriptor rtg_interfaces_cellHandlerR1[] =
{
	{
		"fromSystem"
	  , 1
	}
  , {
		"testSystem"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_cellHandlerR1[] =
{
	{
		0
	  , &HandlerProtocol::Base::rt_class
	}
  , {
		1
	  , &TestProtocol::Base::rt_class
	}
};

#define SUPER RTActor

TestCellHandler_Actor::TestCellHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, testCase( 0 )
{
}

TestCellHandler_Actor::~TestCellHandler_Actor( void )
{
}

int TestCellHandler_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
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
	case 2:
		// cellHandlerR1
		switch( rtg_portId )
		{
		case 0:
			// fromSystem
			if( rtg_repIndex < 1 )
			{
				// com
				rtg_end.port = &com;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		case 1:
			// testSystem
			if( rtg_repIndex < 1 )
			{
				// testSystem
				rtg_end.port = &testSystem;
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

// {{{RME enter ':TOP:armDisarmTest'
INLINE_METHODS void TestCellHandler_Actor::enter2_armDisarmTest( void )
{
	// {{{USR
	testSystem.disarm().send();
	timeout.informIn(RTTimespec(0.25, 0));
	// }}}USR
}
// }}}RME

void TestCellHandler_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_armDisarmTest();
		break;
	case 3:
		enter3_soundAlarmsTest();
		break;
	case 4:
		enter4_testOneAlarmAndSensor();
		break;
	case 5:
		enter5_RespondTest();
		break;
	case 6:
		enter6_testAlarmAndSensor();
		break;
	case 7:
		enter7_runSelfTest();
		break;
	case 8:
		enter8_assertSelfTest();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME enter ':TOP:soundAlarmsTest'
INLINE_METHODS void TestCellHandler_Actor::enter3_soundAlarmsTest( void )
{
	// {{{USR
	testSystem.disarm().send();
	timeout.informIn(RTTimespec(0.25, 0));
	// }}}USR
}
// }}}RME

// {{{RME enter ':TOP:testOneAlarmAndSensor'
INLINE_METHODS void TestCellHandler_Actor::enter4_testOneAlarmAndSensor( void )
{
	// {{{USR
	if (testCase < ALARMS_PER_CELL){
		//ALARM TESTS
		String s1 = "Arm test - alarm";
		toDisplay.display_string(s1).send();
		testSystem.arm().send();
	}

	else if (testCase < ALARMS_PER_CELL + SENSORS_PER_CELL){
		//SENSORS TESTS
		String s2 = "Arm test - sensor";
		toDisplay.display_string(s2).send();
		testSystem.arm().send();
	}
	// }}}USR
}
// }}}RME

// {{{RME enter ':TOP:RespondTest'
INLINE_METHODS void TestCellHandler_Actor::enter5_RespondTest( void )
{
	// {{{USR
	testSystem.disarm().send();
	timeout.informIn(RTTimespec(0.25, 0));
	// }}}USR
}
// }}}RME

// {{{RME enter ':TOP:testAlarmAndSensor'
INLINE_METHODS void TestCellHandler_Actor::enter6_testAlarmAndSensor( void )
{
	// {{{USR
	if (testCase < ALARMS_PER_CELL){
		//ALARM TESTS
		String s1 = "Alerm test";
		toDisplay.display_string(s1).send();
		testSystem.arm().send();
		testSystem.alarm().send();
	}
	// }}}USR
}
// }}}RME

// {{{RME enter ':TOP:runSelfTest'
INLINE_METHODS void TestCellHandler_Actor::enter7_runSelfTest( void )
{
	// {{{USR
	testSystem.selfTest().send();
	// }}}USR
}
// }}}RME

// {{{RME enter ':TOP:assertSelfTest'
INLINE_METHODS void TestCellHandler_Actor::enter8_assertSelfTest( void )
{
	// {{{USR
	debugLog.log("Response Test passed");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP1:testDone'
INLINE_METHODS void TestCellHandler_Actor::transition3_testDone( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	testCase = 0;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:testOneAlarmAndSensor:J4D7643150010:nextTest' guard '1'
INLINE_METHODS int TestCellHandler_Actor::guard5_nextTest_event1( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport )
{
	// {{{USR
	const PeripheralIdentifier & armed = *rtdata;

	if (testCase < ALARMS_PER_CELL){
		return armed.peripheralIndex == testCase;
	}else {
		return armed.peripheralIndex == testCase - ALARMS_PER_CELL;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:testOneAlarmAndSensor:J4D7643150010:nextTest'
INLINE_METHODS void TestCellHandler_Actor::transition5_nextTest( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport )
{
	// {{{USR
	testCase++;

	debugLog.log("Arm/Disarm Test passed");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP2:testDone'
INLINE_METHODS void TestCellHandler_Actor::transition7_testDone( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	testCase = 0;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:testAlarmAndSensor:J4D76837A01F1:nextTest'
INLINE_METHODS void TestCellHandler_Actor::transition9_nextTest( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport )
{
	// {{{USR
	testCase++;

	debugLog.log("Alarm Test passed");
	// }}}USR
}
// }}}RME

INLINE_CHAINS void TestCellHandler_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain2_isTestComplete( void )
{
	// transition ':TOP:armDisarmTest:J4D7641AB007B:isTestComplete'
	rtgChainBegin( 2, "isTestComplete" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_CP1( msg->data, (Timing::Base *)msg->sap() ) )
		chain3_testDone();
	else
		chain4_continueArmTest();
}

// {{{RME choicePoint ':TOP:CP1'
INLINE_METHODS int TestCellHandler_Actor::choicePoint1_CP1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	return (testCase == (ALARMS_PER_CELL + SENSORS_PER_CELL));
	// }}}USR
}
// }}}RME

INLINE_CHAINS void TestCellHandler_Actor::chain3_testDone( void )
{
	// transition ':TOP:CP1:testDone'
	rtgChainBegin( 9, "testDone" );
	rtgTransitionBegin();
	transition3_testDone( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain4_continueArmTest( void )
{
	// transition ':TOP:CP1:continueArmTest'
	rtgChainBegin( 9, "continueArmTest" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain6_isTestComplete( void )
{
	// transition ':TOP:soundAlarmsTest:J4D76826B0270:isTestComplete'
	rtgChainBegin( 3, "isTestComplete" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_CP2( msg->data, (Timing::Base *)msg->sap() ) )
		chain7_testDone();
	else
		chain8_continueAlarmTest();
}

// {{{RME choicePoint ':TOP:CP2'
INLINE_METHODS int TestCellHandler_Actor::choicePoint2_CP2( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	return (testCase == ALARMS_PER_CELL);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void TestCellHandler_Actor::chain7_testDone( void )
{
	// transition ':TOP:CP2:testDone'
	rtgChainBegin( 10, "testDone" );
	rtgTransitionBegin();
	transition7_testDone( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain8_continueAlarmTest( void )
{
	// transition ':TOP:CP2:continueAlarmTest'
	rtgChainBegin( 10, "continueAlarmTest" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain5_nextTest( void )
{
	// transition ':TOP:testOneAlarmAndSensor:J4D7643150010:nextTest'
	rtgChainBegin( 4, "nextTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_nextTest( (const PeripheralIdentifier *)msg->data, (TestProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain10_continueRespondTest( void )
{
	// transition ':TOP:RespondTest:J4D76875F00AB:continueRespondTest'
	rtgChainBegin( 5, "continueRespondTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain9_nextTest( void )
{
	// transition ':TOP:testAlarmAndSensor:J4D76837A01F1:nextTest'
	rtgChainBegin( 6, "nextTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_nextTest( (const PeripheralIdentifier *)msg->data, (TestProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void TestCellHandler_Actor::chain11_awaitTestResults( void )
{
	// transition ':TOP:runSelfTest:J4D7687E70389:awaitTestResults'
	rtgChainBegin( 7, "awaitTestResults" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 8 );
}

void TestCellHandler_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:armDisarmTest'
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
			case 4:
				// {{{RME port 'timeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain2_isTestComplete();
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
		case 3:
			// {{{RME state ':TOP:soundAlarmsTest'
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
			case 4:
				// {{{RME port 'timeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain6_isTestComplete();
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
			// {{{RME state ':TOP:testOneAlarmAndSensor'
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
					if( guard5_nextTest_event1( (const PeripheralIdentifier *)msg->data, (TestProtocol::Base *)msg->sap() ) )
					{
						chain5_nextTest();
						return;
					}
					break;
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
			// {{{RME state ':TOP:RespondTest'
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
			case 4:
				// {{{RME port 'timeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain10_continueRespondTest();
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
			// {{{RME state ':TOP:testAlarmAndSensor'
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
				case TestProtocol::Base::rti_breakin:
					chain9_nextTest();
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
			// {{{RME state ':TOP:runSelfTest'
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
				case TestProtocol::Base::rti_selfTestComplete:
					chain11_awaitTestResults();
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
			// {{{RME state ':TOP:assertSelfTest'
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

const RTActor_class * TestCellHandler_Actor::getActorData( void ) const
{
	return &TestCellHandler_Actor::rtg_class;
}

const RTActor_class TestCellHandler_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 8
  , TestCellHandler_Actor::rtg_parent_state
  , &TestCellHandler
  , 2
  , TestCellHandler_Actor::rtg_capsule_roles
  , 5
  , TestCellHandler_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , TestCellHandler_Actor::rtg_TestCellHandler_fields
};

const RTStateId TestCellHandler_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
  , 1
  , 1
  , 1
};

const RTComponentDescriptor TestCellHandler_Actor::rtg_capsule_roles[] =
{
	{
		"display"
	  , &Display
	  , RTOffsetOf( TestCellHandler_Actor, display )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_display
	  , 1
	  , rtg_bindings_display
	}
  , {
		"cellHandlerR1"
	  , &CellHandler
	  , RTOffsetOf( TestCellHandler_Actor, cellHandlerR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_cellHandlerR1
	  , 2
	  , rtg_bindings_cellHandlerR1
	}
};

const RTPortDescriptor TestCellHandler_Actor::rtg_ports[] =
{
	{
		"testSystem"
	  , (const char *)0
	  , &TestProtocol::Base::rt_class
	  , RTOffsetOf( TestCellHandler_Actor, TestCellHandler_Actor::testSystem )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"com"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( TestCellHandler_Actor, TestCellHandler_Actor::com )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toDisplay"
	  , (const char *)0
	  , &DisplayProtocol::Conjugate::rt_class
	  , RTOffsetOf( TestCellHandler_Actor, TestCellHandler_Actor::toDisplay )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"timeout"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( TestCellHandler_Actor, TestCellHandler_Actor::timeout )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"debugLog"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( TestCellHandler_Actor, TestCellHandler_Actor::debugLog )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor TestCellHandler_Actor::rtg_TestCellHandler_fields[] =
{
	// {{{RME classAttribute 'testCase'
	{
		"testCase"
	  , RTOffsetOf( TestCellHandler_Actor, testCase )
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
