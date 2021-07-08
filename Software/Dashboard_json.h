{
	"description": "Drok-Juntek control dashboard",
	"name": "Soft Power Control",
	"properties": {
		"background_image": "https://i2.wp.com/boingboing.net/wp-content/uploads/2020/06/IMG_20200602_082003_707.jpg",
		"border_radius": "5px",
		"columns": 4,
		"hide_header": false,
		"row_height": 20,
		"show_template": true
	},
	"tabs": [
		{
			"icon": "fas fa-tachometer-alt",
			"name": "JuntekDrok",
			"widgets": [
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Vout",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 6,
						"sizeX": 2,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#0eee02",
						"decimal_places": 2,
						"icon": "",
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#ffffff",
						"showValue": true,
						"size": "75px",
						"textColor": "#1E313E",
						"tickColor": "#000000",
						"unit": "Vo",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Iout",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 15,
						"sizeX": 2,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#fd6306",
						"decimal_places": 3,
						"icon": "",
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#ffffff",
						"showValue": true,
						"size": "75px",
						"textColor": "#1E313E",
						"tickColor": "#000000",
						"unit": "Ao",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"mapping": "Runtime",
							"resource": "status",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 27,
						"sizeX": 1,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424",
						"title": "Cycle:"
					},
					"properties": {
						"color": "#e25ae2",
						"decimal_places": 2,
						"icon": "",
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#ffffff",
						"showValue": true,
						"size": "50px",
						"textColor": "#1E313E",
						"tickColor": "#000000",
						"unit": "",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Vin",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 0,
						"row": 6,
						"sizeX": 2,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#f9e702",
						"decimal_places": 2,
						"icon": "",
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#ffffff",
						"showValue": true,
						"size": "75px",
						"textColor": "#1E313E",
						"tickColor": "#000000",
						"unit": "Vi",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Ahout",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 21,
						"sizeX": 2,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#fd6306",
						"decimal_places": 3,
						"icon": "",
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#ffffff",
						"showValue": true,
						"size": "75px",
						"textColor": "#1E313E",
						"tickColor": "#000000",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Whout",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 0,
						"row": 21,
						"sizeX": 2,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#5a77fe",
						"decimal_places": 2,
						"icon": "",
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#ffffff",
						"showValue": true,
						"size": "75px",
						"textColor": "#1E313E",
						"tickColor": "#000000",
						"unit": "Wh",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 27,
						"sizeX": 2,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#c0c0c0",
						"timezone": ""
					},
					"type": "clock"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Wout",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 0,
						"row": 15,
						"sizeX": 2,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#5a77fe",
						"decimal_places": 2,
						"icon": "",
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#ffffff",
						"showValue": true,
						"size": "75px",
						"textColor": "#1E313E",
						"tickColor": "#000000",
						"unit": "Wo",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"bucket": {
							"backend": "dynamodb",
							"id": "MIN",
							"mapping": [
								"Vout",
								"Vin",
								"Wout",
								"Ioutx10"
							],
							"user": "SoftPower1"
						},
						"source": "bucket"
					},
					"layout": {
						"col": 0,
						"row": 33,
						"sizeX": 4,
						"sizeY": 29
					},
					"panel": {
						"color": "#050505"
					},
					"properties": {
						"axis": true,
						"color": {
							"Iout": "#ff740d",
							"Ioutx10": "#fa7d01",
							"Vin": "#ffdf00",
							"Vout": "#03c90d",
							"Wout": "#3e51ff"
						},
						"fill": false,
						"legend": true,
						"multiple_axes": false,
						"timespan": {
							"magnitude": "hour",
							"mode": "relative",
							"period": "latest",
							"value": 24
						},
						"xaxis": {
							"ticks": 10
						},
						"yaxis": {
							"max": 60,
							"min": -5,
							"ticks": 5
						}
					},
					"type": "chart"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"resource": "scc",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 12,
						"sizeX": 2,
						"sizeY": 3
					},
					"panel": {
						"color": "#f88301"
					},
					"properties": {
						"max": 8000,
						"min": 0,
						"step": 5
					},
					"type": "slider"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"resource": "scv",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 3,
						"sizeX": 2,
						"sizeY": 3
					},
					"panel": {
						"color": "#2fde03"
					},
					"properties": {
						"max": 16000,
						"min": 10000,
						"step": 5
					},
					"type": "slider"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Ohm",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 0,
						"row": 62,
						"sizeX": 2,
						"sizeY": 5
					},
					"panel": {
						"color": "#242424",
						"colors": []
					},
					"properties": {
						"color": "#a85405",
						"decimal_places": 3,
						"icon": "",
						"size": "50px",
						"unit": "Ω",
						"unit_size": "50px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"resource": "scp",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 0,
						"row": 3,
						"sizeX": 2,
						"sizeY": 3
					},
					"panel": {
						"color": "#ffee00",
						"showTs": true
					},
					"properties": {
						"max": 35000,
						"min": 25000,
						"step": 50
					},
					"type": "slider"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"resource": "CtrlMode",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 0,
						"row": 12,
						"sizeX": 1,
						"sizeY": 3
					},
					"panel": {
						"color": "#ababab"
					},
					"properties": {
						"max": 2,
						"min": 0,
						"step": 1
					},
					"type": "slider"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "CtrlModeTXT",
							"resource": "status",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 1,
						"row": 12,
						"sizeX": 1,
						"sizeY": 3
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#f9fafa",
						"decimal_places": 2,
						"icon": "",
						"size": "36px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"resource": "AhMode ",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 3,
						"row": 27,
						"sizeX": 1,
						"sizeY": 6
					},
					"panel": {
						"color": "#242424",
						"title": "Stop,       Run,          Daily"
					},
					"properties": {
						"max": 2,
						"min": 0,
						"step": 1,
						"style": "switch"
					},
					"type": "slider"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"resource": "scv",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 0,
						"sizeX": 2,
						"sizeY": 3
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#fcfcfc",
						"decimal_places": 3,
						"icon": "",
						"size": "40px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"resource": "scp",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 0,
						"row": 0,
						"sizeX": 2,
						"sizeY": 3
					},
					"panel": {
						"color": "#242424"
					},
					"properties": {
						"color": "#f9fafa",
						"decimal_places": 3,
						"icon": "",
						"size": "40px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"type": "text"
				},
				{
					"data": {
						"device": {
							"id": "Steroids6008",
							"interval": 5,
							"mapping": "Charge%",
							"resource": "measure",
							"update": "interval",
							"user": "SoftPower1"
						},
						"source": "device"
					},
					"layout": {
						"col": 2,
						"row": 62,
						"sizeX": 2,
						"sizeY": 5
					},
					"panel": {
						"color": "#242424",
						"colors": []
					},
					"properties": {
						"color": "#24d501",
						"decimal_places": 0,
						"icon": "",
						"size": "50px",
						"unit": "%",
						"unit_size": "50px",
						"weight": "font-thin"
					},
					"type": "text"
				}
			]
		}
	]
}
