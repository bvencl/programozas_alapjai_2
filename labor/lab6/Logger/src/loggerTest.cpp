#include "logging.h"

using namespace logging;

int main()
{
	Logger &logger = Logger::getInstance();
	logger.setDefaultLogLevel(WARN);

	logger.log(INFO, "Network connection established.");
	logger.log(DEBUG, "Module A can communicate with remote host R.");
	logger.log(WARN, "Network card junction temperature is getting higher and higher.");
	logger.log(ERROR, "Network connection interrupted.");

	Logger &logger1 = Logger::getInstance();
	logger1.printInstance();

	Logger &logger2 = Logger::getInstance();
	logger2.printInstance();

	Logger &logger3 = Logger::getInstance();
	logger3.printInstance();

	return 0;
}