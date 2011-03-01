// {{{RME classifier 'Logical View::SystemHandler'

#ifndef SystemHandler_H
#define SystemHandler_H

#ifdef PRAGMA
#pragma interface "SystemHandler.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <CellConfiguration.h>
#include <DisplayProtocol.h>
#include <HandlerProtocol.h>
#include <KeypadProtocol.h>
#include <PhoneProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

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
	// {{{RME classAttribute 'enabled'
	bool enabled;
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
	// {{{RME port 'toTimer'
	Timing::Base toTimer;
	// }}}RME
	// {{{RME port 'toPhone'
	PhoneProtocol::Conjugate toPhone;
	// }}}RME

public:
	SystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~SystemHandler_Actor( void );

protected:
	// {{{RME operation 'setEnabled(bool)'
	void setEnabled( bool enabled );
	// }}}RME

public:
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );
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
