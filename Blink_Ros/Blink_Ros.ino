#include <ros.h>
#include <std_msgs/Empty.h>

#define LED_PIN 35

ros::NodeHandle nh;

void messageCb( const std_msgs::Empty& toggle_msg) {
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup(){
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); 
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}

