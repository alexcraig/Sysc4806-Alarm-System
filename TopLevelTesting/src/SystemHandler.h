// {{{RME classifier 'Logical View::SystemHandler'

#ifndef SystemHandler_H
#define SystemHandler_H

#ifdef PRAGMA
#pragma interface "SystemHandler.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <HandlerProtocol.h>

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

protected:
	// {{{RME port 'toCells'
	HandlerProtocol::Base toCells;
	// }}}RME

public:
	SystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~SystemHandler_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* SystemHandler_H */

// }}}RME
