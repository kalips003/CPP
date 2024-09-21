#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	/////   PRIVATE DATA
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string phone_number;

public:
	/////   PUBLIC STANDARD FUNCIONS
	Contact();
	Contact(int value);
	Contact(const Contact& other);
	~Contact();
	// Contact& operator=(const Contact& other);  // Copy assignment operator

	/////   PUBLIC SETTER
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	void set_darkest_secret(std::string darkest_secret);
	void set_phone_number(std::string phone_number);
	/////   PUBLIC GETTER
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_darkest_secret() const;
	std::string get_phone_number() const;

	// OTHER PUBLIC FUNCTIONS
	void printAttribute() const;

	/////   PUBLIC DATA
	std::string name;

};

#endif