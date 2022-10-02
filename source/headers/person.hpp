#ifndef _PERSON_ALEX_HPP
#define _PERSON_ALEX_HPP
#include <set>
#include <string>
#include <iostream>

class Person {
	const std::string username;
	mutable std::set<std::string> connections;
	public:
	Person() = delete; //No default constructor
	Person(std::string new_username) : username(new_username) {}
	std::string get_username() const;
	void add_connection(std::string other_name) const;
	const std::set<std::string>& get_connections() const;
	bool is_added(std::string other_name) const;
	bool operator<(const Person &other) const ;
	friend std::ostream& operator<<(std::ostream &outs, const Person &p);
};


#endif