const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        /* ... (your existing styles) ... */
        html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      
      .slidecontainer {
        width: 100%;
      }

      .slider {
        -webkit-appearance: none;
        width: 50%;
        height: 15px;
        border-radius: 5px;
        background: #d3d3d3;
        outline: none;
        opacity: 0.7;
        -webkit-transition: .2s;
        transition: opacity .2s;
      }

      .slider:hover {
        opacity: 1;
      }

      .slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: #4CAF50;
        cursor: pointer;
      }

      .slider::-moz-range-thumb {
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: #4CAF50;
        cursor: pointer;
      }
        /* Styles for the dialog box */
        #calendarLinkDialog {
            display: none;
            position: fixed;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            border: 1px solid #ccc;
            padding: 20px;
            background-color: #fff;
        }
    </style>
</head>
<body>
    <h1>Mr Madhav</h1>
    <br><br>

    <div class="slidecontainer">
        <input type="range" min="0" max="180" value="50" class="slider" id="myRange">
        <p>Value : <span id="demo"></span></p>
    </div>

    <!-- Dialog box for entering calendar link -->
    <div id="calendarLinkDialog">
        <label for="calendarLink">Enter Google Calendar public calendar link:</label>
        <input type="text" id="calendarLink">
        <button onclick="submitCalendarLink()">Submit</button>
    </div>

    <button onclick="openCalendarLinkDialog()">Enter Calendar Link</button>

    <script>

function openCalendarLinkDialog() {
            document.getElementById("calendarLinkDialog").style.display = "block";
        }

        function submitCalendarLink() {
            var calendarLink = document.getElementById("calendarLink").value;

            // Validate calendar link (replace with your validation logic)
            if (!isValidCalendarLink(calendarLink)) {
                alert("Invalid calendar link!");
                return;
            }

            // Fetch event data using Google Calendar API
            fetchEvents(calendarLink)
                .then(events => {
                    // Iterate through events and check for "medicine" event
                    for (const event of events) {
                        if (event.name === "medicine") {
                            // Scroll slider smoothly to a specific position
                            scrollSliderToPosition(180); // Replace 180 with your desired position
                        }
                    }
                })
                .catch(error => {
                    console.error("Error fetching events:", error);
                    alert("Failed to fetch events.");
                });

            document.getElementById("calendarLinkDialog").style.display = "none";
        }
        function sendData(pos) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            console.log(this.responseText);
          }
        };
        xhttp.open("GET", "setPOS?servoPOS="+pos, true);
        xhttp.send();
      } 
      var slider = document.getElementById("myRange");
      var output = document.getElementById("demo");
      output.innerHTML = slider.value;

      slider.oninput = function() {
        output.innerHTML = this.value;
        sendData(output.innerHTML);
      }
        function openCalendarLinkDialog() {
            document.getElementById("calendarLinkDialog").style.display = "block";
        }

        function submitCalendarLink() {
            var calendarLink = document.getElementById("calendarLink").value;
            console.log(calendarLink);
            document.getElementById("calendarLinkDialog").style.display = "none";
        }
    </script>
</body>
</html>
)=====";
