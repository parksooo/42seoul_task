#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Message {
	private:
		int fd;
		std::string origin;
		std::string cmd;
		std::vector<std::string> param;
		std::string trailing;
	public:
		Message(int, std::string);
		void splitMessage();

		int getFd() const;
		std::string getOrigin() const;
		std::string getCmd() const;
		std::vector<std::string> getParams() const;
		std::vector<std::string>::iterator getParametersBegin();
		std::string getTrailing() const;
		void setParameters(std::string);
		void setTrailing(std::string);
};
#endif