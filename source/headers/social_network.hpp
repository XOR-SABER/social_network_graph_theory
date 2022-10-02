#ifndef _SOCNET_ALEX_HPP
#define _SOCNET_ALEX_HPP
#include "person.hpp"
#include "read.h"
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>

class Social_Network {
    private:
        std::vector<Person> network;
        std::unordered_map<std::string, int> hash;
        bool isDAG; // is a directed graph 
        bool check(std::string name) const;
    public:
        Social_Network() = delete;
        Social_Network(bool DAG) : isDAG(DAG) {}
        bool check_type() {return isDAG;}
        bool add_friend(std::string name, std::string name2);
        bool add_person(std::string name);
        bool print_friends(std::string name);
        bool print_network(std::string name); 
        friend std::ostream& operator<<(std::ostream &outs, const Social_Network &n);
};


#endif