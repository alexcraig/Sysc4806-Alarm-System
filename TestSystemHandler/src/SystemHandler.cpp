// {{{RME classifier 'Logical View::SystemHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SystemHandler.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <SystemHandler.h>
extern const RTActorClass CellHandler;
extern const RTActorClass Display;
extern const RTActorClass Keypad;
extern const RTActorClass PhoneLine;
extern const RTActorClass SoundAlarm;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"testSystem"
	  , &TestProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"setAlarms"
	  , &HandlerProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_SystemHandler_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new SystemHandler_Actor( _rts, _ref );
}

const RTActorClass SystemHandler =
{
	(const RTActorClass *)0
  , "SystemHandler"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_SystemHandler_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Initializing"
  , "Initialized"
  , "Disabled"
  , "Enabled"
  , "Disarmed"
  , "Armed"
  , "ArmPasswordEntry"
  , "DisarmPasswordEntry"
  , "EnablePasswordEntry"
  , "DisablePasswordEntry"
  , "EnablePasswordValidate"
  , "DisablePasswordValidate"
  , "ArmPasswordValidate"
  , "DisarmPasswordValidate"
};

static const RTInterfaceDescriptor rtg_interfaces_displayR1[] =
{
	{
		"toSystem"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_displayR1[] =
{
	{
		0
	  , &DisplayProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_keypadR1[] =
{
	{
		"toSystem"
	  , 1
	}
  , {
		"testPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_keypadR1[] =
{
	{
		0
	  , &KeypadProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_soundAlarmR1[] =
{
	{
		"fromCell"
	  , 1
	}
  , {
		"testPort"
	  , 0
	}
  , {
		"testSystem"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_soundAlarmR1[] =
{
	{
		0
	  , &HandlerProtocol::Base::rt_class
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
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_cellHandlerR1[] =
{
	{
		0
	  , &HandlerProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_phoneLineR1[] =
{
	{
		"toSystem"
	  , 1
	}
  , {
		"testPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_phoneLineR1[] =
{
	{
		0
	  , &PhoneProtocol::Conjugate::rt_class
	}
};

const RTTypeModifier rtg_tm_SystemHandler_Actor_cellResponded =
{
	RTNumberConstant
  , (NUMBER_OF_CELLS)
  , 0
};

#define SUPER RTActor

SystemHandler_Actor::SystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

SystemHandler_Actor::~SystemHandler_Actor( void )
{
}

int SystemHandler_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// testSystem
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &testSystem;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// setAlarms
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &setAlarms;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int SystemHandler_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// displayR1
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
		// keypadR1
		switch( rtg_portId )
		{
		case 0:
			// toSystem
			if( rtg_repIndex < 1 )
			{
				// toKeypad
				rtg_end.port = &toKeypad;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 3:
		// soundAlarmR1
		switch( rtg_portId )
		{
		case 0:
			// fromCell
			if( rtg_repIndex < 1 )
			{
				// toInternalAlarm
				rtg_end.port = &toInternalAlarm;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 4:
		// cellHandlerR1
		switch( rtg_portId )
		{
		case 0:
			// fromSystem
			if( rtg_repIndex < 3 )
			{
				// toCells
				rtg_end.port = &toCells;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 5:
		// phoneLineR1
		switch( rtg_portId )
		{
		case 0:
			// toSystem
			if( rtg_repIndex < 1 )
			{
				// toPhone
				rtg_end.port = &toPhone;
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
INLINE_METHODS void SystemHandler_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	int i;
	for(i = 0; i < NUMBER_OF_CELLS; i++) {
		this->cellResponded[i] = false;
	}

	this->breakInTimerRunning = false;
	selftestTimeout.informIn(RTTimespec(1, 0));

	// Start the periodic self-test timer
	selftestPeriodic.informEvery( RTTimespec( SYSTEM_SELFTEST_INTERVAL, 0 ) );
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initializing:J4D6E6A3D017C:TimeoutElapsed'
INLINE_METHODS void SystemHandler_Actor::transition2_TimeoutElapsed( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	int i;

	// Initialize cell indexes
	for(i = 0; i < NUMBER_OF_CELLS; i++) {
		toCells.set_cell_index(i).sendAt(i);
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Disabled:J4D6E70570280:EnablePressed'
INLINE_METHODS void SystemHandler_Actor::transition4_EnablePressed( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Please enter your password";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:EnablePasswordValidate:False'
INLINE_METHODS void SystemHandler_Actor::transition6_False( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Invalid password";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:J4D6E736B011E:DisablePressed'
INLINE_METHODS void SystemHandler_Actor::transition7_DisablePressed( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Please enter your password";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:DisablePasswordValidate:True'
INLINE_METHODS void SystemHandler_Actor::transition9_True( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "System disabled.";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:DisablePasswordValidate:False'
INLINE_METHODS void SystemHandler_Actor::transition10_False( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Invalid password.";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:J4D6E78CD004D:StartSelfTest'
INLINE_METHODS void SystemHandler_Actor::transition11_StartSelfTest( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	int i;
	for(i = 0; i < NUMBER_OF_CELLS; i++) {
		this->cellResponded[i] = false;
	}

	toCells.selftest().send();
	selftestTimeout.informIn(RTTimespec(SYSTEM_SELFTEST_TIMEOUT, 0));

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:J4D6E7A440149:GotCellHearbeat'
INLINE_METHODS void SystemHandler_Actor::transition12_GotCellHearbeat( const void * rtdata, HandlerProtocol::Base * rtport )
{
	// {{{USR
	int cellIndex = msg->sapIndex0();
	this->cellResponded[cellIndex] = true; 
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:EnablePasswordValidate:True'
INLINE_METHODS void SystemHandler_Actor::transition13_True( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "System enabled and disarmed.";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:J4D6E8F35018B:BreakInTimeout'
INLINE_METHODS void SystemHandler_Actor::transition14_BreakInTimeout( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	this->breakInTimerRunning = false;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:J4D6E908F020A:SelfTestComplete'
INLINE_METHODS void SystemHandler_Actor::transition15_SelfTestComplete( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	int i;

	for(i = 0; i < NUMBER_OF_CELLS; i++) {
		if(this->cellResponded[i] == false) {
			char displayBuffer[512];

			sprintf(displayBuffer, "Cell failed to respond to self test. Cell index: %d.");

			String displayString = displayBuffer;
			toDisplay.display_string(displayString).send();
			toLog.log(displayString);
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Disarmed:J4D6E70570280:ArmPressed'
INLINE_METHODS void SystemHandler_Actor::transition16_ArmPressed( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Please enter your password";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E736B011E:DisarmPressed'
INLINE_METHODS void SystemHandler_Actor::transition17_DisarmPressed( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Please enter your password";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:ArmPasswordValidate:True'
INLINE_METHODS void SystemHandler_Actor::transition19_True( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "System enabled and armed.";
	toDisplay.display_string(displayMessage).send();

	toCells.arm().send();
	toInternalAlarm.arm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:ArmPasswordValidate:False'
INLINE_METHODS void SystemHandler_Actor::transition20_False( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Invalid password";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:DisarmPasswordValidate:True'
INLINE_METHODS void SystemHandler_Actor::transition22_True( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "System enabled and disarmed.";
	toDisplay.display_string(displayMessage).send();

	this->breakInTimerRunning = false;
	toCells.disarm().send();
	toInternalAlarm.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:DisarmPasswordValidate:False'
INLINE_METHODS void SystemHandler_Actor::transition23_False( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	String displayMessage = "Invalid password.";
	toDisplay.display_string(displayMessage).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Disarmed:J4D6E7F6F029A:DisarmedFailure'
INLINE_METHODS void SystemHandler_Actor::transition25_DisarmedFailure( const PeripheralIdentifier * rtdata, RTProtocol * rtport )
{
	// {{{USR
	const PeripheralIdentifier & failInfo = *rtdata;

	char displayBuffer[512];

	if(failInfo.peripheralType == TYPE_ALARM) {
		sprintf(displayBuffer, "Alarm failure. Cell index: %d. Alarm index: %d.",
			failInfo.cellIndex, failInfo.peripheralIndex);
	} else if(failInfo.peripheralType == TYPE_SENSOR) {
		sprintf(displayBuffer, "Sensor failure. Cell index: %d. Sensor index: %d.",
			failInfo.cellIndex, failInfo.peripheralIndex);
	}

	String displayString = displayBuffer;

	toDisplay.display_string(displayString).send();
	toLog.log(displayString);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E88EA022D:ArmedFailure'
INLINE_METHODS void SystemHandler_Actor::transition26_ArmedFailure( const PeripheralIdentifier * rtdata, RTProtocol * rtport )
{
	// {{{USR
	const PeripheralIdentifier & failInfo = *rtdata;

	char displayBuffer[512];

	if(failInfo.peripheralType == TYPE_ALARM) {
		sprintf(displayBuffer, "Alarm failure. Cell index: %d. Alarm index: %d.",
			failInfo.cellIndex, failInfo.peripheralIndex);
	} else if(failInfo.peripheralType == TYPE_SENSOR) {
		sprintf(displayBuffer, "Sensor failure. Cell index: %d. Sensor index: %d.",
			failInfo.cellIndex, failInfo.peripheralIndex);
	}

	String displayString = displayBuffer;

	toDisplay.display_string(displayString).send();
	toLog.log(displayString);

	if(!this->breakInTimerRunning) {
		sprintf(displayBuffer, "Triggering break-in timer.");
		String displayString = displayBuffer;
		toDisplay.display_string(displayString).send();
		toLog.log(displayString);

		this->breakInTimerRunning = true;
		breakInTimeout.informIn(RTTimespec(SYSTEM_BREAKIN_TIMEOUT,0));
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E8D7B033E:ArmedBreakin'
INLINE_METHODS void SystemHandler_Actor::transition27_ArmedBreakin( const PeripheralIdentifier * rtdata, RTProtocol * rtport )
{
	// {{{USR
	const PeripheralIdentifier & failInfo = *rtdata;

	char displayBuffer[512];

	if(failInfo.peripheralType == TYPE_SENSOR) {
		sprintf(displayBuffer, "BREAK IN DETECTED. Cell index: %d. Sensor index: %d.",
			failInfo.cellIndex, failInfo.peripheralIndex);

		String displayString = displayBuffer;

		toDisplay.display_string(displayString).send();
		toLog.log(displayString);

		if(!this->breakInTimerRunning) {
			sprintf(displayBuffer, "Triggering break-in timer.");
			String displayString = displayBuffer;
			toDisplay.display_string(displayString).send();
			toLog.log(displayString);

			this->breakInTimerRunning = true;
			breakInTimeout.informIn(RTTimespec(SYSTEM_BREAKIN_TIMEOUT,0));
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E8E4202D2:BreakInTimerExpired'
INLINE_METHODS void SystemHandler_Actor::transition28_BreakInTimerExpired( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	char displayBuffer[512];
	this->breakInTimerRunning = false;

	sprintf(displayBuffer, "BREAK IN TIMER EXPIRED, TRIGGERING ALL ALARMS AND PLACING PHONE CALL");

	String displayString = displayBuffer;

	toDisplay.display_string(displayString).send();
	toLog.log(displayString);

	toInternalAlarm.trigger().send();
	toCells.trigger().send();
	toPhone.place_call(config.getPhoneNumber()).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E91C001CE:SuccesfullPhoneCall'
INLINE_METHODS void SystemHandler_Actor::transition29_SuccesfullPhoneCall( const void * rtdata, PhoneProtocol::Conjugate * rtport )
{
	// {{{USR
	char displayBuffer[512];

	sprintf(displayBuffer, "Phone call placed successfully.");

	String displayString = displayBuffer;
	toDisplay.display_string(displayString).send();
	toLog.log(displayString);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initialized:Enabled:Armed:J4D6E920B022C:FailedPhoneCall'
INLINE_METHODS void SystemHandler_Actor::transition30_FailedPhoneCall( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	char displayBuffer[512];

	sprintf(displayBuffer, "Phone call failed.");

	String displayString = displayBuffer;
	toDisplay.display_string(displayString).send();
	toLog.log(displayString);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SystemHandler_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void SystemHandler_Actor::chain2_TimeoutElapsed( void )
{
	// transition ':TOP:Initializing:J4D6E6A3D017C:TimeoutElapsed'
	rtgChainBegin( 2, "TimeoutElapsed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_TimeoutElapsed( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
	// transition ':TOP:Initialized:J4D6E6A3D0181:TimeoutElapsed'
	rtgChainBegin( 3, "TimeoutElapsed" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void SystemHandler_Actor::chain4_EnablePressed( void )
{
	// transition ':TOP:Initialized:Disabled:J4D6E70570280:EnablePressed'
	rtgChainBegin( 4, "EnablePressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_EnablePressed( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 10 );
}

INLINE_CHAINS void SystemHandler_Actor::chain12_GotCellHearbeat( void )
{
	// transition ':TOP:Initialized:Enabled:J4D6E7A440149:GotCellHearbeat'
	rtgChainBegin( 5, "GotCellHearbeat" );
	exitToChainState( 5, rtg_parent_state );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition12_GotCellHearbeat( msg->data, (HandlerProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	processHistory();
}

INLINE_CHAINS void SystemHandler_Actor::chain7_DisablePressed( void )
{
	// transition ':TOP:Initialized:Enabled:J4D6E736B011E:DisablePressed'
	rtgChainBegin( 5, "DisablePressed" );
	exitToChainState( 5, rtg_parent_state );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_DisablePressed( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 11 );
}

INLINE_CHAINS void SystemHandler_Actor::chain15_SelfTestComplete( void )
{
	// transition ':TOP:Initialized:Enabled:J4D6E908F020A:SelfTestComplete'
	rtgChainBegin( 5, "SelfTestComplete" );
	exitToChainState( 5, rtg_parent_state );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition15_SelfTestComplete( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	processHistory();
}

INLINE_CHAINS void SystemHandler_Actor::chain11_StartSelfTest( void )
{
	// transition ':TOP:Initialized:Enabled:J4D6E78CD004D:StartSelfTest'
	rtgChainBegin( 5, "StartSelfTest" );
	exitToChainState( 5, rtg_parent_state );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition11_StartSelfTest( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	processHistory();
}

INLINE_CHAINS void SystemHandler_Actor::chain14_BreakInTimeout( void )
{
	// transition ':TOP:Initialized:Enabled:J4D6E8F35018B:BreakInTimeout'
	rtgChainBegin( 5, "BreakInTimeout" );
	exitToChainState( 5, rtg_parent_state );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition14_BreakInTimeout( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	processHistory();
}

INLINE_CHAINS void SystemHandler_Actor::chain25_DisarmedFailure( void )
{
	// transition ':TOP:Initialized:Enabled:Disarmed:J4D6E7F6F029A:DisarmedFailure'
	rtgChainBegin( 6, "DisarmedFailure" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition25_DisarmedFailure( (const PeripheralIdentifier *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void SystemHandler_Actor::chain16_ArmPressed( void )
{
	// transition ':TOP:Initialized:Enabled:Disarmed:J4D6E70570280:ArmPressed'
	rtgChainBegin( 6, "ArmPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition16_ArmPressed( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 8 );
}

INLINE_CHAINS void SystemHandler_Actor::chain27_ArmedBreakin( void )
{
	// transition ':TOP:Initialized:Enabled:Armed:J4D6E8D7B033E:ArmedBreakin'
	rtgChainBegin( 7, "ArmedBreakin" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition27_ArmedBreakin( (const PeripheralIdentifier *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void SystemHandler_Actor::chain26_ArmedFailure( void )
{
	// transition ':TOP:Initialized:Enabled:Armed:J4D6E88EA022D:ArmedFailure'
	rtgChainBegin( 7, "ArmedFailure" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition26_ArmedFailure( (const PeripheralIdentifier *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void SystemHandler_Actor::chain17_DisarmPressed( void )
{
	// transition ':TOP:Initialized:Enabled:Armed:J4D6E736B011E:DisarmPressed'
	rtgChainBegin( 7, "DisarmPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition17_DisarmPressed( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 9 );
}

INLINE_CHAINS void SystemHandler_Actor::chain29_SuccesfullPhoneCall( void )
{
	// transition ':TOP:Initialized:Enabled:Armed:J4D6E91C001CE:SuccesfullPhoneCall'
	rtgChainBegin( 7, "SuccesfullPhoneCall" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition29_SuccesfullPhoneCall( msg->data, (PhoneProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void SystemHandler_Actor::chain30_FailedPhoneCall( void )
{
	// transition ':TOP:Initialized:Enabled:Armed:J4D6E920B022C:FailedPhoneCall'
	rtgChainBegin( 7, "FailedPhoneCall" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition30_FailedPhoneCall( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void SystemHandler_Actor::chain28_BreakInTimerExpired( void )
{
	// transition ':TOP:Initialized:Enabled:Armed:J4D6E8E4202D2:BreakInTimerExpired'
	rtgChainBegin( 7, "BreakInTimerExpired" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition28_BreakInTimerExpired( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void SystemHandler_Actor::chain18_PasswordEntered( void )
{
	// transition ':TOP:Initialized:Enabled:ArmPasswordEntry:J4D6E70EE037B:PasswordEntered'
	rtgChainBegin( 8, "PasswordEntered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint3_ArmPasswordValidate( (const RTString *)msg->data, msg->sap() ) )
		chain19_True();
	else
		chain20_False();
}

// {{{RME choicePoint ':TOP:Initialized:Enabled:ArmPasswordValidate'
INLINE_METHODS int SystemHandler_Actor::choicePoint3_ArmPasswordValidate( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	const String & password = *rtdata;

	return(password == config.getPassword());
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SystemHandler_Actor::chain19_True( void )
{
	// transition ':TOP:Initialized:Enabled:ArmPasswordValidate:True'
	rtgChainBegin( 14, "True" );
	rtgTransitionBegin();
	transition19_True( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void SystemHandler_Actor::chain20_False( void )
{
	// transition ':TOP:Initialized:Enabled:ArmPasswordValidate:False'
	rtgChainBegin( 14, "False" );
	rtgTransitionBegin();
	transition20_False( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void SystemHandler_Actor::chain21_PasswordEntered( void )
{
	// transition ':TOP:Initialized:Enabled:DisarmPasswordEntry:J4D6E739202E3:PasswordEntered'
	rtgChainBegin( 9, "PasswordEntered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint4_DisarmPasswordValidate( (const RTString *)msg->data, msg->sap() ) )
		chain22_True();
	else
		chain23_False();
}

// {{{RME choicePoint ':TOP:Initialized:Enabled:DisarmPasswordValidate'
INLINE_METHODS int SystemHandler_Actor::choicePoint4_DisarmPasswordValidate( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	const String & password = *rtdata;

	return(password == config.getPassword());
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SystemHandler_Actor::chain22_True( void )
{
	// transition ':TOP:Initialized:Enabled:DisarmPasswordValidate:True'
	rtgChainBegin( 15, "True" );
	rtgTransitionBegin();
	transition22_True( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void SystemHandler_Actor::chain23_False( void )
{
	// transition ':TOP:Initialized:Enabled:DisarmPasswordValidate:False'
	rtgChainBegin( 15, "False" );
	rtgTransitionBegin();
	transition23_False( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 7 );
}

INLINE_CHAINS void SystemHandler_Actor::chain5_PasswordEntered( void )
{
	// transition ':TOP:Initialized:EnablePasswordEntry:J4D6E70EE037B:PasswordEntered'
	rtgChainBegin( 10, "PasswordEntered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint1_EnablePasswordValidate( (const RTString *)msg->data, msg->sap() ) )
		chain13_True();
	else
		chain6_False();
}

// {{{RME choicePoint ':TOP:Initialized:EnablePasswordValidate'
INLINE_METHODS int SystemHandler_Actor::choicePoint1_EnablePasswordValidate( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	const String & password = *rtdata;

	return(password == config.getPassword());
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SystemHandler_Actor::chain13_True( void )
{
	// transition ':TOP:Initialized:EnablePasswordValidate:True'
	rtgChainBegin( 12, "True" );
	rtgTransitionBegin();
	transition13_True( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	// transition ':TOP:Initialized:Enabled:J4D6E7CE402F3:True'
	rtgChainBegin( 5, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void SystemHandler_Actor::chain6_False( void )
{
	// transition ':TOP:Initialized:EnablePasswordValidate:False'
	rtgChainBegin( 12, "False" );
	rtgTransitionBegin();
	transition6_False( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void SystemHandler_Actor::chain8_PasswordEntered( void )
{
	// transition ':TOP:Initialized:DisablePasswordEntry:J4D6E739202E3:PasswordEntered'
	rtgChainBegin( 11, "PasswordEntered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	if( choicePoint2_DisablePasswordValidate( (const RTString *)msg->data, msg->sap() ) )
		chain9_True();
	else
		chain10_False();
}

// {{{RME choicePoint ':TOP:Initialized:DisablePasswordValidate'
INLINE_METHODS int SystemHandler_Actor::choicePoint2_DisablePasswordValidate( const RTString * rtdata, RTProtocol * rtport )
{
	// {{{USR
	const String & password = *rtdata;

	return(password == config.getPassword());
	// }}}USR
}
// }}}RME

INLINE_CHAINS void SystemHandler_Actor::chain9_True( void )
{
	// transition ':TOP:Initialized:DisablePasswordValidate:True'
	rtgChainBegin( 13, "True" );
	rtgTransitionBegin();
	transition9_True( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void SystemHandler_Actor::chain10_False( void )
{
	// transition ':TOP:Initialized:DisablePasswordValidate:False'
	rtgChainBegin( 13, "False" );
	rtgTransitionBegin();
	transition10_False( (const RTString *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
	processHistory();
}

void SystemHandler_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Initializing'
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
			case 6:
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain2_TimeoutElapsed();
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
			// {{{RME state ':TOP:Initialized'
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
		case 4:
			// {{{RME state ':TOP:Initialized:Disabled'
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
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_enabled_pressed:
					chain4_EnablePressed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_enabled_pressed:
					chain4_EnablePressed();
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
			// {{{RME state ':TOP:Initialized:Enabled'
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
				// {{{RME port 'toCells'
				switch( signalIndex )
				{
				case HandlerProtocol::Base::rti_heartbeat:
					chain12_GotCellHearbeat();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_disabled_pressed:
					chain7_DisablePressed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 6:
				// {{{RME port 'selftestTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain15_SelfTestComplete();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 8:
				// {{{RME port 'selftestPeriodic'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain11_StartSelfTest();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 9:
				// {{{RME port 'breakInTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain14_BreakInTimeout();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_disabled_pressed:
					chain7_DisablePressed();
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
			// {{{RME state ':TOP:Initialized:Enabled:Disarmed'
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
				// {{{RME port 'toCells'
				switch( signalIndex )
				{
				case HandlerProtocol::Base::rti_failed:
					chain25_DisarmedFailure();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_arm_pressed:
					chain16_ArmPressed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_arm_pressed:
					chain16_ArmPressed();
					return;
				case TestProtocol::Conjugate::rti_failed:
					chain25_DisarmedFailure();
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
			// {{{RME state ':TOP:Initialized:Enabled:Armed'
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
				// {{{RME port 'toCells'
				switch( signalIndex )
				{
				case HandlerProtocol::Base::rti_breakin:
					chain27_ArmedBreakin();
					return;
				case HandlerProtocol::Base::rti_failed:
					chain26_ArmedFailure();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_disarm_pressed:
					chain17_DisarmPressed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 7:
				// {{{RME port 'toPhone'
				switch( signalIndex )
				{
				case PhoneProtocol::Conjugate::rti_call_placed:
					chain29_SuccesfullPhoneCall();
					return;
				case PhoneProtocol::Conjugate::rti_call_failed:
					chain30_FailedPhoneCall();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 9:
				// {{{RME port 'breakInTimeout'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain28_BreakInTimerExpired();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_disarm_pressed:
					chain17_DisarmPressed();
					return;
				case TestProtocol::Conjugate::rti_failed:
					chain26_ArmedFailure();
					return;
				case TestProtocol::Conjugate::rti_breakin:
					chain27_ArmedBreakin();
					return;
				case TestProtocol::Conjugate::rti_call_failed:
					chain30_FailedPhoneCall();
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
			// {{{RME state ':TOP:Initialized:Enabled:ArmPasswordEntry'
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
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_password_entered:
					chain18_PasswordEntered();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_password_entered:
					chain18_PasswordEntered();
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
			// {{{RME state ':TOP:Initialized:Enabled:DisarmPasswordEntry'
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
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_password_entered:
					chain21_PasswordEntered();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_password_entered:
					chain21_PasswordEntered();
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
		case 10:
			// {{{RME state ':TOP:Initialized:EnablePasswordEntry'
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
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_password_entered:
					chain5_PasswordEntered();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_password_entered:
					chain5_PasswordEntered();
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
		case 11:
			// {{{RME state ':TOP:Initialized:DisablePasswordEntry'
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
			case 2:
				// {{{RME port 'toKeypad'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_password_entered:
					chain8_PasswordEntered();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 10:
				// {{{RME port 'testSystem'
				switch( signalIndex )
				{
				case TestProtocol::Conjugate::rti_password_entered:
					chain8_PasswordEntered();
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

const RTActor_class * SystemHandler_Actor::getActorData( void ) const
{
	return &SystemHandler_Actor::rtg_class;
}

const RTActor_class SystemHandler_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 11
  , SystemHandler_Actor::rtg_parent_state
  , &SystemHandler
  , 5
  , SystemHandler_Actor::rtg_capsule_roles
  , 11
  , SystemHandler_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 3
  , SystemHandler_Actor::rtg_SystemHandler_fields
};

const RTStateId SystemHandler_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 3
  , 3
  , 5
  , 5
  , 5
  , 5
  , 3
  , 3
};

const RTComponentDescriptor SystemHandler_Actor::rtg_capsule_roles[] =
{
	{
		"displayR1"
	  , &Display
	  , RTOffsetOf( SystemHandler_Actor, displayR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_displayR1
	  , 1
	  , rtg_bindings_displayR1
	}
  , {
		"keypadR1"
	  , &Keypad
	  , RTOffsetOf( SystemHandler_Actor, keypadR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_keypadR1
	  , 1
	  , rtg_bindings_keypadR1
	}
  , {
		"soundAlarmR1"
	  , &SoundAlarm
	  , RTOffsetOf( SystemHandler_Actor, soundAlarmR1 )
	  , 3
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 3
	  , rtg_interfaces_soundAlarmR1
	  , 1
	  , rtg_bindings_soundAlarmR1
	}
  , {
		"cellHandlerR1"
	  , &CellHandler
	  , RTOffsetOf( SystemHandler_Actor, cellHandlerR1 )
	  , 4
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 3 // cardinality
	  , 2
	  , rtg_interfaces_cellHandlerR1
	  , 1
	  , rtg_bindings_cellHandlerR1
	}
  , {
		"phoneLineR1"
	  , &PhoneLine
	  , RTOffsetOf( SystemHandler_Actor, phoneLineR1 )
	  , 5
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_phoneLineR1
	  , 1
	  , rtg_bindings_phoneLineR1
	}
};

const RTPortDescriptor SystemHandler_Actor::rtg_ports[] =
{
	{
		"toCells"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toCells )
	  , 3 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toKeypad"
	  , (const char *)0
	  , &KeypadProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toKeypad )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toDisplay"
	  , (const char *)0
	  , &DisplayProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toDisplay )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toInternalAlarm"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toInternalAlarm )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toLog"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toLog )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"selftestTimeout"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::selftestTimeout )
	  , 1 // cardinality
	  , 6
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toPhone"
	  , (const char *)0
	  , &PhoneProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toPhone )
	  , 1 // cardinality
	  , 7
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"selftestPeriodic"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::selftestPeriodic )
	  , 1 // cardinality
	  , 8
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"breakInTimeout"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::breakInTimeout )
	  , 1 // cardinality
	  , 9
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"testSystem"
	  , (const char *)0
	  , &TestProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::testSystem )
	  , 1 // cardinality
	  , 10
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"setAlarms"
	  , (const char *)0
	  , &HandlerProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::setAlarms )
	  , 1 // cardinality
	  , 11
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor SystemHandler_Actor::rtg_SystemHandler_fields[] =
{
	// {{{RME classAttribute 'config'
	{
		"config"
	  , RTOffsetOf( SystemHandler_Actor, config )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_UserConfiguration
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'cellResponded'
  , {
		"cellResponded"
	  , RTOffsetOf( SystemHandler_Actor, cellResponded[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_SystemHandler_Actor_cellResponded
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'breakInTimerRunning'
  , {
		"breakInTimerRunning"
	  , RTOffsetOf( SystemHandler_Actor, breakInTimerRunning )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
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
