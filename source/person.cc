#include "headers/person.hpp"

std::string Person::get_username() const {
	return username;
}

void Person::add_connection(std::string other_name) const {
	auto [iter,inserted] = connections.insert(other_name);
	iter = iter; //Disable unused variable warning
	if (inserted) {} //Insert was successful
	else {} //Insert failed
}

const std::set<std::string>& Person::get_connections() const {
	return connections;
}

bool Person::is_added(std::string other_name) const {
	auto iter = connections.find(other_name);
	return (iter != connections.end());
}

bool Person::operator<(const Person &other) const {
		return username < other.username;
}

std::ostream& operator<<(std::ostream &outs, const Person &p) {
    outs << p.get_username();
    return outs;
}