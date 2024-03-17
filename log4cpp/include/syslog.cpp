#include <log4cpp/Category.hh>
#include <log4cpp/BasicConfigurator.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RemoteSyslogAppender.hh>
#include <log4cpp/SimpleLayout.hh>

int main() {

  // Initialize log4cpp using BasicConfigurator (console)
  log4cpp::BasicConfigurator::configure();

  // Create a console appender (optional customization)
  log4cpp::OstreamAppender* consoleAppender = new log4cpp::OstreamAppender("console", &std::cout);
  consoleAppender->setLayout(new log4cpp::SimpleLayout());

  // Create a logger (using the root category)
  log4cpp::Category& logger = log4cpp::Category::getRoot();

  // Add the console appender (optional, since BasicConfigurator sets a default console appender)
  logger.addAppender(consoleAppender);

  // Create a RemoteSyslogAppender (for remote logging)
  std::string remoteSyslogServer = "192.168.0.116"; // Replace with your server address
  int portNumber = 514;
  log4cpp::RemoteSyslogAppender* syslogAppender =
      new log4cpp::RemoteSyslogAppender("mySyslogAppender", "MyApp", remoteSyslogServer, portNumber);

  // Set the layout for the RemoteSyslogAppender (optional customization)
  syslogAppender->setLayout(new log4cpp::BasicLayout());

  // Add the RemoteSyslogAppender to the logger
  logger.addAppender(syslogAppender);

  // Log a message
  logger.info("Hello from log4cpp (console and remote syslog!)");

  // Clean up
  log4cpp::Category::shutdown(); // Not strictly necessary for BasicConfigurator

  return 0;
}

