// {{{RME classifier 'Logical View::Display'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Display.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <Display.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"toSystem"
	  , &DisplayProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Display_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Display_Actor( _rts, _ref );
}

const RTActorClass Display =
{
	(const RTActorClass *)0
  , "Display"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Display_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Waiting"
};

#define SUPER RTActor

Display_Actor::Display_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Display_Actor::~Display_Actor( void )
{
}

int Display_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// toSystem
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &toSystem;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Waiting:J4D6D459B02A4:DisplayText'
INLINE_METHODS void Display_Actor::transition2_DisplayText( const RTString * rtdata, DisplayProtocol::Base * rtport )
{
	// {{{USR
	int i, j;

	const RTString & signalString = *rtdata;

	char displayBuffer[256] = "DISPLAY: ";
	i = 9;
	j = 0;

	while(signalString[j] != 0) {
		displayBuffer[i] = signalString[j];
		i++;
		j++;
	}

	String displayString = displayBuffer;
	screenDisplay.log(displayString);

	// }}}USR
}
// }}}RME

INLINE_CHAINS void Display_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Display_Actor::chain2_DisplayText( void )
{
	// transition ':TOP:Waiting:J4D6D459B02A4:DisplayText'
	rtgChainBegin( 2, "DisplayText" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_DisplayText( (const RTString *)msg->data, (DisplayProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Display_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Waiting'
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
				// {{{RME port 'toSystem'
				switch( signalIndex )
				{
				case DisplayProtocol::Base::rti_display_string:
					chain2_DisplayText();
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

const RTActor_class * Display_Actor::getActorData( void ) const
{
	return &Display_Actor::rtg_class;
}

const RTActor_class Display_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Display_Actor::rtg_parent_state
  , &Display
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Display_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId Display_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor Display_Actor::rtg_ports[] =
{
	{
		"toSystem"
	  , (const char *)0
	  , &DisplayProtocol::Base::rt_class
	  , RTOffsetOf( Display_Actor, Display_Actor::toSystem )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"screenDisplay"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Display_Actor, Display_Actor::screenDisplay )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
