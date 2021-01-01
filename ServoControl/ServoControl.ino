/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif


#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>


ros::NodeHandle  nh;

Servo servo;
char message[20];

void servo_cb( const std_msgs::UInt16& cmd_msg){
  nh.loginfo("serbo_cb");
  sprintf(message,"%d",cmd_msg.data);
  nh.loginfo(message);
  servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));  //toggle led  
}


ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  
  servo.attach(13); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}
