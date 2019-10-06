#https://electronicshobbyists.com/control-arduino-using-raspberry-pi-arduino-and-raspberry-pi-serial-communication/

import serial
from flask import Flask, render_template
from time import sleep

app = Flask(__name__)

ser = serial.Serial('/dev/ttyACM1',9600)

@app.route("/")
def index():
    templateData = {

    }
    return render_template('index.html', **templateData)

@app.route("/<state>")
def action(state):
    if state == "1":
        send_state = "1"
    if state == "2":
        send_state = "2"
    if state == "3":
        send_state = "3"
    
    ser.write(send_state)
    if ser.read() == '1':
        actual_state = "complete"
    else:
        actual_state = "aborted"
    

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)
