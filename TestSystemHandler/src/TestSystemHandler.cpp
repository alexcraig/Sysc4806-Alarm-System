// {{{RME classifier 'Logical View::TestSystemHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TestSystemHandler.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <TestSystemHandler.h>
extern const RTActorClass SystemHandler;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_TestSystemHandler_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new TestSystemHandler_Actor( _rts, _ref );
}

const RTActorClass TestSystemHandler =
{
	(const RTActorClass *)0
  , "TestSystemHandler"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_TestSystemHandler_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "arm"
  , "initializing"
  , "breakIn"
  , "disarm"
  , "timeout"
  , "enable"
  , "fail"
  , "failTimeout"
  , "CP1"
  , "CP2"
  , "CP1_0"
};

static const RTInterfaceDescriptor rtg_interfaces_systemHandlerR1[] =
{
	{
		"testSystem"
	  , 1
	}
  , {
		"setAlarms"
	  , 1
	}
  , {
		"fromTester"
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
	  , &HandlerProtocol::Base::rt_class
	}
};

#define SUPER RTActor

TestSystemHandler_Actor::TestSystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

TestSystemHandler_Actor::~TestSystemHandler_Actor( void )
{
}

int TestSystemHandler_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
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
			// setAlarms
			if( rtg_repIndex < 1 )
			{
				// setAlarms
				rtg_end.port = &setAlarms;
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

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void TestSystemHandler_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR

	count=0;
	selftestTimeout.informIn(RTTimespec(3, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:timeout:J4D7003EB01D3:disarm'
INLINE_METHODS void TestSystemHandler_Actor::transition2_disarm( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	this->count=0;
	this->breakin=1;
	selftestTimeout.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP1:False'
INLINE_METHODS void TestSystemHandler_Actor::transition4_False( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR

	selftestTimeout.informIn(RTTimespec(10, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP1:True'
INLINE_METHODS void TestSystemHandler_Actor::transition5_True( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	this->count=1;
	selftestTimeout.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:disarm:J4D700FA10224:reset'
INLINE_METHODS void TestSystemHandler_Actor::transition6_reset( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	String pass="1234";
	testSystem.disarm_pressed().send();
	testSystem.password_entered(pass).send();
	selftestTimeout.informIn(RTTimespec(10, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:enable:J4D700892013E:arm'
INLINE_METHODS void TestSystemHandler_Actor::transition7_arm( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Tests armed/enabled/no fails/beat breakin timer
	String password="1234";
	testSystem.arm_pressed().send();
	testSystem.password_entered(password).send();

	selftestTimeout.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:initializing:J4D7008B601EA:enable'
INLINE_METHODS void TestSystemHandler_Actor::transition8_enable( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Tests armed/enabled/no fails/beat breakin timer
	String password="1234";
	testSystem.enabled_pressed().send();
	testSystem.password_entered(password).send();
	selftestTimeout.informIn(RTTimespec(3, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP2:True'
INLINE_METHODS void TestSystemHandler_Actor::transition10_True( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	PeripheralIdentifier ident;
	ident.peripheralType = 1;
	ident.cellIndex = 0;
	ident.peripheralIndex = 0;
	//add trigger
	testSystem.breakin(ident).send();
	selftestTimeout.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP1_0:False'
INLINE_METHODS void TestSystemHandler_Actor::transition12_False( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	if(this->count==2)testSystem.call_failed().send();
	selftestTimeout.informIn(RTTimespec(15, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP1_0:True'
INLINE_METHODS void TestSystemHandler_Actor::transition13_True( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	this->count=1;
	selftestTimeout.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:CP2:False'
INLINE_METHODS void TestSystemHandler_Actor::transition14_False( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	PeripheralIdentifier ident;
	ident.peripheralType = 1;
	ident.cellIndex = 0;
	ident.peripheralIndex = 0;
	//add trigger
	testSystem.failed(ident).send();
	selftestTimeout.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:failTimeout:J4D700D02031A:t1'
INLINE_METHODS void TestSystemHandler_Actor::transition15_t1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	this->count=2;
	selftestTimeout.informIn(RTTimespec(1, 0));
	// }}}USR
}
// }}}RME

INLINE_CHAINS void TestSystemHandler_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain9_failTest( void )
{
	// transition ':TOP:arm:J4D700BCE0318:failTest'
	rtgChainBegin( 2, "failTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_CP2( msg->data, (Timing::Base *)msg->sap() ) )
		chain10_True();
	else
		chain14_False();
}

// {{{RME choicePoint ':TOP:CP2'
INLINE_METHODS int TestSystemHandler_Actor::choicePoint2_CP2( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	return this->breakin==0;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void TestSystemHandler_Actor::chain10_True( void )
{
	// transition ':TOP:CP2:True'
	rtgChainBegin( 11, "True" );
	rtgTransitionBegin();
	transition10_True( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain14_False( void )
{
	// transition ':TOP:CP2:False'
	rtgChainBegin( 11, "False" );
	rtgTransitionBegin();
	transition14_False( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 8 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain8_enable( void )
{
	// transition ':TOP:initializing:J4D7008B601EA:enable'
	rtgChainBegin( 3, "enable" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_enable( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain3_t1( void )
{
	// transition ':TOP:breakIn:J4D70072900FE:t1'
	rtgChainBegin( 4, "t1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_CP1( msg->data, (Timing::Base *)msg->sap() ) )
		chain5_True();
	else
		chain4_False();
}

// {{{RME choicePoint ':TOP:CP1'
INLINE_METHODS int TestSystemHandler_Actor::choicePoint1_CP1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	return this->count==0;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void TestSystemHandler_Actor::chain5_True( void )
{
	// transition ':TOP:CP1:True'
	rtgChainBegin( 10, "True" );
	rtgTransitionBegin();
	transition5_True( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain4_False( void )
{
	// transition ':TOP:CP1:False'
	rtgChainBegin( 10, "False" );
	rtgTransitionBegin();
	transition4_False( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain6_reset( void )
{
	// transition ':TOP:disarm:J4D700FA10224:reset'
	rtgChainBegin( 5, "reset" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_reset( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain2_disarm( void )
{
	// transition ':TOP:timeout:J4D7003EB01D3:disarm'
	rtgChainBegin( 6, "disarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_disarm( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain7_arm( void )
{
	// transition ':TOP:enable:J4D700892013E:arm'
	rtgChainBegin( 7, "arm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_arm( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain11_t1( void )
{
	// transition ':TOP:fail:J4D70072900FE:t1'
	rtgChainBegin( 8, "t1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint3_CP1_0( msg->data, (Timing::Base *)msg->sap() ) )
		chain13_True();
	else
		chain12_False();
}

// {{{RME choicePoint ':TOP:CP1_0'
INLINE_METHODS int TestSystemHandler_Actor::choicePoint3_CP1_0( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	return this->count==0;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void TestSystemHandler_Actor::chain13_True( void )
{
	// transition ':TOP:CP1_0:True'
	rtgChainBegin( 12, "True" );
	rtgTransitionBegin();
	transition13_True( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain12_False( void )
{
	// transition ':TOP:CP1_0:False'
	rtgChainBegin( 12, "False" );
	rtgTransitionBegin();
	transition12_False( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 9 );
}

INLINE_CHAINS void TestSystemHandler_Actor::chain15_t1( void )
{
	// transition ':TOP:failTimeout:J4D700D02031A:t1'
	rtgChainBegin( 9, "t1" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition15_t1( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

void TestSystemHandler_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:arm'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain9_failTest();
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
			// {{{RME state ':TOP:initializing'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain8_enable();
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
			// {{{RME state ':TOP:breakIn'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain3_t1();
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
			// {{{RME state ':TOP:disarm'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain6_reset();
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
			// {{{RME state ':TOP:timeout'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain2_disarm();
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
			// {{{RME state ':TOP:enable'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain7_arm();
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
			// {{{RME state ':TOP:fail'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain11_t1();
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
			// {{{RME state ':TOP:failTimeout'
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
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain15_t1();
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
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * TestSystemHandler_Actor::getActorData( void ) const
{
	return &TestSystemHandler_Actor::rtg_class;
}

const RTActor_class TestSystemHandler_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 9
  , TestSystemHandler_Actor::rtg_parent_state
  , &TestSystemHandler
  , 1
  , TestSystemHandler_Actor::rtg_capsule_roles
  , 3
  , TestSystemHandler_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 2
  , TestSystemHandler_Actor::rtg_TestSystemHandler_fields
};

const RTStateId TestSystemHandler_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
  , 1
  , 1
  , 1
  , 1
};

const RTComponentDescriptor TestSystemHandler_Actor::rtg_capsule_roles[] =
{
	{
		"systemHandlerR1"
	  , &SystemHandler
	  , RTOffsetOf( TestSystemHandler_Actor, systemHandlerR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 3
	  , rtg_interfaces_systemHandlerR1
	  , 2
	  , rtg_bindings_systemHandlerR1
	}
};

const RTPortDescriptor TestSystemHandler_Actor::rtg_ports[] =
{
	{
		"testSystem"
	  , (const char *)0
	  , &TestProtocol::Base::rt_class
	  , RTOffsetOf( TestSystemHandler_Actor, TestSystemHandler_Actor::testSystem )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"setAlarms"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( TestSystemHandler_Actor, TestSystemHandler_Actor::setAlarms )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"selftestTimeout"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( TestSystemHandler_Actor, TestSystemHandler_Actor::selftestTimeout )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor TestSystemHandler_Actor::rtg_TestSystemHandler_fields[] =
{
	// {{{RME classAttribute 'count'
	{
		"count"
	  , RTOffsetOf( TestSystemHandler_Actor, count )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'breakin'
  , {
		"breakin"
	  , RTOffsetOf( TestSystemHandler_Actor, breakin )
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
