#include "communIT.h"

void Commands::readCommand(String command){
    char code = command.charAt(0);
    command.remove(0,1);
    String print_message;
    switch(code){
      case 'm': // Move a motor
        {
          int i, theta;
          int slash = command.indexOf('/');
          i = command.substring(0, slash).toFloat();
          theta = command.substring(slash+1).toFloat();
          Controls::moveMotor(i, theta);
        }
        break;
      case 'l': // Light 
        print_message = "Turning on Lights";
        break;
      default:
        print_message = "Message not understood";
        break;
    };
}
