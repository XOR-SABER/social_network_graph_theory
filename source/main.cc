#include <iostream>
#include <cstdlib>



#include "headers/social_network.hpp"

using namespace std;


void die() {
	cout << "BAD INPUT!\n";
	exit(1);
}

int main() {
	int choice = read<int>("Do you wish to implement:\n1. Facebook\n2. Twitter\n");
	if (choice < 1 || choice > 2) die();
	bool isTwitter = (choice == 2);
	Social_Network Network(isTwitter);

	std::string format = "Enter name of person who will add a " +
	std::string((!Network.check_type() ? "friend:\n" : "follower:\n"));
	std::string format1 = "Enter name of the person to print the " + 
	std::string((!Network.check_type() ? "friends of:\n" : "followers of:\n"));
	std::string format2 = "Enter name of the person to print there network of " + 
	std::string((!Network.check_type() ? "friends:\n" : "followers:\n"));

	while (true) {
		cout << "Do you wish to:" << endl;
		cout << "1. Add person\n";
		cout << "2. Add " << (!Network.check_type() ? "friend:" : "follower:") << endl;
		cout << "3. Print " << (!Network.check_type() ? "friends:" : "followers:") << " of one person\n";
		cout << "4. Print entire social network of one person\n";
		cout << "5. Print all people in the social network\n";
		cout << "6. Quit\n";
		choice = read<int>(": ");
		std::string name, name2;
		switch (choice)
		{
		case 1:
			name = read<std::string>("Enter name of the person to add:\n");
			Network.add_person(name);
			break;
		case 2:
			name = read<std::string>(format);
			name2 = read<std::string>("Enter name of the person to add: \n");
			Network.add_friend(name,name2);
			break;
		case 3:
			name = read<std::string>(format1);
			Network.print_friends(name);
			break;
		case 4:
			name = read<std::string>(format2);
			Network.print_network(name);
			break;
		case 5:
			cout << Network;
			break;
		case 6:
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}
