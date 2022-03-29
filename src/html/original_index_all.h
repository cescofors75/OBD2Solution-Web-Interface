


const char MAIN_page[] PROGMEM = R"=====(





<!DOCTYPE html>
<html>



<head>
<style type="text/css">
tbody tr:nth-child(odd) {
  background-color: #f0f4fc;
  font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
    font-size: 16px;
}

tbody tr:nth-child(even) {
  background-color: #e3e5e8;
  font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
    font-size: 16px;
}
.content{

    max-width: 100%;
    margin: auto;
  }
  .card{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 160px;
       background: #bd0416;
       padding: 10px;
       box-sizing: border-box;
       color: #FFF;
       margin:10px;
       box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
  }
  .card2{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 160px;
       background: #000000;
       padding: 10px;
       box-sizing: border-box;
       color: #FFF;
       margin:10px;
       box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
  }
  .card3{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 160px;
       background: white;
       color: navy;
       padding: 10px;
       box-sizing: border-box;
       font-size: 16px;
       margin:10px;
       box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
  }
  .info{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 160px;
       background: #FFF;
       padding: 10px;
       box-sizing: border-box;
       color: #000;
       margin:10px;
       box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
  }
  .navbar {
    font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
    font-size: 40px;
    overflow: hidden;
    background-color: #333;
    position: fixed; /* Set the navbar to fixed position */
    top: 0; /* Position the navbar at the top of the page */
    width: 100%; /* Full width */
    max-width: 100%;
    margin: auto;
  }
  
  /* Links inside the navbar */
  .navbar a {
    float: right;
    display: block;
    color: #f2f2f2;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
  }
  
  /* Change background on mouse-over */
  .navbar a:hover {
    background: #ddd;
    color: black;
  }

  .button {
    float: right;
  background-color: #bd0416; /* red */
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 20px;
}
.button2 {
    float: left;
  background-color: #4CAF50; /* Green */
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 20px;
}
</style>

 <link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/themes/base/jquery-ui.css" type="text/css" media="all" />
 <script src="https://code.highcharts.com/highcharts.js"></script>
 <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.6.2/jquery.min.js" type="text/javascript"></script>
 <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/jquery-ui.min.js" type="text/javascript"></script>
 <script>
 $(function() {
 $('#tabs').tabs();
 });
 </script>

<script type="text/javascript">

    function getMake() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("MakeValue").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "readMake", true);
       xhttp.send();
      }
     
    function getPIDS(){
      
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("PIDSValue").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "readPIDS", true);
       xhttp.send();
      }
     

      function getidCar(){
      
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("idCar").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "idCar", true);
       xhttp.send();
      }

   function getInfo(){
      
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("InfoValue").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "readInfo", true);
       xhttp.send();
      }

      function PostClearDTC(){

              var xhttp = new XMLHttpRequest();
              
              

               
            xhttp.open("GET", "/ClearDTC", true);
               xhttp.send();

      }


   </script>
   <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
   <script type="text/javascript">
      google.charts.load('current', {'packages':['gauge']});
      google.charts.setOnLoadCallback(drawChart);


      function drawChart() {

        var data = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Speed', 80],
          ['RPM', 55],
          ['Temp1', 68],
          ['Temp2', 40]
        ]);
       
        var data2 = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Fuel', 20],
          ['Voltage', 25],
          ['Temp3', 28],
          ['Temp4', 20]
        ]);

        var options = {
          width: 800, height: 240,
          redFrom: 90, redTo: 100,
          yellowFrom:75, yellowTo: 90,
          minorTicks: 5
        };
       
        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));
        var chart2 = new google.visualization.Gauge(document.getElementById('chart_div2'));

      
       
       
       setInterval(function() {var xhttp = new XMLHttpRequest();
       xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);

          data.setValue(0, 1, y);
          chart.draw(data, options);
        }
  };
  xhttp.open("GET", "/readSPEED", true);
  xhttp.send();
     
   }, 1);


      setInterval(function() {var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);

          data.setValue(1, 1, y);
          chart.draw(data, options);
        }
  };
  xhttp.open("GET", "/readRPM", true);
  xhttp.send();
     
   }, 1);


        setInterval(function() {
          data.setValue(2, 1, 60 + Math.round(20 * Math.random()));
          chart.draw(data, options);
        }, 260);
         setInterval(function() {
          data.setValue(3, 1, 60 + Math.round(20 * Math.random()));
          chart.draw(data, options);
        }, 260);
     
     
      setInterval(function() {
          data2.setValue(0, 1, 40 + Math.round(60 * Math.random()));
          chart2.draw(data2, options);
        }, 3000);

        setInterval(function() {
          data2.setValue(1, 1, 50 + Math.round(60 * Math.random()));
          chart2.draw(data2, options);
        }, 500);

         setInterval(function() {
          data2.setValue(2, 1, 50 + Math.round(60 * Math.random()));
          chart2.draw(data2, options);
        }, 500);

         setInterval(function() {
          data2.setValue(3, 1, 80 + Math.round(20 * Math.random()));
          chart2.draw(data2, options);
        }, 2600);
     

     
      }
     
    </script>


   

  </head>





<body>
<div class="content">

<div class="navbar">
  <a href="#home">Home</a>
  <a href="#news">News</a>
  <a href="#contact">Contact</a>
</div>
<div><br><br><br></div>
<div class="info"> 
<div class="card">
  <h2><span id="MakeValue">Conectant</span></h2>
</div>
</div>


<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getMake();
}, 200); //2000mSeconds update rate


</script>

<div class="info"> 

<div id="chart_div" style="width: 100%; height: 240px;"></div>
   
<div id="chart_div2" style="width: 100%; height: 240px;"></div>
</div>

<div id="tabs">
<ul>
 <li><a href="#tabs-1">ENGINE</a></li>
 <li><a href="#tabs-2">AIR / FUEL </a></li>
 <li><a href="#tabs-3">TEMP</a></li>
 <li><a href="#tabs-4">SPEED / TIME</a></li>
 <li><a href="#tabs-5">DRIVER</a></li>
 <li><a href="#tabs-6">ELECTRIC SYSTEMS</a></li>
 </ul>
<div id="tabs-1">
<h2><span id="PIDSValue">Initcializant</span></h2>

 </div>
 <div id="tabs-2">
 <p>PID_COOLANT_TEMP – Engine coolant temperature (°C)</p>
 <p>PID_ENGINE_OIL_TEMP – Engine oil temperature (°C)</p>
 </div>
 <div id="tabs-3">
 <p>PID_INTAKE_TEMP – Intake temperature (°C)</p>
 <p>PID_INTAKE_PRESSURE – Intake manifold absolute pressure (kPa)</p>
 <p>PID_MAF_FLOW – MAF flow pressure (grams/s)</p>
 <p>PID_BAROMETRIC – Barometric pressure (kPa)</p>
 </div>
 <div id="tabs-4">
 <p>PID_SPEED – Vehicle speed (km/h)</p>
 <p>PID_RUNTIME – Engine running time (second)</p>
 <p>PID_DISTANCE – Vehicle running distance (km)</p>
 </div>
 <div id="tabs-5">
 <p>PID_THROTTLE – Throttle position (%)</p>
 <p>PID_AMBIENT_TEMP – Ambient temperature (°C)</p>
 </div>
 <div id="tabs-6">
 <p>PID_CONTROL_MODULE_VOLTAGE</p>
 <p>PID_HYBRID_BATTERY_PERCENTAGE</p>
 </div>
</div>
<script> $('#linkToTab3').click(function() { 
 // To get the index of the currently selected Tab ;
// var index = $('#tabs').data('tabs').options.selected; ;
// alert('selected tab = ' + index); ;
// To set the index of the tab to be selected ;
$('#tabs').tabs('select', 2); }); </script>




<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getPIDS();
}, 200); //2000mSeconds update rate


</script>

<div class="info">
<div class="card2">
 <h2><span id="InfoValue">Buscant Erros. </span></h2>
  
<a href="ClearDTC"><button class="button">CLEAR DTC </button></a>

 </div>
 </div>

 <div class="info">
<div class="card3">
 <h2><span id="idCar">Buscant idCar. </span></h2>
  
 </div>
 </div>
<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getInfo();
}, 200); //2000mSeconds update rate

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getidCar();
}, 200); //2000mSeconds update rate




</script>








</div>
</body>
</html>
)=====";