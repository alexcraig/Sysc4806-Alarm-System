// {{{RME classifier 'Logical View::UserConfiguration'

#ifndef UserConfiguration_H
#define UserConfiguration_H

#ifdef PRAGMA
#pragma interface "UserConfiguration.h"
#endif

#include <RTSystem/TestSystemHandler.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_UserConfiguration;

class UserConfiguration
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
	// {{{RME classAttribute 'password'
	RTString password;
	// }}}RME
	// {{{RME classAttribute 'phoneNumber'
	RTString phoneNumber;
	// }}}RME

public:
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	UserConfiguration( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~UserConfiguration( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	UserConfiguration( const UserConfiguration & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	UserConfiguration & operator=( const UserConfiguration & rtg_arg );
	// }}}RME
	// {{{RME operation 'getPassword()'
	RTString getPassword( void );
	// }}}RME
	// {{{RME operation 'setPassword(RTString)'
	void setPassword( RTString password );
	// }}}RME
	// {{{RME operation 'getPhoneNumber()'
	RTString getPhoneNumber( void );
	// }}}RME
	// {{{RME operation 'setPhoneNumber(RTString)'
	void setPhoneNumber( RTString phoneNumber );
	// }}}RME
};

struct RTTypedValue_UserConfiguration
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_UserConfiguration( const UserConfiguration & rtg_value )
		: data( &rtg_value ), type( &RTType_UserConfiguration )
	{
	}
	inline RTTypedValue_UserConfiguration( const UserConfiguration & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_UserConfiguration( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* UserConfiguration_H */

// }}}RME
