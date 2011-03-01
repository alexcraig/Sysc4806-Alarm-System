// {{{RME classifier 'Logical View::SoundAlarm'

#ifndef SoundAlarm_H
#define SoundAlarm_H

#ifdef PRAGMA
#pragma interface "SoundAlarm.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <Alarm.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass SoundAlarm;

#define SUPER Alarm_Actor
class SoundAlarm_Actor : public Alarm_Actor
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

public:
	SoundAlarm_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~SoundAlarm_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain3_DisarmAlarm( void );
	INLINE_CHAINS void chain4_TriggerAlarm( void );
	INLINE_CHAINS void chain7_FailArmed( void );
	INLINE_CHAINS void chain2_ArmAlarm( void );
	INLINE_CHAINS void chain6_FailDisarmed( void );
	INLINE_CHAINS void chain8_RecoverDisarmed( void );
	INLINE_CHAINS void chain9_RecoverArmed( void );
	INLINE_CHAINS void chain5_DisarmTriggeredAlarm( void );
	INLINE_CHAINS void chain10_FailTriggered( void );

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

#endif /* SoundAlarm_H */

// }}}RME
