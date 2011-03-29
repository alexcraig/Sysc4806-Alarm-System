// {{{RME classifier 'Logical View::Display'

#ifndef Display_H
#define Display_H

#ifdef PRAGMA
#pragma interface "Display.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <DisplayProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Display;

#define SUPER RTActor
class Display_Actor : public RTActor
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
	// {{{RME port 'toSystem'
	DisplayProtocol::Base toSystem;
	// }}}RME
	// {{{RME port 'screenDisplay'
	Log::Base screenDisplay;
	// }}}RME

public:
	Display_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Display_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Waiting:J4D6D459B02A4:DisplayText'
	INLINE_METHODS void transition2_DisplayText( const RTString * rtdata, DisplayProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_DisplayText( void );

public:
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

#endif /* Display_H */

// }}}RME
