#include "../Account.hpp"

///////////////////////////////////////////////////////////////////////////////]
//  DEFAULT CONSTRUCTOR
Account( void );
Account( int initial_deposit ) {};

//  DEFAULT DESTRUCTOR
~Account( void );

//  SETTER
void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
//  GETTER
static int	getNbAccounts( void );
static int	getTotalAmount( void );
static int	getNbDeposits( void );
static int	getNbWithdrawals( void );
static void	displayAccountsInfos( void );
///////////////////////////////////////////////////////////////////////////////]
//  OTHER FUNCTIONS
int		checkAmount( void ) const;
void	displayStatus( void ) const;
static void	_displayTimestamp( void );
///////////////////////////////////////////////////////////////////////////////]
