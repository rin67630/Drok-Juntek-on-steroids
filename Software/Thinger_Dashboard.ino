{
  "description": "Juntek",
  "name": "Juntek",
  "properties": {
    "border_radius": "10px",
    "columns": 6,
    "row_height": 40
  },
  "tabs": [
    {
      "icon": "fas fa-tachometer-alt",
      "name": "Juntek",
      "widgets": [
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "interval": 5,
              "mapping": "Wout",
              "resource": "measure",
              "update": "interval",
              "user": "User"
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
            "color": "#7094ff"
          },
          "properties": {
            "majorTicks": 10,
            "max": 80,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "W"
          },
          "type": "tachometer"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "mapping": "Vout",
              "resource": "measure",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 2,
            "row": 0,
            "sizeX": 2,
            "sizeY": 7
          },
          "panel": {
            "color": "#fff894"
          },
          "properties": {
            "majorTicks": 2,
            "max": 38,
            "min": 2,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "Vout"
          },
          "type": "tachometer"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "mapping": "Iout",
              "resource": "measure",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 4,
            "row": 0,
            "sizeX": 2,
            "sizeY": 7
          },
          "panel": {
            "color": "#fdb38b"
          },
          "properties": {
            "majorTicks": 1,
            "max": 6,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "A"
          },
          "type": "tachometer"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "interval": 60,
              "mapping": [
                "Vout",
                "Vin",
                "Wout",
                "Iout"
              ],
              "resource": "measure",
              "update": "interval",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 0,
            "row": 15,
            "sizeX": 6,
            "sizeY": 19
          },
          "panel": {
            "color": "#000000"
          },
          "properties": {
            "axis": true,
            "color": {
              "Iout": "#d38312",
              "Vin": "#12e251",
              "Vout": "#ebf740",
              "Wout": "#497ddf"
            },
            "fill": false,
            "legend": true,
            "multiple_axes": true,
            "timespan": {
              "magnitude": "hour",
              "value": 6
            },
            "yaxis": {
              "max": "",
              "min": "",
              "ticks": ""
            }
          },
          "type": "chart"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "resource": "scc",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 4,
            "row": 7,
            "sizeX": 2,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff"
          },
          "properties": {
            "max": 6000,
            "min": 0,
            "step": 10
          },
          "type": "slider"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "resource": "scv",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 2,
            "row": 7,
            "sizeX": 2,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff"
          },
          "properties": {
            "max": 35000,
            "min": 3000,
            "step": 10
          },
          "type": "slider"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "resource": "scv",
              "update": "events",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 2,
            "row": 9,
            "sizeX": 2,
            "sizeY": 3
          },
          "panel": {
            "color": "#ffffff",
            "title": "Set point"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit_size": "20px",
            "weight": "font-thin",
            "unit": "Vout"
          },
          "type": "text"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "resource": "scc",
              "update": "events",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 4,
            "row": 9,
            "sizeX": 2,
            "sizeY": 3
          },
          "panel": {
            "color": "#ffffff",
            "title": "Set point"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit_size": "20px",
            "weight": "font-thin",
            "unit": "Aout"
          },
          "type": "text"
        },
        {
          "data": {
            "device_property": {
              "device": "JuntekNT",
              "mapping": "Wh/hour",
              "property": "persistances",
              "user": "User"
            },
            "source": "device_property"
          },
          "layout": {
            "col": 0,
            "row": 12,
            "sizeX": 2,
            "sizeY": 3
          },
          "panel": {
            "color": "#ffffff"
          },
          "properties": {
            "color": "#0865fd",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "Wh",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "type": "text"
        },
        {
          "data": {
            "device_property": {
              "device": "JuntekNT",
              "mapping": "Ah/hour",
              "property": "persistances",
              "user": "User"
            },
            "source": "device_property"
          },
          "layout": {
            "col": 4,
            "row": 12,
            "sizeX": 2,
            "sizeY": 3
          },
          "panel": {
            "color": "#ffffff"
          },
          "properties": {
            "color": "#ff9500",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "Ah",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "type": "text"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "mapping": "Vin",
              "resource": "measure",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 0,
            "row": 0,
            "sizeX": 2,
            "sizeY": 6
          },
          "panel": {
            "color": "#b0fe96"
          },
          "properties": {
            "majorTicks": 2,
            "max": 38,
            "min": 2,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "Vin"
          },
          "type": "tachometer"
        },
        {
          "data": {
            "device": {
              "id": "JuntekNT",
              "interval": 60,
              "mapping": "Runtime",
              "resource": "status",
              "update": "events",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 3,
            "row": 12,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#ffffff",
            "title": "Cycle"
          },
          "properties": {
            "color": "#c504c8",
            "decimal_places": 2,
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
              "id": "JuntekNT",
              "resource": "button_z",
              "user": "User"
            },
            "source": "device"
          },
          "layout": {
            "col": 2,
            "row": 12,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#ffffff",
            "title": "Restart Cycle"
          },
          "properties": {
            "icon": "fa-power-off",
            "iconColor": "#ffffff",
            "iconSize": 16,
            "offColor": "#be00cc",
            "onColor": "#00bb00",
            "style": "push_button"
          },
          "type": "boolean"
        }
      ]
    }
  ]
}
