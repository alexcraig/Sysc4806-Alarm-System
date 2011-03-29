// {{{RME classifier 'Logical View::UserConfiguration'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UserConfiguration.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <UserConfiguration.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_UserConfiguration_init( const RTObject_class * type, UserConfiguration * target )
{
	(void)new( target ) UserConfiguration;
}

static void rtg_UserConfiguration_copy( const RTObject_class * type, UserConfiguration * target, const UserConfiguration * source )
{
	(void)new( target ) UserConfiguration( *source );
}

static void rtg_UserConfiguration_destroy( const RTObject_class * type, UserConfiguration * target )
{
	target->~UserConfiguration();
}

const RTObject_class RTType_UserConfiguration =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "UserConfiguration"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( UserConfiguration )
  , (RTInitFunction)rtg_UserConfiguration_init
  , (RTCopyFunction)rtg_UserConfiguration_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_UserConfiguration_destroy
  , 0
  , (const RTFieldDescriptor *)0
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
UserConfiguration::UserConfiguration( void )
	: password( "1234" )
	, phoneNumber( "911" )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
UserConfiguration::~UserConfiguration( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
UserConfiguration::UserConfiguration( const UserConfiguration & rtg_arg )
	: password( rtg_arg.password )
	, phoneNumber( rtg_arg.phoneNumber )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
UserConfiguration & UserConfiguration::operator=( const UserConfiguration & rtg_arg )
{
	if( this != &rtg_arg )
	{
		password = rtg_arg.password;
		phoneNumber = rtg_arg.phoneNumber;
	}
	return *this;
}
// }}}RME

// {{{RME operation 'getPassword()'
RTString UserConfiguration::getPassword( void )
{
	// {{{USR
	return this->password;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPassword(RTString)'
void UserConfiguration::setPassword( RTString password )
{
	// {{{USR
	this->password = password;
	// }}}USR
}
// }}}RME

// {{{RME operation 'getPhoneNumber()'
RTString UserConfiguration::getPhoneNumber( void )
{
	// {{{USR
	return this->phoneNumber;
	// }}}USR
}
// }}}RME

// {{{RME operation 'setPhoneNumber(RTString)'
void UserConfiguration::setPhoneNumber( RTString phoneNumber )
{
	// {{{USR
	this->phoneNumber = phoneNumber;
	// }}}USR
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_UserConfiguration_installer( RTType_UserConfiguration );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
