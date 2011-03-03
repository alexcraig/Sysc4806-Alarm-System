// {{{RME classifier 'Logical View::PhoneLine'

#ifndef PhoneLine_H
#define PhoneLine_H

#ifdef PRAGMA
#pragma interface "PhoneLine.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <PhoneProtocol.h>
#include <PhoneTest.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass PhoneLine;

#define SUPER RTActor
class PhoneLine_Actor : public RTActor
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
	PhoneProtocol::Base toSystem;
	// }}}RME
	// {{{RME port 'testPort'
	PhoneTest::Base testPort;
	// }}}RME

public:
	PhoneLine_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~PhoneLine_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Failed:J4D6D4B220080:FailedCall'
	INLINE_METHODS void transition4_FailedCall( const RTString * rtdata, PhoneProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Active:J4D6D4B3B00BD:SuccessfulCall'
	INLINE_METHODS void transition5_SuccessfulCall( const RTString * rtdata, PhoneProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain5_SuccessfulCall( void );
	INLINE_CHAINS void chain2_Fail( void );
	INLINE_CHAINS void chain4_FailedCall( void );
	INLINE_CHAINS void chain3_Recover( void );

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

#endif /* PhoneLine_H */

// }}}RME
