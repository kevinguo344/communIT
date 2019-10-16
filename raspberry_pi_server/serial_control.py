# https://electronicshobbyists.com/control-arduino-using-raspberry-pi-arduino-and-raspberry-pi-serial-communication/
# https://towardsdatascience.com/python-webserver-with-flask-and-raspberry-pi-398423cc6f5d

import serial
from flask import Flask, render_template
from time import sleep

app = Flask(__name__)

ser = serial.Serial('/dev/ttyACM0',9600)

current_config = 0
templateData = {
		'title': "communIT Control Panel",
		'config1_state': "False",
		'config2_state': "False",
		'config3_state': "False",
		'current_state': "None",
		'current_config': "None"
	}
@app.route("/")
def index():
	return render_template('index.html', **templateData)

@app.route("/<config>")
def action(config):
	# checks which state the thing is
	if config == "1":
		new_config = "1"
		config1_state = "True"
		config2_state = "False"
		config3_state = "False"
		title = "Config 1 Chosen"
	if config == "2":
		new_config = "2"
		config1_state = "False"
		config2_state = "True"
		config3_state = "False"
		title = "Config 2 Chosen"
	if config == "3":
		new_config = "3"
		config1_state = "False"
		config2_state = "False"
		config3_state = "True"
		title = "Config 3 Chosen"
	global current_config
	current_state = 0
	if(current_config != new_config):
		ser.write(str.encode(new_config))
		current_config = new_config
		
		if ser.read() == 'D':
			actual_state = "Complete"
		else:
			actual_state = "Aborted"
		current_state = actual_state
	templateData = {
		'title': title,
		'config1_state': config1_state,
		'config2_state': config2_state,
		'config3_state': config3_state,
		'current_state': current_state,
		'current_config': current_config
	}
	return render_template('index.html', **templateData)

if __name__ == "__main__":
	app.run(host='0.0.0.0', port=80, debug=True)
