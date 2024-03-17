#include <log4cpp/Category.hh>
#include <log4cpp/BasicConfigurator.hh>  // Not strictly necessary (commented out)
#include <log4cpp/RemoteSyslogAppender.hh>
#include <log4cpp/SimpleLayout.hh>

int main() {

  // **Optional:** BasicConfigurator::configure();  // Commented out as not needed

  // Create a RemoteSyslogAppender (for remote logging)
  std::string remoteSyslogServer = "192.168.0.116"; // Replace with your server address
  int portNumber = 514;
  log4cpp::RemoteSyslogAppender* syslogAppender =
      new log4cpp::RemoteSyslogAppender("mySyslogAppender", "MyApp", remoteSyslogServer, portNumber);

  // Set the layout for the RemoteSyslogAppender (optional customization)
  syslogAppender->setLayout(new log4cpp::SimpleLayout());

  // Create a logger (using the root category)
  log4cpp::Category& logger = log4cpp::Category::getRoot();

  // **Removed console appender:**

  // Add the RemoteSyslogAppender to the logger
  logger.addAppender(syslogAppender);

  // Log a message
  logger.info("Hello from log4cpp (only remote syslog!)");

  // Clean up
  log4cpp::Category::shutdown();

  return 0;
}

