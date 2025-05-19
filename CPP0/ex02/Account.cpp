#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////]

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

///////////////////////////////////////////////////////////////////////////////]
int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
    return _totalAmount;
}
int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void ) {
    
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::_nbAccounts
    << ";total:" << Account::_totalAmount
    << ";deposits:" << Account::_totalNbDeposits
    << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
// [19920104_091532] index:0;amount:42;created
Account::Account( int initial_deposit ) 
: _accountIndex(Account::_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";amount:" << _amount << ";created" << std::endl;
}
// [19920104_091532] index:0;amount:47;closed
Account::~Account( void ) {
    Account::_nbAccounts--;

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";amount:" << _amount << ";closed" << std::endl;
}
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit ) {

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";p_amount:" << _amount << ";deposit:" << deposit;

    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;

    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal ) {

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";p_amount:" << _amount << ";withdrawal:";

    if (withdrawal <= _amount) {
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    } else {
        std::cout << "refused" << std::endl;
        return false;
    }
}
int		Account::checkAmount( void ) const {
    std::cout << "this? " << _accountIndex << std::endl;
    return _amount;
}
// [19920104_091532] index:7;amount:16596;deposits:1;withdrawals:0
void	Account::displayStatus( void ) const {

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
// [19920104_091532]
void	Account::_displayTimestamp( void ) {

    std::time_t ora = std::time(NULL);
    std::tm     *now = std::localtime(&ora);

    std::cout << "[" << now->tm_year + 1900 << std::setfill('0')
        << std::setw(2) << now->tm_mon + 1
        << std::setw(2) << now->tm_mday << "_"
        << std::setw(2) << now->tm_hour
        << std::setw(2) << now->tm_min
        << std::setw(2) << now->tm_sec
        << "]";
}
Account::Account( void ) 
: _accountIndex(Account::_nbAccounts++), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
}
