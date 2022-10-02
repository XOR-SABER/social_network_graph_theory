#include "headers/social_network.hpp"

bool Social_Network::check(std::string name) const {
	return hash.count(name);
}

bool Social_Network::add_person(std::string name) {	
	if(check(name)) {
		std::cout << "Error: " << name << " in network already.\n";
		return false;
	} else {
		Person temp(name);
		hash.insert({name, network.size()});
		network.push_back(temp);	
		std::cout << name << " added to network.\n";
		return true;
	}	
}

bool Social_Network::add_friend(std::string name, std::string name2) {
	if(!check(name)){
		std::cout << "Error: " << name << " is not in the network.\n";
		return false;
	}
	if(!check(name2)){
		std::cout << "Error: " << name << " is not in the network.\n";
		return false;
	}
	if(isDAG) {
		Person& p1 = network[hash[name]];
		if(p1.is_added(name2)) {
			std::cout << "Error: " << name2 << " is added already.\n";
		}
		p1.add_connection(name2);
	} else {
		Person& p1 = network[hash[name]];
		Person& p2 = network[hash[name2]];
		if(p1.is_added(name2) || p2.is_added(name)) {
			std::cout << "Error: " << name2 << " is added already.\n";
			return false;
		}
		p1.add_connection(name2);
		p2.add_connection(name);
	}
	return true;
}

bool Social_Network::print_friends(std::string name) {
	if(!check(name)){
		std::cout << "Error: " << name << " is not in the network.\n";
		return false;
	}
	const Person& p1 = network[hash[name]];
	for(const std::string s : p1.get_connections()) {
		std::cout << s << std::endl;
	}
	return true;
}

bool Social_Network::print_network(std::string name) {
	//If trying to print the network of someone not in the system:
	if(!check(name)){
		std::cout << "Error: " << name << " is not in the network.\n";
		return false;
	}
	//Graph traversal - store vertexes processed and to be processed
	//Edges will be loaded from all each time based on name
	std::unordered_set<std::string> processed; 
	std::stack<std::string> to_process; 
	//Start with one name in the to_process list...
	to_process.push(name);
	while(!to_process.empty()) {
		std::string curr = to_process.top(); //Get first vertex to process
		const Person &p1 = network[hash[curr]];
		//Step 1. Remove the current vertex from the to_process list
		to_process.pop();
		//Step 2. Get all edges from all for the current vertex
		for(const std::string next : p1.get_connections()) {
			//std::cout << next << std::endl;
			if(!processed.count(next)){
				to_process.push(next);
			}
		}
		//For each outgoing edge...
		//Step 2.1. Check to see if they have been processed
		//Step 2.2. If we haven't seen them before, add to to-do list
		if(!processed.count(curr)) processed.insert(curr);
		//Step 3. Add the vertex to the processed list
	}
	for(const std::string s : processed) {
		std::cout << s << std::endl;
	}
	return true;
}

std::ostream& operator<<(std::ostream &outs, const Social_Network &n) {
	for (const Person &p : n.network) {
		outs << p << std::endl;
	}
	return outs;
}