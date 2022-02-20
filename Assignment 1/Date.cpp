#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{
  void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
  }

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }

  void Date::errCode(int errorCode) {
	  this->m_readErrorCode = errorCode;
  }
  
  void Date::set(int year, int mon, int day, int hour, int min) {
	  this->m_year = year;
	  this->m_mon = mon;
	  this->m_day = day;
	  this->m_hour = hour;
	  this->m_min = min;
	  this->m_readErrorCode = NO_ERROR;
  }

  Date::Date() {
	  this->m_dateOnly = false;
	  set();
  }
  
  Date::Date(int year, int month, int day) {
	  this->m_dateOnly = true;
	  this->m_year = year;
	  this->m_mon = month;
	  this->m_day = day;
	  this->m_hour = 0;
	  this->m_min = 0;
	  this->m_readErrorCode = NO_ERROR;

  }

  Date::Date(int year, int month, int day, int hour, int min) {
	  this->m_dateOnly = false;
	  this->m_year = year;
	  this->m_mon = month;
	  this->m_day = day;
	  this->m_hour = hour;
	  this->m_min = min;
	  this->m_readErrorCode = NO_ERROR;
  }

  bool Date::operator==(const Date& D)const {
	  if (this->value() == D.value()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }
  bool Date::operator!=(const Date& D)const {
	  if (this->value() != D.value()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }
  bool Date::operator<(const Date& D)const {
	  if (this->value() < D.value()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }
  bool Date::operator>(const Date& D)const {
	  if (this->value() > D.value()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }
  bool Date::operator<=(const Date& D)const {
	  if (this->value() <= D.value()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }
  bool Date::operator>=(const Date& D)const {
	  if (this->value() >= D.value()) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }

  int Date::errCode() const {
	  return m_readErrorCode;
  }

  bool Date::bad() const {
	  if (m_readErrorCode != 0) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }
  bool Date::dateOnly() const {
	  return m_dateOnly;
  }
  void Date::dateOnly(bool value) {
	  this->m_dateOnly = value;
	  if (value == true){
		  m_hour = 0;
		  m_min = 0;
	  }
  }
  std::istream& Date::read(std::istream& is) {
	  if (this->m_dateOnly) {
		  is >> this->m_year;
		  if (is.get() != '/') {
			  this->m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  else if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
			  this->m_readErrorCode = YEAR_ERROR;
		  }
		  is >> this->m_mon;
		  if (is.get() != '/') {
			  this->m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  else if (m_mon < 1 || m_mon > 12) {
			  this->m_readErrorCode = MON_ERROR;
		  }
		  is >> this->m_readErrorCode;
	  }
	  else {
		  is >> this->m_year;
		  if (is.get() != '/') {
			  this->m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  else if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
			  this->m_readErrorCode = YEAR_ERROR;
		  }
		  is >> this->m_mon;
		  if (is.get() != '/') {
			  this->m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  else if (m_mon < 1 || m_mon > 12) {
			  this->m_readErrorCode = MON_ERROR;
		  }
		  is >> this->m_readErrorCode;
	  }

	  return is;
  }

  std::ostream& Date::write(std::ostream& ostr)const {
	  if (this->m_dateOnly) {
		  ostr << this->m_year << "/" << this->m_mon << "/" << this->m_day;
	  }
	  else {
		  ostr << this->m_year << "/" << this->m_mon << "/" << this->m_day << ", " << this->m_hour << ":" << this->m_min;
	  }
	  return ostr;
  }

  std::istream& operator >> (std::istream& is, Date& D) {
	  return D.read(is);
  }
  std::ostream& operator<<(std::ostream& ostr, const Date& D) {
	  return D.write(ostr);
  }


}
