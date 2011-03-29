// {{{RME classifier 'Logical View::Keypad'

#ifndef Keypad_H
#define Keypad_H

#ifdef PRAGMA
#pragma interface "Keypad.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <KeypadProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR


// }}}USR
// }}}RME

extern const RTActorClass Keypad;

#define SUPER RTActor
class Keypad_Actor : public RTActor
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
	KeypadProtocol::Base toSystem;
	// }}}RME
	// {{{RME port 'testPort'
	KeypadProtocol::Conjugate testPort;
	// }}}RME

public:
	Keypad_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Keypad_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Waiting:J4D6D46FB01E4:ArmPressed'
	INLINE_METHODS void transition2_ArmPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Waiting:J4D6D476B0052:DisarmPressed'
	INLINE_METHODS void transition3_DisarmPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Waiting:J4D6D477F0237:EnabledPressed'
	INLINE_METHODS void transition4_EnabledPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Waiting:J4D6D479B0266:DisabledPressed'
	INLINE_METHODS void transition5_DisabledPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Waiting:J4D6D47E103B1:PasswordEntered'
	INLINE_METHODS void transition6_PasswordEntered( const RTString * rtdata, KeypadProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain6_PasswordEntered( void );
	INLINE_CHAINS void chain2_ArmPressed( void );
	INLINE_CHAINS void chain3_DisarmPressed( void );
	INLINE_CHAINS void chain4_EnabledPressed( void );
	INLINE_CHAINS void chain5_DisabledPressed( void );

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

#endif /* Keypad_H */

// }}}RME
