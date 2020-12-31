#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

void messageCb( const std_msgs::Empty& toggle_msg) {
  digitalWrite(LED_BUILDIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILDIN, LOW);
  delay(100);
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup(){
  pinMode(LED_BUILDIN OUTPUT);
  digitalWrite(LED_BUILDIN, HIGH); 
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}

