# -*- coding: utf-8 -*-
"""
Created on Tue Jun  4 13:18:14 2019

@author: hp
"""

import RPi.GPIO as GPIO
import time

sensor = 4

GPIO.setmode(GPIO.BCM)
GPIO.setup(sensor, GPIO.IN, GPIO.PUD_DOWN)

previous_state = False
current_state = False

while True:
    time.sleep(0.1)
    previous_state = current_state
    current_state = GPIO.input(sensor)
    if current_state != previous_state:
        new_state = "HIGH" if current_state else "LOW"
        print("GPIO pin %s is %s" % (sensor, new_state))
        import smtplib
 
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login("from_email_address", "from_email_password")
 
        msg = "INTRUDER!"
        server.sendmail("from_email_address", "to_email_address", msg)
        server.quit()

