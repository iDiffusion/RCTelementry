#!/bin/bash

# Install GPIO Libraries

echo CHECKING FOR PACKAGES
sudo apt update

echo INSTALLING GPIO LIBRARIES...
sudo apt install python3-gpiozero -y
sudo apt-get install python3-dev python3-pip
sudo python3 -m pip install --upgrade pip setuptools wheel
sudo pip3 install Adafruit_DHT
sudo apt-get install python-dev
sudo apt-get install python-rpi.gpio

echo CHECKING FOR UPDATES
sudo apt dist-upgrade

read -p "Press [Enter] key to start reboot..."
sudo reboot
