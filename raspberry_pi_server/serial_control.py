#https://electronicshobbyists.com/control-arduino-using-raspberry-pi-arduino-and-raspberry-pi-serial-communication/

import serial
from flask import Flask, render_template
from time import sleep

app = Flask(__name__)

ser = serial.Serial('/dev/ttyACM0',9600)

templateData = {
	'config1_state': "False",
	'config2_state': "False",
	'config3_state': "False",
	'current_state:': "None",
	'current_config': "None"
}

current_config = 0

@app.route("/")
def index():
	return render_template('index.html', **templateData)

@app.route("/<configuration>")
def action(config):
	# checks which state the thing is
	if config == "1":
		new_config = "1"
		templateData.config1_state = "True"
		templateData.config2_state = "False"
		templateData.config3_state = "False"
	if config == "2":
		new_config = "2"
		templateData.config1_state = "False"
		templateData.config2_state = "True"
		templateData.config3_state = "False"
	if config == "3":
		new_config = "3"
		templateData.config1_state = "False"
		templateData.config2_state = "False"
		templateData.config3_state = "True"

	if new_config != current_config:
		current_config = new_config
		ser.write(current_config)
		templateData.current_config = current_config
		if ser.read() == 'Done':
			actual_state = "Complete"
		else:
			actual_state = "Aborted"
	templateData.current_state = actual_state
	return render_template('index.html', **templateData)

if __name__ == "__main__":
	app.run(host='0.0.0.0', port=80, debug=True)
